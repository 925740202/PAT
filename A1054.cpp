#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int main()
{
    int n,m,color;//�������к���ɫ��
    map<int,int>mp;//��map�����������ɫ��
    scanf("%d%d",&n,&m);//��������
    for(int i=0;i<m;i++)//ѭ��������ɫ��
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&color);
            if(mp.find(color)!=mp.end()) mp[color]++;//���ɫ�ų��ֹ�����Ӧ��ɫ�ż�ֵ+1
            else//û���ֹ���ɫ�ż�ֵ��Ӧ��Ϊ1
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

