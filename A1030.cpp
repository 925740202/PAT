#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=510;
const int INF=10000000;
int n,m,s,ed;
int G[maxn][maxn],d[maxn],cost[maxn][maxn],pre[maxn],c[maxn];//G�洢ͼ��d�洢ÿ�����㵽��ǰ�������С���룬cost�洢ÿ����·��·��
//vector<int> path;//������·��
bool vis[maxn];//��¼��ǰ����Ƿ��Ѿ�������
void Dijkstra(int a)
{
    memset(vis,false,sizeof(vis));//��vis��ʼ��Ϊfalse
    fill(d,d+maxn,INF);//��d����ĳ�ֵ��ΪINF
    fill(c,c+maxn,INF);
    d[a]=0;//��㵽�ﱾ��ľ���Ϊ0
    c[s]=0;
    for(int j=0;j<n;j++) pre[j]=j;
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
        for(int v=0;v<n;v++)
        {
           if(vis[v]==false&&G[u][v]!=INF)
           {
             if(d[u]+G[u][v]<d[v])
             {
                d[v]=d[u]+G[u][v];
                c[v]=c[u]+cost[u][v];
                pre[v]=u;
             }
            else if(d[u]+G[u][v]==d[v])
              {
                if(c[u]+cost[u][v]<c[v])
                 {
                    c[v]=c[u]+cost[u][v];
                    pre[v]=u;
                 }
              }
            }
         }
    }

}
void DFS(int v)
{
    if(v==s)
    {
        printf("%d ",v);
        return;
    }
    DFS(pre[v]);
    printf("%d ",v);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&ed);
    fill(G[0],G[0]+maxn*maxn,INF);
    int city1,city2;
/************������е�·֮�����Ϣ*************/
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&city1,&city2);
        scanf("%d",&G[city1][city2]);
        G[city2][city1]=G[city1][city2];
        scanf("%d",&cost[city1][city2]);
        cost[city2][city1]=cost[city1][city2];
    }
    Dijkstra(s);//Dijkstra���
    DFS(ed);
    printf("%d %d\n",d[ed],c[ed]);
	return 0;
}

