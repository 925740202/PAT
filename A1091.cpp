#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,z;
}Node;
const int M=1290,N=130,L=61;//M,N,L�������
int m,n,l,t;
//��������
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
int matrix[M][N][L];//��Ž��ľ���
bool inq[M][N][L]={false};//�жϸý���Ƿ�������еľ���
bool judge(int x,int y,int z)//�ж��Ƿ�����Ч���
{
    if(x>=m||x<0||y>=n||y<0||z>=l||z<0)return false;
    if(matrix[x][y][z]==0||inq[x][y][z]==true) return false;
    return true;
}
int BFS(int x,int y,int z)
{
    int tot=0;//��ǰ����1�ĸ���
    queue<node> Q;//����Q����ʵ��BFS
    Node.x=x,Node.y=y,Node.z=z;
    Q.push(Node);
    inq[x][y][z]=true;
    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        tot++;
        for(int i=0;i<6;i++)//ѭ��6�εõ�6�����ڵ�λ��
        {
            int NewX=top.x+X[i];
            int NewY=top.y+Y[i];
            int NewZ=top.z+Z[i];
            if(judge(NewX,NewY,NewZ))//����½����Ҫ���ʣ����
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
    scanf("%d%d%d%d",&m,&n,&l,&t);//�Ӽ�������m,n,l,t
    for(int i=0;i<l;i++)//���Ȱ�������
    {
        for(int j=0;j<m;j++)//��ΰ���
        {
            for(int k=0;k<n;k++)//�����
            {
                scanf("%d",&matrix[j][k][i]);
            }

        }
    }
    int ans=0;//��¼������1�ĸ�������
    for(int z=0;z<l;z++)//���ɨ����ά�����ÿ����㣬�ҳ��ܼ�¼�Ŀ�
    {
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(matrix[x][y][z]==1&&inq[x][y][z]==false)//��ǰλ�ý��Ϊ1������û������ӽ���BFS
                ans+=BFS(x,y,z);
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}

