#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=100010;
struct Node{
       int address,data,next;
       int order;//����������е�˳��
      // bool flag;//�Ƿ�����Ч���
}node[maxn];
bool isExit[maxn];
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}
int main()
{
    for(int i=0;i<maxn;i++)//��ʼ������
    {
        //node[i].flag=false;
        node[i].order=2*maxn;
    }
    for(int i=0;i<maxn;i++)//��ʼ��isExit����
    {
        isExit[i]=false;
    }
    int first_address,n;//�׵�ַ�ͽ������
    scanf("%d%d",&first_address,&n);
    int address,data,next;//������ĵ�ַ����ָ�����
    for(int i=0;i<n;i++)//ѭ������������
    {
        scanf("%d%d%d",&address,&data,&next);
        node[address].address=address;
        node[address].data=data;
        node[address].next=next;
    }
/***********���������ҳ���Ч���***********/
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
    sort(node,node+maxn,cmp);//����Ч����������
    int count=countRemoved+countValid;
    for(int i=0;i<count;i++)//�����Ч��㣬��order��С��С����
    {
        if(i!=countValid-1&&i!=count-1)
        {
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }
        else//δɾ���Ľ������һ����ɾ���������һ����������ʽ
        {
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
    }
	return 0;
}

