#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
bool check(char c)//判断字符是否属于[0,9] [A,Z] [a,z]，是否为标准字符
{
    if(c<='9'&&c>='0')return true;
    if(c<='Z'&&c>='A')return true;
    if(c<='z'&&c>='a')return true;
    return false;
}
int main()
{
    string sen;
    map<string,int>count;
    getline(cin,sen);
    int i=0;
    while(i<sen.length())
    {
        string word;//寻找每个单词需要重新开辟临时变量
        while(i<sen.length()&&check(sen[i])==true)//提取单词，并且将大写字母换为小写字母
        {
            if(sen[i]<='Z'&&sen[i]>='A')
            {
                sen[i]+=32;//将大写字母换为小写字母
            }
            word+=sen[i];
            i++;
        }
        if(word!="") //遍历map寻找该单词，如果已有则次数+1，没有则置1
        {
            if(count.find(word)==count.end())count[word]=1;
            else count[word]++;
        }
        while(i<sen.length()&&check(sen[i])==false)//如果不是标准字符跳过此字符
        {
            i++;
        }

    }
    string res;
    int max=0;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++)//遍历cout寻找出现次数最大的单词
    {
        if(max<it->second)
        {
            max=it->second;
            res=it->first;
        }
    }
    cout<<res<<" "<<max<<endl;
    //printf("%s %d",res,max);
	return 0;
}

