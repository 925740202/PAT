#include<iostream>
#include<cstdio>
#include<cstring>
const int maxn=1010;
using namespace std;
int n;//������
struct node{
     int data;
     node* lchild;
     node* rchild;
};//��Ž��Ľṹ������
int Nodee[maxn];//��Ų�����˳�������
int preor[maxn],mirror[maxn];//���BSTǰ�����������;����������������
/************�����½��***********/
node* newNode(int v)
{
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}
/************��BST�в���һ���½��**********/
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
/************����BST************/
node* creat(int data[],int n)
{
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        insert(root,data[i]);
    }
    return root;
}
/***********ǰ�����BST***********/
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
int num=0;//��¼��ǰ����˼������
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
    node* root=creat(Nodee,n);//����BST
    preorder(root);//ǰ�����
    mirrororder(root);//ǰ�������
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

