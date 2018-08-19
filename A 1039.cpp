#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N=40000;
const int M=26*26*26*10+1;
vector<int> SelectCourse[M];
int getID(char name[])                       //hash 函数将名字转换为整数
{
    int id=0;
    for(int i=0;i<3;i++)
    {
        id=id*26+(name[i]-'A');
    }
    id=id*10+(name[3]-'0');
    return id;
}
int main()
{
    int n,k;
    char name[5];
    int id;
    scanf("%d%d",&n,&k);                  //输入查询人数N和课程总数K
    for(int i=0;i<5;i++)
    {
        int course,x;
        scanf("%d%d",&course,&x);           //输入课程号和选择课程总人数
        for(int j=0;j<x;j++)
        {
            scanf("%s",name);               //输入选择该课程人的ID
            id=getID(name);              //将其ID转换为整数
            SelectCourse[id].push_back(course);    //将该人所选课程放入SelectCourse容器
        }
    }
   // vector<int> nid;
    for(int i=0;i<n;i++)
    {
       scanf("%s",name);                           //输入被查询人的ID
       id=getID(name);
       printf("%s %d",name,SelectCourse[id].size());
     //  nid.push_back(id);
       sort(SelectCourse[id].begin(),SelectCourse[id].end());    //将课程号从小到大排序
       for(int j=0;j<SelectCourse[id].size();j++)
       {
           printf(" %d",SelectCourse[id][j]);
       }
       printf("\n");
    }

    /*for(vector<int>::iterator it=nid.begin();it!=nid.end();it++)
    {
        printf("%s %d",)
    }*/
	return 0;
}

