#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=2010;
int n,k,numPerson=0;//the numbers of phone calls and threshold and the number of person
map<int,string> intTostring;//编号->姓名
map<string,int> stringToint;//姓名->编号
map<string,int> Gang;//head->人数
int G[maxn][maxn]={0};//存储图的邻接矩阵
int weight[maxn]={0};//存储每个人的从权值
bool vis[maxn]={false};//判断该结点是否被访问过
void DFS(int nowVisit,int& head,int& numMember,int& totvalue)
{
    numMember++;//当前帮派人员+1
    vis[nowVisit]=true;//标记当前结点已经访问
    if(weight[nowVisit]>weight[head])//如果当前访问结点的weight大于当前head的weight
    {
        head=nowVisit;//更新当前head
    }
    for(int i=0;i<numPerson;i++)//枚举所有人
    {
        if(G[nowVisit][i]>0)//该结点可以到达i结点
        {
            totvalue+=G[nowVisit][i];//更新当前帮派totvalue
            G[nowVisit][i]=G[i][nowVisit]=0;//删除当前边，防止回头
            if(vis[i]==false)//如果该结点未被访问过，递归访问该结点
            {
                DFS(i,head,numMember,totvalue);
            }
        }

    }
}
void DFStravel()//遍历整个图，找到所有符合条件得到帮派
{
    for(int i=0;i<numPerson;i++)//枚举所有人数
    {
        if(vis[i]==false)
        {
            int head=i,numMember=0,totvalue=0;
            DFS(i,head,numMember,totvalue);
            if(numMember>2&&totvalue>k)//如果帮派成员数大于2并且totvalue大于k，将其记录进Gang
            {
               Gang[intTostring[head]]=numMember;//将该帮派的人数计入head下
            }
        }

    }
}
int change(string str)//将字符串与编号一一对应
{
    if(stringToint.find(str)!=stringToint.end())//str可以找到，直接返回对应的数字
    {
        return stringToint[str];
    }
    else
    {
        stringToint[str]=numPerson;//最近输入的人对应编号为当前人数
        intTostring[numPerson]=str;//将编号与人名对应
        return numPerson++;//每增加一个人，图内总人数加1
    }
}
int main()
{
   // cin>>n>>k;
    scanf("%d%d",&n,&k);//输入总通话数，与threshol K
    string name1,name2;//人名类型为string
    int str1,str2,w;
    for(int i=0;i<n;i++)
    {
       cin>>name1>>name2;//输入字符串用cin
       /*************将人名转换成对应的编号*********/
       str1=change(name1);
       str2=change(name2);
       /*********************************************/
       scanf("%d",&w);//输入该次通话的时间
       /************通话时间赋给图中相应的边当作权值********/
       G[str1][str2]+=w;
       G[str2][str1]+=w;
       /************累加参与通话的人的weight**********/
       weight[str1]+=w;
       weight[str2]+=w;
    }
    DFStravel();
    printf("%d\n",Gang.size());//输出图内的帮派数
    map<string,int>::iterator it;//迭代器it
    for(it=Gang.begin();it!=Gang.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;//输出字符串用cout
    }
	return 0;
}

