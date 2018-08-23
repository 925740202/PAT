#include<iostream>
#include<cstdio>
#include<cstring>
const int maxn=1010;
using namespace std;
int n;//结点个数
struct node{
     int data;
     node* lchild;
     node* rchild;
};//存放结点的结构体数组
int Nodee[maxn];//存放插入结点顺序的数组
int preor[maxn],mirror[maxn];//存放BST前序遍历的数组和镜像遍历的数组数组
/************建立新结点***********/
node* newNode(int v)
{
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}
/************在BST中插入一个新结点**********/
void insert(node* &root,int x)
{
    if(root==NULL)
    {
        root=newNode(x);
        return;
    }
//    if(x==root->data)
//    {
//        return;
//    }
    if(x<root->data)
    {insert(root->lchild,x);}
    else
    {
        insert(root->rchild,x);
    }
}
/************创建BST************/
node* creat(int data[],int n)
{
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        insert(root,data[i]);
    }
    return root;
}
/***********前序遍历BST***********/
int a=0;
void preorder(node* root)
{
   if(root)
   {
       preor[a++]=root->data;
       preorder(root->lchild);
       preorder(root->rchild);
   }

}
int b=0;
void mirrororder(node* root)
{
   if(root)
   {
        mirror[b++]=root->data;
        mirrororder(root->rchild);
        mirrororder(root->lchild);
   }

}
int num=0;//记录当前输出了几个结点
void postorder(node *root)
{
    if(root)
    {
       postorder(root->lchild);
       postorder(root->rchild);
       printf("%d",root->data);
       num++;
    if(num<n)
    {
        printf(" ");
    }

    }

}
void mpostorder(node *root)
{
    if(root)
    {
       mpostorder(root->rchild);
       mpostorder(root->lchild);
       printf("%d",root->data);
       num++;
    if(num<n)
    {
        printf(" ");
    }

    }

}
bool compare(int a[],int b[])
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]){num++;}
       // printf("%d\n",num);
    }
    if(num==n)
    {

        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Nodee[i]);
    }
    node* root=creat(Nodee,n);//建立BST
    preorder(root);//前序遍历
    mirrororder(root);//前序镜像遍历
//    for(int i=0;i<n;i++)
//    {
//        printf("%d ",preor[i]);
//    }
//    printf("\n");
//    for(int i=0;i<n;i++)
//    {
//        printf("%d ",mirror[i]);
//    }
//     printf("\n");
    if(compare(Nodee,preor))
    {
        printf("YES\n");
        postorder(root);
    }
    else if(compare(Nodee,mirror))
    {
        printf("YES\n");
        mpostorder(root);
    }
    else
    {
        printf("NO\n");
    }
   // printf("%d\n",num);
	return 0;
}

