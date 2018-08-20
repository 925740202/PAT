#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
const int maxn=100010;
using namespace std;
int n;
double p,r;//商品单价和加价率,最高价格
vector<int> child[maxn];//存放每个结点的孩子结点
int num=0,maxdepth=0;
void DFS(int index,int depth)
{
    if(child[index].size()==0)//达到叶结点
    {
        if(depth>maxdepth)
        {
           maxdepth=depth;//更新当前最大深度
           num=1;            //最大深度结点置为1
        }
        else if(depth==maxdepth)//找到另一个相同深度的结点
        {
        num++;
        }
        return;
    }
    for(int i=0;i<child[index].size();i++)
    {
        DFS(child[index][i],depth+1);//递归查找每个孩子结点
    }
}
int main()
{
    scanf("%d%lf%lf",&n,&p,&r);
    r/=100;
    int parent,root;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&parent);
        if(parent==-1)//找到根节点
        {
            root=i;
        }
        else//将结点的孩子结点存入
        {
            child[parent].push_back(i);
        }
    }
    DFS(root,0);//DFS入口
    printf("%.2lf %d\n",p*pow(1+r,maxdepth),num);
	return 0;
}

