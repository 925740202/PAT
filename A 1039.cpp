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
int getID(char name[])                       //hash ����������ת��Ϊ����
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
    scanf("%d%d",&n,&k);                  //�����ѯ����N�Ϳγ�����K
    for(int i=0;i<5;i++)
    {
        int course,x;
        scanf("%d%d",&course,&x);           //����γ̺ź�ѡ��γ�������
        for(int j=0;j<x;j++)
        {
            scanf("%s",name);               //����ѡ��ÿγ��˵�ID
            id=getID(name);              //����IDת��Ϊ����
            SelectCourse[id].push_back(course);    //��������ѡ�γ̷���SelectCourse����
        }
    }
   // vector<int> nid;
    for(int i=0;i<n;i++)
    {
       scanf("%s",name);                           //���뱻��ѯ�˵�ID
       id=getID(name);
       printf("%s %d",name,SelectCourse[id].size());
     //  nid.push_back(id);
       sort(SelectCourse[id].begin(),SelectCourse[id].end());    //���γ̺Ŵ�С��������
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

