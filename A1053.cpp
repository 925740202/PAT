#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=110;
struct node{  // 结点的结构体
    int weight;    //权重
    vector<int> child;    //孩子结点
}Node[maxn];
bool cmp(int a,int b)   //用来排序孩子结点的权重，按从大到小
{
    return Node[a].weight>Node[b].weight;
}
int n,m,s;//结点个数，非叶结点的个数，路径结点权重和
int path[maxn];//存放结点路径的数组
void DFS(int index,int numNode,int sum)
{
    if(sum>s)return;//当前和大于s直接返回
    if(sum==s)//当前和等于s
    {
        if(Node[index].child.size()!=0)return;//当前结点不是叶结点，直接返回
        for(int i=0;i<numNode;i++)//输出当前路径上结点的weight
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
    for(int i=0;i<Node[index].child.size();i++)//对每个结点的孩子结点进行DFS
    {
        int child=Node[index].child[i];
        path[numNode]=child;//将此孩子结点记录于路径末尾
        DFS(child,numNode+1,sum+Node[child].weight);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);//从键盘输入n,m,s
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Node[i].weight);//输入每个结点的weight
    }
    int id,k,child;//非叶结点的id和孩子数k
    for(int i=0;i<m;i++)//输入非叶结点的都孩子结点
    {
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);//对非叶结点的孩子结点的weight进行从大到小排序
    }
    path[0]=0;//路径上的第一个结点肯定是根节点
    DFS(0,1,Node[0].weight);//DFS求解
	return 0;
}

