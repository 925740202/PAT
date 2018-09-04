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
    if(v==currentpoint)return;//��������ɾ�����ʱֱ�ӷ���
    vis[v]=true;//��Ǹý���Է���
    for(int i=0;i<G[v].size();i++)//�ݹ������ý�������Ľ��
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
        //����ͼ��¼��ͳ�������
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int query=0;query<k;query++)
    {
        memset(vis,false,sizeof(vis));
        int block=0;
        scanf("%d",&currentpoint);//���뱻ɾ���Ľ��
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

