#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
const int maxn=110;
using namespace std;
vector<int> Node[maxn];
int n,m;//����������ͷ�Ҷ���ĸ���
int level[maxn];//��¼ÿ���Ҷ������
int depth=0;//ÿ��Ҷ���ĸ���
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

         level[depth]=num;//�������м�¼ÿ���Ҷ������
     }
}
int main()
{
    scanf("%d%d",&n,&m);//�Ӽ�������������ͷ�Ҷ���ĸ���
    int father,k,child;
    for(int i=0;i<m;i++)//����������Ϣ
    {
        scanf("%d%d",&father,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            Node[father].push_back(child);//���˽��ĺ��ӽ��ѹ��vector
        }
    }
    BFS(1);
    for(int j=1;j<=depth;j++)
    {
        printf("%d",level[j]);//���ÿһ���Ҷ������
        if(j<depth)
        {
            printf(" ");
        }
    }
	return 0;
}

