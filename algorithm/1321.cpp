#include<iostream>
using namespace std;
int N,K;//N,K
int visit[10][10];//是否有标记
int count=0;//计数
void DFS(int step,int dqh)//搜索,step表示当前搜到了几个棋子,qdh表示从第几行开始搜.(保证下一个棋子在上一个棋子的后面,去掉重复)
{
    if (step==K)
    {
        count++;
        return;
    }
    for (int i=dqh;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if (visit[i][j]>=1)
            {
                continue;
            }
            else
            {               
                for (int m=0;m<N;m++)
                {
                    visit[i][m]++;
                    visit[m][j]++;                    
                }
                DFS(step+1,i+1);
                for (int m=0;m<N;m++)
                {
                    visit[i][m]--;
                    visit[m][j]--;                    
                }
            }
        }
    }
    return ;
}
int main()
{
    while (cin>>N>>K)
    {
        count=0;       
        if (N==-1&&K==-1)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                char tem;
                cin>>tem;
                if (tem=='.')
                {
                    visit[i][j]=1;                    
                }
                else
                {
                    visit[i][j]=0;                   
                }
            }
        }        //输入数据结束
        DFS(0,0);
        cout<<count<<endl;        
    }    
    return 0;
}


