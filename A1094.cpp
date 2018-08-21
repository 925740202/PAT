#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
const int maxn=110;
using namespace std;
vector<int> Node[maxn];//��Ž��
int n,m;//�������n���к��ӵĽ����m
int maxnum=0,num=0,level=0,maxlevel;//��ǰlevel�ж��ٸ����
void BFS(int root)
{
    queue<int> q;//�������в�������Ķ���
    q.push(root);
    while(!q.empty())
    {
        num=q.size();//��ǰ��ĺ�����
        level++;
        if(maxnum<num)//�����ǰ��ĺ���������maxnum�����maxnum��maxlevel
        {
            maxnum=num;
            maxlevel=level;
        }
        int now;
        for(int j=0;j<num;j++)//��������ȫ��������������ĺ��ӽ��ȫ��ѹ�����
        {
            now=q.front();
            q.pop();
            if(Node[now].size()!=0)
            {
            for(int i=0;i<Node[now].size();i++)
              {
                q.push(Node[now][i]);
              }
            }
        }

    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int nowNode,child,k;
    for(int i=0;i<m;i++)//�����ͥ��Ա��
    {
        scanf("%d%d",&nowNode,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            Node[nowNode].push_back(child);
        }
    }
    BFS(01);//BFS���
    printf("%d %d\n",maxnum,maxlevel);
	return 0;
}

