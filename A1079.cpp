#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
struct node//结点的结构体形式
{
    double data;
    vector<int> child;
}Node[maxn];
int n;//结点总个数
double p,r,ans=0;//商品价格与加价比率
void DFS(int index,int depth)
{
    if(Node[index].child.size()==0)
    {
        ans+=Node[index].data*pow(1+r,depth);//求此叶结点处的价格，并累加
        return;
    }
    for(int i=0;i<Node[index].child.size();i++)
    {
        DFS(Node[index].child[i],depth+1);//递归访问子结点
    }

}
int main()
{
    int k,child;
    scanf("%d%lf%lf",&n,&p,&r);//从键盘输入结点的个数，商品的价格，加价率
    r/=100;//将r白分化
    //int numc;//i结点的孩子数
   // int c;//孩子结点
    for(int i=0;i<n;i++)//输入树的数据
    {
        scanf("%d",&k);
        if(k==0)//为叶结点
        {
             scanf("%lf",&Node[i].data);

        }
        else//有孩子结点
        {
            //int num;//叶结点的商品数量

            for(int j=0;j<k;j++)
            {
                scanf("%d",&child);
                Node[i].child.push_back(child);//将孩子结点压进vector
            }
            //Node[i].data=num;
        }
    }
    DFS(0,0);
    printf("%.1lf\n",p*ans);//输出最终的结果
	return 0;
}

