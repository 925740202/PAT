#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=110;
//int level[maxn],in[maxn];//层序遍历和中序遍历的数组
struct node{
     //int data;
     int lchild;
     int rchild;
}Tree[maxn];
bool notRoot[maxn]={false};
int n,num=0;//n结点总数，num当前输出的结点数
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
int findRoot()//找到根节点的位置
{
    for(int i=0;i<n;i++)
    {
        if(notRoot[i]==false)
        return i;
    }

}
void creat(int x,char a,char b)//建立二叉树
{
   // Tree[x]=x;//根节点
    if(a=='-')
    {
        Tree[x].lchild=-1;//无左孩子，指向-1
    }
    else
    {
        Tree[x].lchild=a-'0';
        notRoot[Tree[x].lchild]=true;//由于其有父亲结点所以他不是根节点
    }
    if(b=='-')
    {
        Tree[x].rchild=-1;//无右孩子，指向-1
    }
    else
    {
        Tree[x].rchild=b-'0';
        notRoot[Tree[x].rchild]=true;//由于其有父亲结点所以他不是根节点
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
void postorder(int root)//后序遍历用于转换二叉树
{
    if(root==-1)return;
    postorder(Tree[root].lchild);
    postorder(Tree[root].rchild);
    swap(Tree[root].lchild,Tree[root].rchild);
}
void inorder(int root)//中序遍历输出反转后的二叉树
{
    if(root==-1)return;
    inorder(Tree[root].lchild);
    print(root);
    inorder(Tree[root].rchild);
}
void BFS(int root)//用于层序输出二叉树
{
    queue<int> Q;
    Q.push(root);
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        print(now);
        if(Tree[now].lchild!=-1)Q.push(Tree[now].lchild);//左子树非空
        if(Tree[now].rchild!=-1)Q.push(Tree[now].rchild);//右子树非空
    }
}
int main()
{
    char lchild,rchild;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%*c%c %c",&lchild,&rchild);
        creat(i,lchild,rchild);//建立二叉树
        //Tree[i].lchild=strTonum(lchild);
        //Tree[i].rchild=strTonum(rchild);
    }
    int root=findRoot();//获得根节点的位置
    postorder(root);//后序遍历用于反转二叉树
    BFS(root);//输出层序遍历
    num=0;
    inorder(root);//输出中序遍历
	return 0;
}

