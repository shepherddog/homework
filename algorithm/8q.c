#include <stdio.h>
#define MAX 8
int queen[MAX],sum=0;
void show() /* 显示坐标 */
{
	int i;
	for(i=0;i<MAX;i++)
		printf("(%d %d) ",i,queen[i]);
	printf("\n");
	sum++;
}
int check(int n) /* 判断是否符合要求 */
{
	int i;
	for(i=0;i<n;i++)
	{
		if(queen[i]==queen[n]||abs(queen[n]-queen[i])==(n-i))
			return 1;
	}
	return 0;

}
void put(int n) /* 使用回溯法 */
{
	int i;
	for (i = 0; i < MAX; i++) {
		queen[n]=i;
		if(!check(n))
		{
			if(n==MAX-1)
				show();
			else
				put(n+1);
		}
	}
}
int main(int argc, const char *argv[])
{
	put(0);
	printf("%d\n",sum);
	return 0;
}

