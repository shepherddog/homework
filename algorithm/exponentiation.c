#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024
char buf[MAX];
int main()
{
	char numstr[10]; int i, num, n, s, c; 
	int dotpos = 0, nLen = 0; char *p = numstr;
	while ( scanf("%s%d", numstr, &n) == 2) {
		if (n == 0) {
			printf("1.0\n");
			continue;
		}
		nLen = strlen(numstr);
		for(i=nLen-1;numstr[i]=='0';i--);	//去除尾部的0
		numstr[i+1]='\0';
		nLen=i+1;
		i = 0; 
		while (numstr[i] != '.') ++i;
		dotpos = nLen - i - 1;			
		for (; i < nLen; ++i ) 
			numstr[i] = numstr[i+1];
		num = atoi(numstr); 
		memset(buf, 0, MAX * sizeof(buf[0]));
		buf[1] = 1;  
		dotpos = dotpos * n;			//计算'.'的位置
		while (n > 0) {
			s = 0; c = 0;
			for (i = 1; i < MAX; ++i) {	//计算幂指，存入buf中
				s = num * buf[i] + c;
				c = s / 10; 
				buf[i] = s % 10;
			}
			--n;
		}
		for (i = MAX-1; buf[i] == 0; --i) ;
		i = (i < dotpos)? dotpos : i;
		while (i>0) {
			if (i == dotpos) printf(".");
			printf("%d", buf[i--]);
		}
		printf("\n");
	}
	return 0;
}

