#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=40010;                    //���ѧ����
const int K=2510;                   //���γ���
char name[N][5];
vector<int>course[K];              //�洢ÿ�ſγ���ѡ����
bool cmp(int a,int b)                   //�ж������������ֵ��е��Ⱥ�˳��
{
    return strcmp(name[a],name[b])<0;
}
int main()
{
    int n,k,c,courseID;              //����ѧ�������γ�����ÿ����ѡ�γ������γ̺�
    scanf("%d%d",&n,&k);           //����ѧ���������Ϳγ�����
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",name[i],&c);     //�����i��ѧ����������ѡ�γ�����
        for(int j=0;j<c;j++)
        {
            scanf("%d",&courseID);         //ѭ�������i��ѧ����ѡ�γ̺�
            course[courseID].push_back(i);  //����i��ѧ��������ѡ�γ̺�����
        }
    }
    for(int i=1;i<=k;i++)
    {
        printf("%d %d\n",i,course[i].size());           //����γ̺ź͸ÿγ���ѡѧ����
        sort(course[i].begin(),course[i].end(),cmp);    //�Կγ�i�ڵ�ѧ��������������
        for(int j=0;j<course[i].size();j++)            //ѭ�����i�γ���ѧ������
        {
            printf("%s\n",name[course[i][j]]);
        }
    }
   	return 0;
}

