#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=40010;                    //最大学生数
const int K=2510;                   //最大课程数
char name[N][5];
vector<int>course[K];              //存储每门课程所选的人
bool cmp(int a,int b)                   //判断两个名字在字典中的先后顺序
{
    return strcmp(name[a],name[b])<0;
}
int main()
{
    int n,k,c,courseID;              //定义学生数，课程数，每人所选课程数，课程号
    scanf("%d%d",&n,&k);           //输入学生总人数和课程总数
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",name[i],&c);     //输入第i个学生姓名及所选课程总数
        for(int j=0;j<c;j++)
        {
            scanf("%d",&courseID);         //循环输入第i个学生所选课程号
            course[courseID].push_back(i);  //将第i个学生存入所选课程号容器
        }
    }
    for(int i=1;i<=k;i++)
    {
        printf("%d %d\n",i,course[i].size());           //输出课程号和该课程所选学生数
        sort(course[i].begin(),course[i].end(),cmp);    //对课程i内的学生姓名进行排序
        for(int j=0;j<course[i].size();j++)            //循环输出i课程内学生姓名
        {
            printf("%s\n",name[course[i][j]]);
        }
    }
   	return 0;
}

