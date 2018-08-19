#include<iostream>
#include<string>
using namespace std;
int n;  //精确度位数
string deal(string s,int &e)
{
    int k=0;//s的下标
    while(s.length()>0&&s[0]=='0')//去掉s中的先导0
    {
        s.erase(s.begin());
    }
    if(s[0]=='.')//说明是小数
    {
      s.erase(s.begin());//删除小数点
      while(s.length()>0&&s[0]=='0')//继续删除小数点后的0
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
    while(num<n)//精度没达到n
    {
        if(k<s.length())res+=s[k++];//只要还有数就加到res后面
        else res+='0';//没有数加0
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

