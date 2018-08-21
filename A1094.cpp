#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
const int maxn=110;
using namespace std;
vector<int> Node[maxn];//存放结点
int n,m;//结点总数n，有孩子的结点数m
int maxnum=0,num=0,level=0,maxlevel;//当前level有多少个结点
void BFS(int root)
{
    queue<int> q;//用来进行层序遍历的队列
    q.push(root);
    while(!q.empty())
    {
        num=q.size();//当前层的孩子数
        level++;
        if(maxnum<num)//如果当前层的孩子数大于maxnum则更新maxnum与maxlevel
        {
            maxnum=num;
            maxlevel=level;
        }
        int now;
        for(int j=0;j<num;j++)//将本层结点全部弹出，本层结点的孩子结点全部压入队列
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
    for(int i=0;i<m;i++)//输入家庭成员树
    {
        scanf("%d%d",&nowNode,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            Node[nowNode].push_back(child);
        }
    }
    BFS(01);//BFS入口
    printf("%d %d\n",maxnum,maxlevel);
	return 0;
}

