#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
struct node//���Ľṹ����ʽ
{
    double data;
    vector<int> child;
}Node[maxn];
int n;//����ܸ���
double p,r,ans=0;//��Ʒ�۸���Ӽ۱���
void DFS(int index,int depth)
{
    if(Node[index].child.size()==0)
    {
        ans+=Node[index].data*pow(1+r,depth);//���Ҷ��㴦�ļ۸񣬲��ۼ�
        return;
    }
    for(int i=0;i<Node[index].child.size();i++)
    {
        DFS(Node[index].child[i],depth+1);//�ݹ�����ӽ��
    }

}
int main()
{
    int k,child;
    scanf("%d%lf%lf",&n,&p,&r);//�Ӽ���������ĸ�������Ʒ�ļ۸񣬼Ӽ���
    r/=100;//��r�׷ֻ�
    //int numc;//i���ĺ�����
   // int c;//���ӽ��
    for(int i=0;i<n;i++)//������������
    {
        scanf("%d",&k);
        if(k==0)//ΪҶ���
        {
             scanf("%lf",&Node[i].data);

        }
        else//�к��ӽ��
        {
            //int num;//Ҷ������Ʒ����

            for(int j=0;j<k;j++)
            {
                scanf("%d",&child);
                Node[i].child.push_back(child);//�����ӽ��ѹ��vector
            }
            //Node[i].data=num;
        }
    }
    DFS(0,0);
    printf("%.1lf\n",p*ans);//������յĽ��
	return 0;
}

