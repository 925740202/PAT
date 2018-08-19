#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1010;
struct mouse{      //定义老鼠的结构体
    int weight;   //体重
    int r;        //排名
}mouse[maxn];
int main()
{
    int np,ng,order;// np 老鼠的总数 ng 每组有几只老鼠 order 老鼠的排名
    scanf("%d%d",&np,&ng);
    for(int i=0;i<np;i++)
    {
        scanf("%d",&mouse[i].weight);//输入每只老鼠的重量
    }
    queue<int> q;//定义老鼠排名的队列
    for(int i=0;i<np;i++)
    {
        scanf("%d",&order);
        q.push(order);
    }
    int temp=np,group;   //temp 每轮比较的老鼠个数，group 每轮比较的老鼠的组数
    while(q.size()!=1)
    {
        if(temp%ng==0) group=temp/ng;  //能整除group为temp/ng
        else group=temp/ng+1;         //不能整除group为temp/ng+1，取整
        for(int i=0;i<group;i++)
        {
            int k=q.front();   //k用来存储当前组里重量最大的老鼠的编号
            for(int j=0;j<ng;j++)
            {
                if(i*ng+j>=temp) break;   //用于最后一组如果数量不足ng时，直接退出
                int front=q.front();  //用于找出本组重量最大的老鼠
                if(mouse[front].weight>mouse[k].weight) {k=front;}//记录最大重量老鼠的编号
                mouse[front].r=group+1;//组内剩余老鼠的排名为组数+1
                q.pop();//将组内比较过的老鼠弹出队列
            }
           q.push(k);//将胜出的老鼠入队，进行下一轮的比较
        }
         temp=group;//下一轮比较老鼠的数量等于这一轮的组数
    }
    mouse[q.front()].r=1;//最后一轮胜出的老鼠的排名为1
    for(int i=0;i<np;i++)//循环输出老鼠的排名
    {
       printf("%d",mouse[i].r);
       if(i<np-1) printf(" ");
    }
	return 0;
}

