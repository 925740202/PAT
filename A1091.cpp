#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,z;
}Node;
const int M=1290,N=130,L=61;//M,N,L的最大数
int m,n,l,t;
//增量矩阵
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
int matrix[M][N][L];//存放结点的矩阵
bool inq[M][N][L]={false};//判断该结点是否进过队列的矩阵
bool judge(int x,int y,int z)//判断是否是有效结点
{
    if(x>=m||x<0||y>=n||y<0||z>=l||z<0)return false;
    if(matrix[x][y][z]==0||inq[x][y][z]==true) return false;
    return true;
}
int BFS(int x,int y,int z)
{
    int tot=0;//当前块中1的个数
    queue<node> Q;//队列Q用来实现BFS
    Node.x=x,Node.y=y,Node.z=z;
    Q.push(Node);
    inq[x][y][z]=true;
    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        tot++;
        for(int i=0;i<6;i++)//循环6次得到6个相邻的位置
        {
            int NewX=top.x+X[i];
            int NewY=top.y+Y[i];
            int NewZ=top.z+Z[i];
            if(judge(NewX,NewY,NewZ))//如果新结点需要访问，入队
            {
               Node.x=NewX,Node.y=NewY,Node.z=NewZ;
               Q.push(Node);
               inq[NewX][NewY][NewZ]=true;
            }
        }
    }
    if(tot>=t)return tot;
    else return 0;
}
int main()
{
    scanf("%d%d%d%d",&m,&n,&l,&t);//从键盘输入m,n,l,t
    for(int i=0;i<l;i++)//首先按层输入
    {
        for(int j=0;j<m;j++)//其次按行
        {
            for(int k=0;k<n;k++)//最后按列
            {
                scanf("%d",&matrix[j][k][i]);
            }

        }
    }
    int ans=0;//记录核心区1的个数总数
    for(int z=0;z<l;z++)//逐个扫描三维数组的每个结点，找出能记录的块
    {
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(matrix[x][y][z]==1&&inq[x][y][z]==false)//当前位置结点为1，并且没有入过队进行BFS
                ans+=BFS(x,y,z);
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}

