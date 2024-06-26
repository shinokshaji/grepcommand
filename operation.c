#include "grep.h"
#include<ctype.h>

void string_lower(char *str1 ,char *str2)
{
	for(;*str2;++str1,++str2)
	{
		*str1 = tolower(*str2);
	}
	*str1=*str2;
}

int is_word_delimiter(char c)
{
    return isspace(c) || ispunct(c) || c == '\0';
}

char *strstr_word(const char *line, const char *pattern)
{

int pattern_len = strlen(pattern);
const char *line_a = line;
while (( line_a = strstr( line_a,pattern)) != NULL) 
{
        
        if ((line_a == line || is_word_delimiter(*(line_a - 1))) &&
            (is_word_delimiter(*(line_a + pattern_len)))) {
            return (char *)line_a;
        }
        line_a += pattern_len;
}
return NULL;
}
void grep_operate(char operator , char *pattern , char *filename)
{ 
  switch(operator)
  {
	  case 'c': operate_c(pattern , filename);break;
	  case 'i': operate_i(pattern , filename);break;
	  case 'w': operate_w(pattern , filename);break;
	  case 'v': operate_v(pattern , filename);break;
	  case 'n': operate_n(pattern , filename);break;
	  case 'x': operate_x(pattern , filename);break;
	  case '*' : operate_default(pattern , filename);break;

  }
}

void operate_default(char *pattern , char *filename)
{
FILE *file = fopen(filename, "r");

char line[MAX_LINE_LENGTH];
while (fgets(line, sizeof(line), file)) 
{
        if (strstr(line, pattern) != 0 )
	   	{
            printf("%s",  line);
        }
}

    fclose(file);
}


void operate_x(char *pattern , char *filename)
{
FILE *file = fopen(filename, "r");

char line[MAX_LINE_LENGTH];
while (fgets(line, sizeof(line), file)) 
{
        if (strstr(line, pattern) != 0 &&  (strlen(pattern) == ((strlen(line)-1) )))
		{
            printf("%s",  line);
		}
}

    fclose(file);
}


void operate_c(char *pattern ,char *filename)
{
FILE *file = fopen(filename, "r");
char line[MAX_LINE_LENGTH];
int line_no =0;
while (fgets(line, sizeof(line), file)) 
{
        if (strstr(line, pattern) != NULL){line_no++;}
}
    printf("%d" , line_no);
    fclose(file);
}



void operate_n(char *pattern ,char *filename)
{
FILE *file = fopen(filename, "r");
char line[MAX_LINE_LENGTH];
int line_no=1;
while (fgets(line, sizeof(line), file)) 
{
        if (strstr(line, pattern) != NULL)
	   	{
            printf("%d:%s",  line_no, line);
        }
line_no++;
}

    fclose(file);
}


void operate_w(char *pattern ,char *filename)
{

char line[MAX_LINE_LENGTH];
FILE *file = fopen(filename, "r");

  while (fgets(line, sizeof(line), file))
  {

        if (strstr_word(line, pattern) != NULL)
	   	{
            printf("%s",  line);
        }
  }
}




void operate_i(char *pattern ,char *filename)
{ 
	
FILE *file = fopen(filename, "r");
char line_l[MAX_LINE_LENGTH];
char line[MAX_LINE_LENGTH];
char pattern_l[100];
string_lower(pattern_l , pattern);
while (fgets(line, sizeof(line), file))
{
  string_lower(line_l , line);
  if (strstr(line_l, pattern_l) != NULL)
  {
            printf("%s",  line);
  }

}
 fclose(file);
}





void operate_v(char *pattern ,char *filename)
{
FILE *file = fopen(filename, "r");
char line[MAX_LINE_LENGTH];
while (fgets(line, sizeof(line), file)) 
{
        if (strstr(line, pattern) == NULL)
	   	{
            printf("%s",  line);
        }
}

    fclose(file);
	
}
