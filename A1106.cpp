#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
const int maxn=100010;
using namespace std;
vector<int> Node[maxn];
int n;
double price,rate;
/******注意mindepth初始值应该不小于树的深度**********/
int mindepth=maxn,num=0;//深度最低的子树和最低子树的个数     ******注意mindepth初始值应该不小于树的深度**********
bool notRoot[maxn]={false};//bool型数组用来判断当前结点是否为树根
void DFS(int index,int depth)
{

    if(Node[index].size()==0)//到达叶结点
    {
        if(mindepth>depth)//如果当前最浅深度大于当前深度，更新最浅深度
        {
        mindepth=depth;
        num=1;              //重置最浅深度叶结点的个数
        }
        else if(mindepth==depth)//深度等于最大深度
        {
        num++;                //叶结点个数加一
        }
        return;
    }
    for(int i=0;i<Node[index].size();i++)
    {
        DFS(Node[index][i],depth+1);//递归访问index结点的孩子结点
    }

}
int findRoot()
{
    //int root;
   for(int i=0;i<n;i++)
   {
       if(notRoot[i]==false)
       {
          // root=i;
          return i;
       }
   }
}
int main()
{
    int child,k;//k为每个结点孩子的数量
    scanf("%d%lf%lf",&n,&price,&rate);//输入结点总数，价格price，加价率rate
    rate/=100;
    for(int i=0;i<n;i++)//输入信息，建立商品流通树
    {
        scanf("%d",&k);
        if(k!=0)
        {
            for(int j=0;j<k;j++)//结点的孩子数不为0时，依次输入孩子
            {
                scanf("%d",&child);
                Node[i].push_back(child);
                notRoot[child]=true;//child节点不是根节点，它有父亲结点
            }
        }
    }
    DFS(findRoot(),0);//DFS入口
   // printf("%.4lf",pow(1+rate,mindepth));
    printf("%.4lf %d\n",price*pow(1+rate,mindepth),num);//输出结果
	return 0;
}

