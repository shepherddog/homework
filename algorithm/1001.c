#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 100
char s[max];
int n;
struct r{
	int num;
	int factor;
}key;

void split_s(){
	char temp[max];
	strcpy(temp,s);
	int i;
	for (i = 0; s[i]!='.'&&s[i]!='\0'; i++) {
		temp[i]=s[i];
	}
	temp[i]='\0';
	key.num=atoi(temp);
	key.factor=1;
	char *small=strchr(s,'.');
	if(small!=NULL)
	{
		for (i = 1; small[i]!='\0'; i++) {
			key.factor*=10;
		}
		char *t=&small[1];
		int small=atoi(t);
		while((small%10)==0){
			small=small/10;
			key.factor/=10;
		}
		key.num=key.num*key.factor+small;
	}
	else
		key.factor=0;
}

void compute(){
	long result=1;
	long div=1;
	long b;
	long s;
	while(n!=0)
	{
		result=result*key.num;
		div=div*key.factor;
		n--;
	}
	if(div!=0)
	{
		b=result/div;
		s=result%div;
		printf("%ld.%ld\n",b,s);
	}
	else
		printf("%ld\n",result);

}

int main(int argc, const char *argv[])
{
	while(scanf("%s%d",s,&n)==2)
	{
		split_s();
		compute();
	}
	return 0;
}

