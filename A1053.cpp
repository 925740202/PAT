#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=110;
struct node{  // ���Ľṹ��
    int weight;    //Ȩ��
    vector<int> child;    //���ӽ��
}Node[maxn];
bool cmp(int a,int b)   //���������ӽ���Ȩ�أ����Ӵ�С
{
    return Node[a].weight>Node[b].weight;
}
int n,m,s;//����������Ҷ���ĸ�����·�����Ȩ�غ�
int path[maxn];//��Ž��·��������
void DFS(int index,int numNode,int sum)
{
    if(sum>s)return;//��ǰ�ʹ���sֱ�ӷ���
    if(sum==s)//��ǰ�͵���s
    {
        if(Node[index].child.size()!=0)return;//��ǰ��㲻��Ҷ��㣬ֱ�ӷ���
        for(int i=0;i<numNode;i++)//�����ǰ·���Ͻ���weight
        {
            printf("%d",Node[path[i]].weight);
            if(i<numNode-1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
        return;

    }
    for(int i=0;i<Node[index].child.size();i++)//��ÿ�����ĺ��ӽ�����DFS
    {
        int child=Node[index].child[i];
        path[numNode]=child;//���˺��ӽ���¼��·��ĩβ
        DFS(child,numNode+1,sum+Node[child].weight);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);//�Ӽ�������n,m,s
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Node[i].weight);//����ÿ������weight
    }
    int id,k,child;//��Ҷ����id�ͺ�����k
    for(int i=0;i<m;i++)//�����Ҷ���Ķ����ӽ��
    {
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);//�Է�Ҷ���ĺ��ӽ���weight���дӴ�С����
    }
    path[0]=0;//·���ϵĵ�һ�����϶��Ǹ��ڵ�
    DFS(0,1,Node[0].weight);//DFS���
	return 0;
}

