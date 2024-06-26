
/*

Name:shino k shaji
Date:19-06-2024
Description: grep  command with options i,w,n,x,v,c is implemented

*/
  

#include"grep.h"


int main(int argc , char **argv )
{  char option;
   char filename[100];
   char pattern[100];
  if( argc <=2) //command with less 2 arhument
  {
    printf("usage: grep[option] ... PATTERNS [FILE] ..."); return FAIL;
  }
  else if(argc == 4)//command with 3 argument
  { 
     option = option_check(argv); 
	 if(option == invalid_option)
	 {
		 printf("grep:invalid option --'%c'",argv[1][1]);
		 return FAIL;
	 }
      if(file_check(argv[3])==FAIL)
	  {
		  printf("grep:%s: No such file or directory",argv[3]);
		  return FAIL;
	  }
	  else
	  {
            strcpy(filename , argv[3]);
			strcpy(pattern , argv[2]);
			grep_operate(option ,pattern,filename);
	  }
  }
  else if(argc == 3) //coomand line with 2 argument
  {
	  option = default_operation;
	  if(file_check(argv[2])==FAIL)
	  {
		  printf("grep:%s: No such file or directory",argv[3]);
		  return FAIL;
	  }
	  else
      {   
            strcpy(filename , argv[2]);
			strcpy(pattern , argv[1]);
			grep_operate(option ,pattern,filename);
	  }
  }
return 0;
}

