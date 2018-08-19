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
    scanf("%d",&n);//输入书的数目
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ID);//输入本书的ID
        char c=getchar();//接收回车字符
        getline(cin,title);//输入书名
        mpTitle[title].insert(ID);
        getline(cin,author);//输入作者
        mpAuthor[author].insert(ID);
        while(cin>>key)//输入关键字
        {
            mpKey[key].insert(ID);
            c=getchar();
            if(c=='\n')break;
        }
        getline(cin,pub);//输入出版社
        mpPub[pub].insert(ID);
        getline(cin,year);//输入年份
        mpYear[year].insert(ID);
    }
    int m,type;//查询条件次数
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

