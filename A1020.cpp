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
int n;//����������������
int in[maxn],post[maxn];//���ڴ������ͺ��������
node* creat(int postL,int postR,int inL,int inR)
{
    if(postR<postL)return NULL;
    node* root=new node;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==post[postR])//����������������ҵ����ڵ��λ��
        break;
    }
    int numLeft=k-inL;//������������ҳ����ڵ��������ĸ���
    root->lchild=creat(postL,postL+numLeft-1,inL,k-1);//�ݹ齨��������
    root->rchild=creat(postL+numLeft,postR-1,k+1,inR);//�ݹ齨��������
    return root;//���ظ��ڵ�
}
int num=0;//������Ľ�����
void BFS(node* root)//���ö��жԶ��������в������
{
    queue<node*> Q;
    Q.push(root);//���ڵ����
    while(!Q.empty())
    {
        node* now=Q.front();
        Q.pop();
        num++;
        printf("%d",now->data);//�����ǰ���
        if(num<n)
        {
            printf(" ");
        }
        if(now->lchild!=NULL)Q.push(now->lchild);//�������������
        if(now->rchild!=NULL)Q.push(now->rchild);//�������������
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post[i]);//����������������
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);//�����������������
    }
    BFS(creat(0,n-1,0,n-1));
	return 0;
}

