#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=2010;
int n,k,numPerson=0;//the numbers of phone calls and threshold and the number of person
map<int,string> intTostring;//���->����
map<string,int> stringToint;//����->���
map<string,int> Gang;//head->����
int G[maxn][maxn]={0};//�洢ͼ���ڽӾ���
int weight[maxn]={0};//�洢ÿ���˵Ĵ�Ȩֵ
bool vis[maxn]={false};//�жϸý���Ƿ񱻷��ʹ�
void DFS(int nowVisit,int& head,int& numMember,int& totvalue)
{
    numMember++;//��ǰ������Ա+1
    vis[nowVisit]=true;//��ǵ�ǰ����Ѿ�����
    if(weight[nowVisit]>weight[head])//�����ǰ���ʽ���weight���ڵ�ǰhead��weight
    {
        head=nowVisit;//���µ�ǰhead
    }
    for(int i=0;i<numPerson;i++)//ö��������
    {
        if(G[nowVisit][i]>0)//�ý����Ե���i���
        {
            totvalue+=G[nowVisit][i];//���µ�ǰ����totvalue
            G[nowVisit][i]=G[i][nowVisit]=0;//ɾ����ǰ�ߣ���ֹ��ͷ
            if(vis[i]==false)//����ý��δ�����ʹ����ݹ���ʸý��
            {
                DFS(i,head,numMember,totvalue);
            }
        }

    }
}
void DFStravel()//��������ͼ���ҵ����з��������õ�����
{
    for(int i=0;i<numPerson;i++)//ö����������
    {
        if(vis[i]==false)
        {
            int head=i,numMember=0,totvalue=0;
            DFS(i,head,numMember,totvalue);
            if(numMember>2&&totvalue>k)//������ɳ�Ա������2����totvalue����k�������¼��Gang
            {
               Gang[intTostring[head]]=numMember;//���ð��ɵ���������head��
            }
        }

    }
}
int change(string str)//���ַ�������һһ��Ӧ
{
    if(stringToint.find(str)!=stringToint.end())//str�����ҵ���ֱ�ӷ��ض�Ӧ������
    {
        return stringToint[str];
    }
    else
    {
        stringToint[str]=numPerson;//���������˶�Ӧ���Ϊ��ǰ����
        intTostring[numPerson]=str;//�������������Ӧ
        return numPerson++;//ÿ����һ���ˣ�ͼ����������1
    }
}
int main()
{
   // cin>>n>>k;
    scanf("%d%d",&n,&k);//������ͨ��������threshol K
    string name1,name2;//��������Ϊstring
    int str1,str2,w;
    for(int i=0;i<n;i++)
    {
       cin>>name1>>name2;//�����ַ�����cin
       /*************������ת���ɶ�Ӧ�ı��*********/
       str1=change(name1);
       str2=change(name2);
       /*********************************************/
       scanf("%d",&w);//����ô�ͨ����ʱ��
       /************ͨ��ʱ�丳��ͼ����Ӧ�ıߵ���Ȩֵ********/
       G[str1][str2]+=w;
       G[str2][str1]+=w;
       /************�ۼӲ���ͨ�����˵�weight**********/
       weight[str1]+=w;
       weight[str2]+=w;
    }
    DFStravel();
    printf("%d\n",Gang.size());//���ͼ�ڵİ�����
    map<string,int>::iterator it;//������it
    for(it=Gang.begin();it!=Gang.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;//����ַ�����cout
    }
	return 0;
}

