#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
using namespace std;
const int INF=1000000;
const int maxn=510;
int n,m,c1,c2;//结点总数n，边总数m，起点c1,终点c2
int weight[maxn];//每个点所拥有的resue teams总数
int d[maxn],w[maxn],num[maxn];//存放最短距离的数组
int G[maxn][maxn];
bool vis[maxn]={false};
void Dijstra(int a)
{
    memset(w,0,sizeof(w));
    memset(num,0,sizeof(num));
    fill(d,d+maxn,INF);//将整个d数组赋为INF
    d[a]=0;//起点到达自身的距离为0
    w[a]=weight[a];
    num[a]=1;
    for(int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;//标记u以访问

        for(int v=0;v<n;v++)
        {
            //int v=Adj[u][j].v;
            if(vis[v]==false&&G[u][v]!=INF)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }
                else if(d[u]+G[u][v]==d[v])
                {
                    if(w[u]+weight[v]>w[v])
                    {
                        w[v]=w[u]+weight[v];
                    }
                    num[v]+=num[u];
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);//每个结点的点权
    }
    fill(G[0],G[0]+maxn*maxn,INF);
    //Node C1,C2;
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u]=G[u][v];

    }
    Dijstra(c1);
    printf("%d %d",num[c2],w[c2]);
	return 0;
}

