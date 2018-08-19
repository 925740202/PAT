#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
using namespace std;
map<string,set<int> >mpTitle,mpAuthor,mpKey,mpPub,mpYear;
void query(map<string,set<int> > &mp,string &str)
{
    if(mp.find(str)==mp.end())printf("Not Found\n");
    for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++)
    {
        printf("%07d\n",*it);
    }
}
int main()
{
    int n,ID;
    string title,author,key,pub,year;
    scanf("%d",&n);//���������Ŀ
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ID);//���뱾���ID
        char c=getchar();//���ջس��ַ�
        getline(cin,title);//��������
        mpTitle[title].insert(ID);
        getline(cin,author);//��������
        mpAuthor[author].insert(ID);
        while(cin>>key)//����ؼ���
        {
            mpKey[key].insert(ID);
            c=getchar();
            if(c=='\n')break;
        }
        getline(cin,pub);//���������
        mpPub[pub].insert(ID);
        getline(cin,year);//�������
        mpYear[year].insert(ID);
    }
    int m,type;//��ѯ��������
    scanf("%d",&m);
    string temp;
    for(int j=0;j<m;j++)
    {
        scanf("%d:",&type);
        getline(cin,temp);
        //cout<<type<<":"<<temp<<endl;
        printf("%d:%s\n",type,temp);
        if(type==1)query(mpTitle,temp);
        if(type==2)query(mpAuthor,temp);
        if(type==3)query(mpKey,temp);
        if(type==4)query(mpPub,temp);
        else
        query(mpYear,temp);
    }
	return 0;
}

