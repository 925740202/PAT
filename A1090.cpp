#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
const int maxn=100010;
using namespace std;
int n;
double p,r;//��Ʒ���ۺͼӼ���,��߼۸�
vector<int> child[maxn];//���ÿ�����ĺ��ӽ��
int num=0,maxdepth=0;
void DFS(int index,int depth)
{
    if(child[index].size()==0)//�ﵽҶ���
    {
        if(depth>maxdepth)
        {
           maxdepth=depth;//���µ�ǰ������
           num=1;            //�����Ƚ����Ϊ1
        }
        else if(depth==maxdepth)//�ҵ���һ����ͬ��ȵĽ��
        {
        num++;
        }
        return;
    }
    for(int i=0;i<child[index].size();i++)
    {
        DFS(child[index][i],depth+1);//�ݹ����ÿ�����ӽ��
    }
}
int main()
{
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100;
    int parent,root;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&parent);
        if(parent==-1)//�ҵ����ڵ�
        {
            root=i;
        }
        else//�����ĺ��ӽ�����
        {
            child[parent].push_back(i);
        }
    }
    DFS(root,0);//DFS���
    printf("%.2lf %d\n",p*pow(1+r,maxdepth),num);
	return 0;
}

