#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>
using namespace std;
vector<int> fac,ans,temp;//vector�����������洢���ŵ�������
int n,k,p,maxfacsum=-1;
void init()   //��ʼ��fac�������ҵ�����iʹ��i^p<=n
{
   int i=0,sumtemp=0;
   while(sumtemp<=n)
   {
       fac.push_back(sumtemp);
       sumtemp=pow(++i,p);
   }
}
void DFS(int index,int nowK,int sum,int facsum)
{
    if(sum==n&&nowK==k)
    {
        if(facsum>maxfacsum)
        {
            ans=temp;     //�������ŵ�������
            maxfacsum=facsum;  //����������֮��
        }
        return;
    }
   // temp.push_back()
   if(sum>n||nowK>k)return;//��ǰ����֮�ʹ���n��������ѡ����������kֱ�ӷ���
   if(index-1>=0)//fac[0]����Ҫѡ��
   {
       temp.push_back(index);//ѡ�е�������temp����
       DFS(index,nowK+1,sum+fac[index],facsum+index);//����ѡ���ظ�����
       temp.pop_back();//δѡ�е�����temp�������׳�
       DFS(index-1,nowK,sum,facsum); //û��ѡ��ķ�֧
   }
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);//�Ӽ�������n,p,k
    init();
    DFS(fac.size()-1,0,0,0);
    if(maxfacsum==-1)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%d = %d^%d",n,ans[0],p);
        for(int i=1;i<k;i++)
        {
            printf(" + %d^%d",ans[i],p);
        }
    }

	return 0;
}
