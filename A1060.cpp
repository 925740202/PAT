#include<iostream>
#include<string>
using namespace std;
int n;  //��ȷ��λ��
string deal(string s,int &e)
{
    int k=0;//s���±�
    while(s.length()>0&&s[0]=='0')//ȥ��s�е��ȵ�0
    {
        s.erase(s.begin());
    }
    if(s[0]=='.')//˵����С��
    {
      s.erase(s.begin());//ɾ��С����
      while(s.length()>0&&s[0]=='0')//����ɾ��С������0
      {
          s.erase(s.begin());
          e--;
      }
    }
    else
    {
        while(k<s.length()&&s[k]!='.')
        {
            k++;
            e++;
        }
    }
    if(k<s.length())
    {
        s.erase(s.begin()+k);
    }
    if(s.length()==0)e=0;
    int num=0;
    k=0;
    string res;
    while(num<n)//����û�ﵽn
    {
        if(k<s.length())res+=s[k++];//ֻҪ�������ͼӵ�res����
        else res+='0';//û������0
        num++;
    }
    return res;
}
int main()
{
   string s1,s2,s3,s4;
   cin>>n>>s1>>s2;
   int e1=0,e2=0;
   s3=deal(s1,e1);
   s4=deal(s2,e2);
   if(s3==s4&&e1==e2)cout<<"YES 0."<<s3<<"*10^"<<e1;
   else cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2;
	return 0;
}

