#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1010;
struct mouse{      //��������Ľṹ��
    int weight;   //����
    int r;        //����
}mouse[maxn];
int main()
{
    int np,ng,order;// np ��������� ng ÿ���м�ֻ���� order ���������
    scanf("%d%d",&np,&ng);
    for(int i=0;i<np;i++)
    {
        scanf("%d",&mouse[i].weight);//����ÿֻ���������
    }
    queue<int> q;//�������������Ķ���
    for(int i=0;i<np;i++)
    {
        scanf("%d",&order);
        q.push(order);
    }
    int temp=np,group;   //temp ÿ�ֱȽϵ����������group ÿ�ֱȽϵ����������
    while(q.size()!=1)
    {
        if(temp%ng==0) group=temp/ng;  //������groupΪtemp/ng
        else group=temp/ng+1;         //��������groupΪtemp/ng+1��ȡ��
        for(int i=0;i<group;i++)
        {
            int k=q.front();   //k�����洢��ǰ����������������ı��
            for(int j=0;j<ng;j++)
            {
                if(i*ng+j>=temp) break;   //�������һ�������������ngʱ��ֱ���˳�
                int front=q.front();  //�����ҳ�����������������
                if(mouse[front].weight>mouse[k].weight) {k=front;}//��¼�����������ı��
                mouse[front].r=group+1;//����ʣ�����������Ϊ����+1
                q.pop();//�����ڱȽϹ������󵯳�����
            }
           q.push(k);//��ʤ����������ӣ�������һ�ֵıȽ�
        }
         temp=group;//��һ�ֱȽ����������������һ�ֵ�����
    }
    mouse[q.front()].r=1;//���һ��ʤ�������������Ϊ1
    for(int i=0;i<np;i++)//ѭ��������������
    {
       printf("%d",mouse[i].r);
       if(i<np-1) printf(" ");
    }
	return 0;
}

