#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10010;
vector<int> G[maxn];
bool vis[maxn];//����Ƿ񱻷���
/*****************�ݹ��������ͼ****************/
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
/************��¼����ͼ���м���components**********/
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
vector<int> temp,ans;//temp��ŵ�һ��DFSʱ���������ڵ㣬ans��ŵڶ���DFSʱ���������ڵ�
int maxh=0;//���߶�
void DFS(int u,int height)//u��ǰ��㣬height��ǰ�����ȣ�
{
    vis[u]=true;
    if(height>maxh)//���µ�ǰ������
    {
        temp.clear();
        maxh=height;
        temp.push_back(u);
    }
    else if(height==maxh)//�����ͬ��ѹ��temp��
    {
        temp.push_back(u);
    }
    for(int i=0;i<G[u].size();i++)
    {
        if(vis[G[u][i]]==false)
        DFS(G[u][i],height+1);//�ݹ�����������ҵ�������
    }
}
int n;//������
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

