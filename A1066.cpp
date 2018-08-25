#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=25;
int num;
int sequence[maxn];
/***********���ṹ��***********/
struct node
{
    int v,height;
    node* lchild;
    node* rchild;
};
/************���߶�***********/
int getheight(node* root)
{
    if(root==NULL)return 0;
    else
    return root->height;
}
/****************��ý��ƽ������*********/
int getbalancefactor(node* root)
{
    return getheight(root->lchild)-getheight(root->rchild);
}
/***************���½��ĸ߶�**************/
void updateHeight(node* root)
{
    root->height=max(getheight(root->lchild),getheight(root->rchild))+1;
}
/*****************�������***************/
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
/****************�������***************/
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
/**************����һ���½��**********/
node* newNode(int x)
{
    node* Node=new node;//����һ��node�ͱ����ĵ�ַ�ռ�
    Node->v=x;         //���Ȩ�ظ�ֵ
    Node->lchild=Node->rchild=NULL;//��������ΪNULL
    Node->height=1;//���߶�Ϊ1
    return Node;//���ؽ���ַ
}
/***************������************/
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
            if(getbalancefactor(root->lchild)==1)   //LL��
            {
                R(root);
            }
            else if(getbalancefactor(root->lchild)==-1)//LR��
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
          if(getbalancefactor(root->rchild)==-1)//RR��
          {
            L(root);
          }
          else if(getbalancefactor(root->rchild)==1)//RL��
          {
                R(root->rchild);
                L(root);
          }
        }
    }

}
/******************����AVL��*****************/
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

