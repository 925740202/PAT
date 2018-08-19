#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int main()
{
    int n,m,color;//定义行列和颜色号
    map<int,int>mp;//开map存出现最多的颜色号
    scanf("%d%d",&n,&m);//输入行列
    for(int i=0;i<m;i++)//循环输入颜色号
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&color);
            if(mp.find(color)!=mp.end()) mp[color]++;//如果色号出现过，对应的色号键值+1
            else//没出现过得色号键值对应置为1
            mp[color]=1;
        }
    }
    int k=0,max=0;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>max)
        {
            k=it->first;
            max=it->second;
        }
    }
    printf("%d\n",k);
	return 0;
}

