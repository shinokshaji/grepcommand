#include<stdio.h>
#include<string.h>
#define default_operation  '*'
#define invalid_option  '#'
#define SUCCESS          1
#define FAIL             0
#define MAX_LINE_LENGTH 1024
char option_check(char**argv);
int file_check(char * filename);

void grep_operate(char operator , char *pattern , char *filename);
//operations
void operate_c(char *pattern ,char *filename);
void operate_v(char *pattern ,char *filename);
void operate_i(char *pattern ,char *filename);
void operate_w(char *pattern ,char *filename);
void operate_n(char *pattern ,char *filename);
void operate_x(char *pattern , char *filename);
void operate_default(char *pattern , char *filename);
