#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=100010;
struct Node{
       int address,data,next;
       int order;//结点在链表中的顺序
      // bool flag;//是否是有效结点
}node[maxn];
bool isExit[maxn];
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}
int main()
{
    for(int i=0;i<maxn;i++)//初始化数组
    {
        //node[i].flag=false;
        node[i].order=2*maxn;
    }
    for(int i=0;i<maxn;i++)//初始化isExit数组
    {
        isExit[i]=false;
    }
    int first_address,n;//首地址和结点总数
    scanf("%d%d",&first_address,&n);
    int address,data,next;//定义结点的地址数据指针变量
    for(int i=0;i<n;i++)//循环输入结点数据
    {
        scanf("%d%d%d",&address,&data,&next);
        node[address].address=address;
        node[address].data=data;
        node[address].next=next;
    }
/***********遍历链表找出有效结点***********/
    int p,countValid=0,countRemoved=0;
    for(p=first_address;p!=-1;p=node[p].next)
    {
        if(!isExit[abs(node[p].data)])
        {
            isExit[abs(node[p].data)]=true;
            node[p].order=countValid++;
        }
        else
        {
            node[p].order=maxn+countRemoved++;
        }
    }
    sort(node,node+maxn,cmp);//对有效结点进行排序
    int count=countRemoved+countValid;
    for(int i=0;i<count;i++)//输出有效结点，按order大小从小到大
    {
        if(i!=countValid-1&&i!=count-1)
        {
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }
        else//未删除的结点的最后一个和删除结点的最后一个结点输出方式
        {
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
    }
	return 0;
}

