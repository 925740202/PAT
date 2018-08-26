#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int father[maxn];
int course[maxn]={0};
int n;
int isRoot[maxn]={0};
int findFather(int x)//找到结点的根节点
{
    int a=x;
    while(x!=father[x])
    {
        x=father[x];
    }
    while(a!=father[a])//路径压缩
    {
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
void Union(int a,int b)
{
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb)
    {
        father[fa]=fb;
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        isRoot[i]=false;
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    scanf("%d",&n);//输入总人数
    init(n);
    int k,h;
    for(int i=1;i<=n;i++)
    {
        scanf("%d:",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&h);
            if(course[h]==0)//该爱好为第一次
            {
                course[h]=i;
            }
            Union(i,findFather(course[h]));//将当前人归入该爱好的根节点
        }
    }

    for(int i=1;i<=n;i++)
    {
        isRoot[findFather(i)]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(isRoot[i]!=0)
        ans++;
    }
    sort(isRoot+1,isRoot+n+1,cmp);
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
    {
        printf("%d",isRoot[i]);
        if(i<ans)
        printf(" ");
    }
	return 0;
}

