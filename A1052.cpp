#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node{     //定义结点的结构体组成，address,data and next
      int address,next;
      int data;
      bool flag;          //结点是否在链表中
}node[maxn];
bool cmp(Node a,Node b)
{
    if(a.flag==false||b.flag==false)
    {
        return a.flag>b.flag;//a或者b中有一个是无效结点就把它放到后面
    }
    else
    {
        return a.data<b.data;//全是有效结点的话按照数据从小到大排序
    }
}
int main()
{
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=false;   //初始化所有flag为false
    }
    int n,first_address;
    scanf("%d%d",&n,&first_address);   //从键盘输入结点的个数和首地址
    //queue<Node> q1,q2;
    int address,data,next;     //结点的地址，数据和指针
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&address,&data,&next);//循环从键盘输入结点的内容
        node[address].data=data;
        node[address].next=next;
        node[address].address=address;
       // node[address].flag=false;
    }
    int q,count=0;//遍历整个链表的指针,count用来记录数组中的有效数据
    for(q=first_address;q!=-1;q=node[q].next)
    {
        node[q].flag=true;
        count++;
    }
    if(count==0) printf("0 -1\n");
    else{
        sort(node,node+maxn,cmp);
     printf("%d %05d\n",count,node[0].address);
    for(int i=0;i<count;i++)
    {
        if(i!=count-1)
        {
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }
        else
        {
            printf("%05d %d -1",node[i].address,node[i].data);
        }
    }
    }

	return 0;
}

