#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> G[maxn];
bool vis[maxn];
int currentpoint;
void dfs(int v)
{
    if(v==currentpoint)return;//遍历到已删除结点时直接返回
    vis[v]=true;//标记该结点以访问
    for(int i=0;i<G[v].size();i++)//递归访问与该结点相连的结点
    {
        if(vis[G[v][i]]==false)
        {
            dfs(G[v][i]);
        }
    }
}
int n,m,k;
int main()
{

    scanf("%d%d%d",&n,&m,&k);
    int a,b;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        //无向图记录入和出两条边
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int query=0;query<k;query++)
    {
        memset(vis,false,sizeof(vis));
        int block=0;
        scanf("%d",&currentpoint);//输入被删除的结点
        for(int i=1;i<=n;i++)
        {
            if(i!=currentpoint&&vis[i]==false)
            {
                dfs(i);
                block++;
            }
        }
        printf("%d\n",block-1);
//        if(query<k-1)
//        printf(" ");
    }
	return 0;
}

