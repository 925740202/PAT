#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
struct Node{
     int next;//��һ���ڵ�ĵ�ַ
     char data;//��Ÿýڵ������
     bool flag;//�ýڵ��Ƿ񱻷��ʹ����ڱ�����
}node[maxn];
int main()
{
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=false;
    }
    int s1,s2,n;//���1,2���׵�ַ���ܹ��Ľ����n
    scanf("%d%d%d",&s1,&s2,&n);//�Ӽ����������������׵�ַ�ͽ������
    int address,next;
    char data;
    for(int i=0;i<n;i++)//�Ӽ���ѭ������ÿ������address��data��next
    {
        scanf("%d %c %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
        //node[address].flag=false;
    }
    int p;//�����������������ָ��
    for(p=s1;p!=-1;p=node[p].next)
    {
        node[p].flag=true;    //���������Ľ���flag��Ϊtrue
    }
    for(p=s2;p!=-1;p=node[p].next)
    {
        if(node[p].flag==true) break;//����������Ľ���flagΪtrue˵���ҵ��˹�ͬ��㣬�˳�ѭ��
    }
    if(p!=-1)  //�����ʱpΪ-1˵��û���ҵ���ͬ��㣬���-1
    {
         printf("%05d\n",p);//˵���ҵ��˹�ͬ��㣬�����ͬ���ĵ�ַ
        //printf("-1\n");
    }
    else
    {
         printf("-1\n");
    }
	return 0;
}
