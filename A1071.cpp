#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
bool check(char c)//�ж��ַ��Ƿ�����[0,9] [A,Z] [a,z]���Ƿ�Ϊ��׼�ַ�
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
        string word;//Ѱ��ÿ��������Ҫ���¿�����ʱ����
        while(i<sen.length()&&check(sen[i])==true)//��ȡ���ʣ����ҽ���д��ĸ��ΪСд��ĸ
        {
            if(sen[i]<='Z'&&sen[i]>='A')
            {
                sen[i]+=32;//����д��ĸ��ΪСд��ĸ
            }
            word+=sen[i];
            i++;
        }
        if(word!="") //����mapѰ�Ҹõ��ʣ�������������+1��û������1
        {
            if(count.find(word)==count.end())count[word]=1;
            else count[word]++;
        }
        while(i<sen.length()&&check(sen[i])==false)//������Ǳ�׼�ַ��������ַ�
        {
            i++;
        }

    }
    string res;
    int max=0;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++)//����coutѰ�ҳ��ִ������ĵ���
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

