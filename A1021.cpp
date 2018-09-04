#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10010;
vector<int> G[maxn];
bool vis[maxn];//结点是否被访问
/*****************递归访问所给图****************/
void dfs(int v)
{
    vis[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(vis[u]==false)
        dfs(u);
    }
}
/************记录所给图中有几个components**********/
int component(int n)
{
    memset(vis,false,sizeof(vis));
    int components=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
           dfs(i);
           components++;
        }
    }
    return components;
}
vector<int> temp,ans;//temp存放第一次DFS时的最深树节点，ans存放第二次DFS时的最深树节点
int maxh=0;//最大高度
void DFS(int u,int height)//u当前结点，height当前结点深度，
{
    vis[u]=true;
    if(height>maxh)//更新当前最大深度
    {
        temp.clear();
        maxh=height;
        temp.push_back(u);
    }
    else if(height==maxh)//深度相同，压入temp中
    {
        temp.push_back(u);
    }
    for(int i=0;i<G[u].size();i++)
    {
        if(vis[G[u][i]]==false)
        DFS(G[u][i],height+1);//递归遍历子树，找到最深结点
    }
}
int n;//结点个数
int main()
{
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(component(n)!=1)
    {
        printf("Error: %d components",component(n));
    }
    else
    {
        memset(vis,false,sizeof(vis));
        DFS(1,1);
        ans=temp;
        memset(vis,false,sizeof(vis));
        DFS(ans[0],1);
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]!=ans[i-1])
            printf("%d\n",ans[i]);
        }
    }
	return 0;
}

