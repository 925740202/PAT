#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=35;
struct node{
     int data;
     node* lchild;
     node* rchild;
};
int n;//二叉树所含结点个数
int in[maxn],post[maxn];//用于存放中序和后序的数组
node* creat(int postL,int postR,int inL,int inR)
{
    if(postR<postL)return NULL;
    node* root=new node;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==post[postR])//在中序遍历序列里找到根节点的位置
        break;
    }
    int numLeft=k-inL;//在中序遍历中找出根节点左子树的个数
    root->lchild=creat(postL,postL+numLeft-1,inL,k-1);//递归建立左子树
    root->rchild=creat(postL+numLeft,postR-1,k+1,inR);//递归建立右子树
    return root;//返回根节点
}
int num=0;//以输出的结点个数
void BFS(node* root)//利用队列对二叉树进行层序输出
{
    queue<node*> Q;
    Q.push(root);//根节点入队
    while(!Q.empty())
    {
        node* now=Q.front();
        Q.pop();
        num++;
        printf("%d",now->data);//输出当前结点
        if(num<n)
        {
            printf(" ");
        }
        if(now->lchild!=NULL)Q.push(now->lchild);//左子树不空入队
        if(now->rchild!=NULL)Q.push(now->rchild);//右子树不空入队
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post[i]);//输入后序遍历的序列
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);//输入中序遍历的序列
    }
    BFS(creat(0,n-1,0,n-1));
	return 0;
}

