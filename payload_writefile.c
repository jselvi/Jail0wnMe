#include <stdio.h>

int main(int argc, char **argv)
{
	/*
	if(argc == 0)
	{
        	// make me root and remove sandbox
        	syscall(0);
	}
	*/

	FILE * pFile;
	pFile = fopen ("/tmp/pwned.txt","w");
	if (pFile!=NULL)
	{
		fputs ("OWNED!",pFile);
		fclose (pFile);
	}

	return 0;
}
