#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>
using namespace std;
vector<int> fac,ans,temp;//vector容器，用来存储最优底数序列
int n,k,p,maxfacsum=-1;
void init()   //初始化fac容器，找到所有i使得i^p<=n
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
            ans=temp;     //更新最优底数序列
            maxfacsum=facsum;  //更新最大底数之和
        }
        return;
    }
   // temp.push_back()
   if(sum>n||nowK>k)return;//当前序列之和大于n或者是所选的数超过了k直接返回
   if(index-1>=0)//fac[0]不需要选择
   {
       temp.push_back(index);//选中的数进入temp容器
       DFS(index,nowK+1,sum+fac[index],facsum+index);//可以选择重复的数
       temp.pop_back();//未选中的数从temp容器中抛出
       DFS(index-1,nowK,sum,facsum); //没有选择的分支
   }
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);//从键盘输入n,p,k
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
