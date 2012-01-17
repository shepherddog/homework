#include <stdio.h>
#define MAX 8
int queen[MAX][MAX];
int N,K;
int sum=0;

void DFS(int step,int depth)
{
	if(step==K)
	{
		sum++;
		return;
	}
	int i,j;
	for (i = depth; i < N; i++) {
		for (j = 0; j < N; j++) {
			if(queen[i][j]>=1)
				continue;
			else{
				int m;
				for (m = 0; m < N; m++) {
					queen[i][m]++;
					queen[m][j]++;
				}
				DFS(step+1,i+1);
				for (m = 0; m < N; m++) {
					queen[i][m]--;
					queen[m][j]--;
				}

			}
		}
	}
	return;
}

int main(int argc, const char *argv[])
{
	while(scanf("%d %d",&N,&K)!=EOF)
	{
		if (N==-1&&K==-1) {
			break;
		}
		else
		{
			int i,j;
			char c;
			sum=0;
			for (i = 0; i < N; i++) {
		        	for (j = 0; j < N; j++) {
					c=getchar();
					if(c=='#')
						queen[i][j]=0;
					else if(c=='.')
						queen[i][j]=1;
					else
						j--;
		        	}		
			}
			DFS(0,0);
		        printf("%d\n",sum);	
		}
	}
	return 0;
}
