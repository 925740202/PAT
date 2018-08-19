#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
const int maxn=35;
int n;//二叉树总共包含的结点数
using namespace std;
struct node//结点的结构
{
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn],in[maxn];//存放先序遍历和中序遍历的数组
node* creat(int preL,int preR,int inL,int inR)
{
    if(preR<preL)return NULL;
    node* root=new node;
    root->data=pre[preL];//先序遍历的第一个结点为整个二叉树的根节点
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==pre[preL])break;
    }
    int numLeft=k-inL;//根节点左子树的结点个数
    root->lchild=creat(preL+1,preL+numLeft,inL,k-1);
    root->rchild=creat(preL+numLeft+1,preR,k+1,inR);
    return root;//返回根节点的位置
}
int num=0;
void postorder(node* root)
{
    if(root==NULL)return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d",root->data);
    num++;
    if(num<n)
    {
        printf(" ");
    }
}
int main()
{
    char str[5];
    int x,pree=0,inn=0;//入栈的元素
    scanf("%d",&n);//从键盘输入结点的总数
    stack<int>  S;
    for(int i=0;i<2*n;i++)
    {
        scanf("%s",str);
        if(strcmp(str,"Push")==0)//如果指令是push则入栈
        {
            scanf("%d",&x);
            pre[pree++]=x;  //入栈的数为先序序列
            S.push(x);
        }
        else//如果指令是pop 出栈，弹出的数进入中序序列数组
        {
           // x=S.top();
            in[inn++]=S.top();
            S.pop();
        }
    }
    postorder(creat(0,n-1,0,n-1));

	return 0;
}

