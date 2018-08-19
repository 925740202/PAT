#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node{     //������Ľṹ����ɣ�address,data and next
      int address,next;
      int data;
      bool flag;          //����Ƿ���������
}node[maxn];
bool cmp(Node a,Node b)
{
    if(a.flag==false||b.flag==false)
    {
        return a.flag>b.flag;//a����b����һ������Ч���Ͱ����ŵ�����
    }
    else
    {
        return a.data<b.data;//ȫ����Ч���Ļ��������ݴ�С��������
    }
}
int main()
{
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=false;   //��ʼ������flagΪfalse
    }
    int n,first_address;
    scanf("%d%d",&n,&first_address);   //�Ӽ���������ĸ������׵�ַ
    //queue<Node> q1,q2;
    int address,data,next;     //���ĵ�ַ�����ݺ�ָ��
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&address,&data,&next);//ѭ���Ӽ��������������
        node[address].data=data;
        node[address].next=next;
        node[address].address=address;
       // node[address].flag=false;
    }
    int q,count=0;//�������������ָ��,count������¼�����е���Ч����
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

