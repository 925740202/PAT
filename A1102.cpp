#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=110;
//int level[maxn],in[maxn];//����������������������
struct node{
     //int data;
     int lchild;
     int rchild;
}Tree[maxn];
bool notRoot[maxn]={false};
int n,num=0;//n���������num��ǰ����Ľ����
void print(int root)
{
    printf("%d",root);
    num++;
    if(num<n)
    {
        printf(" ");
    }
    else
    {
        printf("\n");
    }
}
int findRoot()//�ҵ����ڵ��λ��
{
    for(int i=0;i<n;i++)
    {
        if(notRoot[i]==false)
        return i;
    }

}
void creat(int x,char a,char b)//����������
{
   // Tree[x]=x;//���ڵ�
    if(a=='-')
    {
        Tree[x].lchild=-1;//�����ӣ�ָ��-1
    }
    else
    {
        Tree[x].lchild=a-'0';
        notRoot[Tree[x].lchild]=true;//�������и��׽�����������Ǹ��ڵ�
    }
    if(b=='-')
    {
        Tree[x].rchild=-1;//���Һ��ӣ�ָ��-1
    }
    else
    {
        Tree[x].rchild=b-'0';
        notRoot[Tree[x].rchild]=true;//�������и��׽�����������Ǹ��ڵ�
    }

}
//int strTonum(char c)
//{
//    if(c=='-')return -1;
//    else
//    {
//        notRoot[c-'0']=true;
//        return c-'0';
//    }
//}
void postorder(int root)//�����������ת��������
{
    if(root==-1)return;
    postorder(Tree[root].lchild);
    postorder(Tree[root].rchild);
    swap(Tree[root].lchild,Tree[root].rchild);
}
void inorder(int root)//������������ת��Ķ�����
{
    if(root==-1)return;
    inorder(Tree[root].lchild);
    print(root);
    inorder(Tree[root].rchild);
}
void BFS(int root)//���ڲ������������
{
    queue<int> Q;
    Q.push(root);
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        print(now);
        if(Tree[now].lchild!=-1)Q.push(Tree[now].lchild);//�������ǿ�
        if(Tree[now].rchild!=-1)Q.push(Tree[now].rchild);//�������ǿ�
    }
}
int main()
{
    char lchild,rchild;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%*c%c %c",&lchild,&rchild);
        creat(i,lchild,rchild);//����������
        //Tree[i].lchild=strTonum(lchild);
        //Tree[i].rchild=strTonum(rchild);
    }
    int root=findRoot();//��ø��ڵ��λ��
    postorder(root);//����������ڷ�ת������
    BFS(root);//����������
    num=0;
    inorder(root);//����������
	return 0;
}

