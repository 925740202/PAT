#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=25;
int num;
int sequence[maxn];
/***********结点结构体***********/
struct node
{
    int v,height;
    node* lchild;
    node* rchild;
};
/************结点高度***********/
int getheight(node* root)
{
    if(root==NULL)return 0;
    else
    return root->height;
}
/****************获得结点平衡因子*********/
int getbalancefactor(node* root)
{
    return getheight(root->lchild)-getheight(root->rchild);
}
/***************更新结点的高度**************/
void updateHeight(node* root)
{
    root->height=max(getheight(root->lchild),getheight(root->rchild))+1;
}
/*****************结点左旋***************/
node* L(node* &root)
{
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
    return root;
}
/****************结点右旋***************/
node* R(node* &root)
{
    node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
    return root;
}
/**************建立一个新结点**********/
node* newNode(int x)
{
    node* Node=new node;//申请一个node型变量的地址空间
    Node->v=x;         //结点权重赋值
    Node->lchild=Node->rchild=NULL;//左右子树为NULL
    Node->height=1;//结点高度为1
    return Node;//返回结点地址
}
/***************插入结点************/
void insert(node* &root,int n)
{
    if(root==NULL)
    {
        root=newNode(n);
        return;
    }
    if(n<root->v)
    {
        insert(root->lchild,n);
        updateHeight(root);
        if(getbalancefactor(root)==2)
        {
            if(getbalancefactor(root->lchild)==1)   //LL型
            {
                R(root);
            }
            else if(getbalancefactor(root->lchild)==-1)//LR型
            {
                L(root->lchild);
                R(root);
            }
        }
    }
    else
    {
        insert(root->rchild,n);
        updateHeight(root);
        if(getbalancefactor(root)==-2)
        {
          if(getbalancefactor(root->rchild)==-1)//RR型
          {
            L(root);
          }
          else if(getbalancefactor(root->rchild)==1)//RL型
          {
                R(root->rchild);
                L(root);
          }
        }
    }

}
/******************创建AVL树*****************/
node* creat(int data[],int n)
{
   node* root=NULL;
   for(int i=0;i<n;i++)
   {
       insert(root,data[i]);
   }
   return root;
}
int main()
{
    int data;
    //node* root=NULL;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&sequence[i]);
       // scanf("%d",&data);
        //insert(root,data);
    }
    node* root=creat(sequence,num);
    printf("%d\n",root->v);
  //  printf("%d\n",creat(sequence,num)->v);
	return 0;
}

