#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
const int maxn=35;
int n;//�������ܹ������Ľ����
using namespace std;
struct node//���Ľṹ
{
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn],in[maxn];//�������������������������
node* creat(int preL,int preR,int inL,int inR)
{
    if(preR<preL)return NULL;
    node* root=new node;
    root->data=pre[preL];//��������ĵ�һ�����Ϊ�����������ĸ��ڵ�
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==pre[preL])break;
    }
    int numLeft=k-inL;//���ڵ��������Ľ�����
    root->lchild=creat(preL+1,preL+numLeft,inL,k-1);
    root->rchild=creat(preL+numLeft+1,preR,k+1,inR);
    return root;//���ظ��ڵ��λ��
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
    int x,pree=0,inn=0;//��ջ��Ԫ��
    scanf("%d",&n);//�Ӽ��������������
    stack<int>  S;
    for(int i=0;i<2*n;i++)
    {
        scanf("%s",str);
        if(strcmp(str,"Push")==0)//���ָ����push����ջ
        {
            scanf("%d",&x);
            pre[pree++]=x;  //��ջ����Ϊ��������
            S.push(x);
        }
        else//���ָ����pop ��ջ��������������������������
        {
           // x=S.top();
            in[inn++]=S.top();
            S.pop();
        }
    }
    postorder(creat(0,n-1,0,n-1));

	return 0;
}

