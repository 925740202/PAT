#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
struct Node{
     int next;//下一个节点的地址
     char data;//存放该节点的数据
     bool flag;//该节点是否被访问过，哨兵作用
}node[maxn];
int main()
{
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=false;
    }
    int s1,s2,n;//结点1,2的首地址与总共的结点数n
    scanf("%d%d%d",&s1,&s2,&n);//从键盘输入两个结点的首地址和结点总数
    int address,next;
    char data;
    for(int i=0;i<n;i++)//从键盘循环输入每个结点的address、data、next
    {
        scanf("%d %c %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
        //node[address].flag=false;
    }
    int p;//用来遍历两个链表的指针
    for(p=s1;p!=-1;p=node[p].next)
    {
        node[p].flag=true;    //将遍历过的结点的flag置为true
    }
    for(p=s2;p!=-1;p=node[p].next)
    {
        if(node[p].flag==true) break;//如果遍历到的结点的flag为true说明找到了共同结点，退出循环
    }
    if(p!=-1)  //如果此时p为-1说明没有找到共同结点，输出-1
    {
         printf("%05d\n",p);//说明找到了共同结点，输出共同结点的地址
        //printf("-1\n");
    }
    else
    {
         printf("-1\n");
    }
	return 0;
}
