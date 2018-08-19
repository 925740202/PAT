#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
const int N=50;
const int M=10000;
set<int> num[N];
//vector<int>element[N]
void num_simi(int a,int b)
{
    int simi=0;
    int tot=num[b].size();
//    int c=a<=b?a:b;
//    int d=a>b?a:b;
    for(set<int>::iterator it=num[a].begin();it!=num[a].end();it++)
    {
        if(num[b].find(*it)!=num[b].end())simi++;
        else tot++;
    }
    printf("%.1f%%\n",simi*100.0/tot);
//    return simi;
}
//int num_totl(int a,int b)
//{
//    for(int j=0;j<num[b].size();j++)
//    {
//        num[a].insert(num[b][j]);
//    }
//    return num[a].size();
//}
int main()
{
    int n;          //输入总共有几套需要比较的数据
    int tot,ele;        //每一套数据有几个元素
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tot);
        for(int j=0;j<tot;j++)
        {
            scanf("%d",&ele);
            //element[i].push_back(ele);
            num[i].insert(ele);
        }
    }
    int quer;            //几个相似数
    int compare_1,compare_2;
    scanf("%d",&quer);
    for(int i=0;i<quer;i++)
    {
        scanf("%d%d",&compare_1,&compare_2);
//        for(int j=0;j<element[compare_1].size();j++)
//        {
//            num[compare_1].insert(element[compare_1][j]);
//        }
      num_simi(compare_1,compare_2);
//      int num_tot=(num[compare_1].size()+num[compare_2].size())-simi;
//      float similarity=simi*100.0/num_tot;
//      printf("%.1f%%\n",similarity);
    }
	return 0;
}

