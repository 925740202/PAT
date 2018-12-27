#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=510;
const int INF=1000000;
int G[maxn][maxn];//用于存放图的邻接矩阵
int weight[maxn];//用于存放每个城市当前的自行车数量
int Cmax,n,problem_station,m;//Cmax每个station最大存放自行车数量，n是station的数量，problem_station出问题的station，m道路总数
int d[maxn];//存放当前最短路径长度
bool vis[maxn]={false};//当前结点是否已经访问
vector<int> pre[maxn];//存放结点前驱
vector<int> path,tempath;//path存放最终路径，tempath存放临时路径
int minNeed=INF,minRemain=INF,numpath=0;
void Dijkstra(int s)
{
  fill(d,d+maxn,INF);
  d[s]=0;
  for(int i=0;i<n;i++)
  {
      int u=-1,min=INF;
      for(int j=0;j<n;j++)
      {
          if(vis[j]==false&&d[j]<min)
          {
              u=j;
              min=d[j];
          }
      }
      if(u==-1)return;
      vis[u]=true;
      for(int v=0;v<=n;v++)
      {
          if(vis[v]==false&&G[u][v]!=INF)
          {
              if(d[u]+G[u][v]<d[v])
              {
                  d[v]=d[u]+G[u][v];
                  pre[v].clear();
                  pre[v].push_back(u);
              }else if(d[u]+G[u][v]==d[v])
              {
                  pre[v].push_back(u);
              }
          }
      }
  }
}
void DFS(int v)
{
    if(v==0)//递归边界，PBMC
    {
        tempath.push_back(v);
        int need=0,remain=0;
        for(int i=tempath.size()-1;i>=0;i--)
        {
            int id=tempath[i];
            if(weight[id]>0)
            {
                remain+=weight[id];
            }else
            {
                if(remain>abs(weight[id]))
                {
                    remain-=abs(weight[id]);
                }else
                {
                    need+=abs(weight[id])-remain;
                    remain=0;
                }
            }
        }
    if(need<minNeed)
    {
        minNeed=need;
        minRemain=remain;
        path=tempath;
    }else if(need==minNeed&&remain<minRemain)
    {
        minRemain=remain;
        path=tempath;
    }
    tempath.pop_back();
    return;
    }
    tempath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
    {
        DFS(pre[v][i]);
    }
    tempath.pop_back();

}
int main()
{
    scanf("%d%d%d%d",&Cmax,&n,&problem_station,&m);//输入题干信息
    fill(G[0],G[0]+maxn*maxn,INF);
/***********输入每个station现存的自行车数量*****/
int bikenum;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&bikenum);
        weight[i]=bikenum-Cmax/2;//当前站点距离perfect状态的数量
    }
/***********输入道路信息***************************/
    int a,b;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        scanf("%d",&G[a][b]);
        G[b][a]=G[a][b];
    }
    Dijkstra(0);
    DFS(problem_station);
    printf("%d ",minNeed);
    for(int i=path.size()-1;i>=0;i--)
    {
        printf("%d",path[i]);
        if(i>0)printf("->");
    }
    printf(" ");
    printf("%d",minRemain);
	return 0;
}

