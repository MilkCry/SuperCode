/*
 * Maxline.c
 *
 *  Created on: 2017年3月13日
 *      Author: Milk
 此程序的功能是打印出输入文件的最长行
 */

#include <stdio.h>
#define MAXLINE 1000
int getline(char line[], int maxline);
void copy(char to[], char from[]);
main()
{
	int len; /*当前行长度*/	
	int max; /*目前为止的最长行*/                         
	char line[MAXLINE]; /*当前输入行*/                 
	char longest[MAXLINE]; /* 用于保存最长行*/                         
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s",longest);
	return 0;
}

int getline(char s[], int lim)
{
	int c ,i;
	for (i = 0;i<lim-1 && (c = getchar())!= EOF && c !='\n' ;++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
void copy(char to[],char from[])
{
	int i;
	i=0;
	while ((to[i] = from[i]) != '\0')
		++i;
	}
