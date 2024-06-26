#include"grep.h"

char option_check(char**argv)
{
	char option;
	if(argv[1][0] !='-') 
	{
       option = default_operation; //default opertation
	   return option;
	}
	if(!strcmp(argv[1] ,"-i"))
	{
		option = 'i';
		return option;
	}
			
	if(!strcmp(argv[1] ,"-c"))
	{
		option = 'c';
		return option;
	}
	if(!strcmp(argv[1] ,"-v"))
	{
		option = 'v';
		return option;
	}
	if(!strcmp(argv[1] ,"-w"))
	{
		option = 'w';
		return option;
	}
       if(!strcmp(argv[1] ,"-n"))
	{
		option = 'n';
		return option;
	}
       if(!strcmp(argv[1] ,"-x"))
	{
		option = 'x';
		return option;
	}
    return invalid_option;

}
int file_check(char * filename)
{
	FILE *fp;
	fp = fopen(filename , "r");

	if(fp == NULL)
	{   
		return FAIL;
	}
	else
	{   
		fclose(fp);
		return SUCCESS;
	}
}
