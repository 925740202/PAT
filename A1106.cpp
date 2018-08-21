#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
const int maxn=100010;
using namespace std;
vector<int> Node[maxn];
int n;
double price,rate;
/******ע��mindepth��ʼֵӦ�ò�С���������**********/
int mindepth=maxn,num=0;//�����͵���������������ĸ���     ******ע��mindepth��ʼֵӦ�ò�С���������**********
bool notRoot[maxn]={false};//bool�����������жϵ�ǰ����Ƿ�Ϊ����
void DFS(int index,int depth)
{

    if(Node[index].size()==0)//����Ҷ���
    {
        if(mindepth>depth)//�����ǰ��ǳ��ȴ��ڵ�ǰ��ȣ�������ǳ���
        {
        mindepth=depth;
        num=1;              //������ǳ���Ҷ���ĸ���
        }
        else if(mindepth==depth)//��ȵ���������
        {
        num++;                //Ҷ��������һ
        }
        return;
    }
    for(int i=0;i<Node[index].size();i++)
    {
        DFS(Node[index][i],depth+1);//�ݹ����index���ĺ��ӽ��
    }

}
int findRoot()
{
    //int root;
   for(int i=0;i<n;i++)
   {
       if(notRoot[i]==false)
       {
          // root=i;
          return i;
       }
   }
}
int main()
{
    int child,k;//kΪÿ����㺢�ӵ�����
    scanf("%d%lf%lf",&n,&price,&rate);//�������������۸�price���Ӽ���rate
    rate/=100;
    for(int i=0;i<n;i++)//������Ϣ��������Ʒ��ͨ��
    {
        scanf("%d",&k);
        if(k!=0)
        {
            for(int j=0;j<k;j++)//���ĺ�������Ϊ0ʱ���������뺢��
            {
                scanf("%d",&child);
                Node[i].push_back(child);
                notRoot[child]=true;//child�ڵ㲻�Ǹ��ڵ㣬���и��׽��
            }
        }
    }
    DFS(findRoot(),0);//DFS���
   // printf("%.4lf",pow(1+rate,mindepth));
    printf("%.4lf %d\n",price*pow(1+rate,mindepth),num);//������
	return 0;
}

