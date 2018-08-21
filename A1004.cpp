#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
const int maxn=110;
using namespace std;
vector<int> Node[maxn];
int n,m;//结点总数，和非叶结点的个数
int level[maxn];//记录每层的叶结点个数
int depth=0;//每层叶结点的个数
void BFS(int root)
{
     queue<int> q;
     q.push(root);
     while(!q.empty())
     {
         depth++;
         int now,num=0;
         int v=q.size();
         for(int i=0;i<v;i++)
         {
             now=q.front();
             q.pop();
             if(Node[now].size()==0)
             {
                 num++;
                 //printf("%d\n",num);
             }
             else
             {
                 for(int j=0;j<Node[now].size();j++)
                 {
                   q.push(Node[now][j]);
                 }
             }

         }

         level[depth]=num;//在数组中记录每层的叶结点个数
     }
}
int main()
{
    scanf("%d%d",&n,&m);//从键盘输入结点个数和非叶结点的个数
    int father,k,child;
    for(int i=0;i<m;i++)//输入树的信息
    {
        scanf("%d%d",&father,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            Node[father].push_back(child);//将此结点的孩子结点压入vector
        }
    }
    BFS(1);
    for(int j=1;j<=depth;j++)
    {
        printf("%d",level[j]);//输出每一层的叶结点个数
        if(j<depth)
        {
            printf(" ");
        }
    }
	return 0;
}

