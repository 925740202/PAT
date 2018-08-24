#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
const int maxn=1010;
using namespace std;
int sequence[maxn],cbt[maxn],indexx=0;
int n;//�������
void inorder(int root)
{
    if(root>n)return;
    inorder(root*2);
    cbt[root]=sequence[indexx++];
    inorder(root*2+1);
}
int main()
{
    scanf("%d",&n);//���������
    for(int i=0;i<n;i++)
    {
        scanf("%d",&sequence[i]);
    }
    sort(sequence,sequence+n);
    inorder(1);
    for(int i=1;i<=n;i++)
    {
        printf("%d",cbt[i]);
        if(i<n)printf(" ");
    }
    return 0;
}
/********************************************�����������*****************************
struct node            //���ṹ
{
    int data;
    node* lchild;
    node* rchild;
};
/****************BST�Ľ���*************
node* newNode(int v)
{
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}
void insert(node* &root,int x)
{
    if(root==NULL)
    {
        root=newNode(x);
        return;
    }
    else if(x<root->data)
    {
        insert(root->lchild,x);
    }
    else
    {
        insert(root->rchild,x);
    }
}
node* creat(int data[],int n)
{
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        insert(root,data[i]);
    }
    return root;
}
/***************************************/
/******************CBT�Ĳ������*************
int num=0;//��ǰ������ĸ���
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* now=q.front();
        q.pop();
        printf("%d",now->data);
        num++;
        if(num<n)
        {
            printf(" ");
        }
        if(now->lchild!=NULL)
        {
            q.push(now->lchild);
        }
        if(now->rchild!=NULL)
        {
            q.push(now->rchild);
        }
    }
}
int main()
{
    scanf("%d",&n);//�Ӽ���������ĸ���
    for(int i=0;i<n;i++)//��������Ϣ
    {
        scanf("%d",&sequence[i]);
    }
    levelorder(creat(sequence,n));
	return 0;
}
**********************************************/
