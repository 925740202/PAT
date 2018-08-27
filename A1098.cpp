#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int n;
int sequence[maxn],halfsequence[maxn],changed[maxn];//��Ŵ�������������Ͳ���������������
void downAdjust(int low,int high)
{
    int i=low,j=2*i;
    while(j<=high)
    {
        if(j+1<=high&&halfsequence[j]<halfsequence[j+1])
        {
            j=j+1;
        }
        if(halfsequence[j]>halfsequence[i])
        {
            swap(halfsequence[j],halfsequence[i]);
            i=j;
            j=j*2;
        }else
        {
            break;
        }
    }
}
bool isSame(int a[],int b[])
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])return false;
    }
    return true;
}
void print(int a[])
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        printf("%d",halfsequence[i]);
        num++;
        if(num<n)
        {
            printf(" ");
        }
    }
}
/**************�ж��Ƿ�Ϊ��������*******************/
bool insertSort()
{
    bool flag=false;
    for(int i=2;i<=n;i++)
    {
        if(i!=2&&isSame(halfsequence,changed))//�ж���������е������Ƿ����
        {
            flag=true;
        }
        sort(halfsequence,halfsequence+i+1);//ǰi�������в�������
        if(flag==true)
        return true;
    }
    return false;
}
/**************�ж��Ƿ�Ϊ������*************************/
void heapSort()
{
    bool flag=false;
    for(int i=n/2;i>=1;i--)//����
    {
        downAdjust(i,n);
    }
    for(int i=n;i>1;i--)
    {
        if(i!=2&&isSame(halfsequence,changed))//�ж���������е������Ƿ��������������
        {
            flag=true;
        }
        swap(halfsequence[i],halfsequence[1]);
        downAdjust(1,i-1);
        if(flag==true)
        {
            print(halfsequence);
            return;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)//�������������
    {
        scanf("%d",&sequence[i]);
        halfsequence[i]=sequence[i];
    }
    for(int i=1;i<=n;i++)//���벿����������
    {
        scanf("%d",&changed[i]);
    }
    if(insertSort())
    {
        printf("Insertion Sort\n");
        print(halfsequence);
    }
    else
    {
        printf("Heap Sort\n");
        for(int i=1;i<=n;i++)
        {
            halfsequence[i]=sequence[i];
        }
        heapSort();
    }
	return 0;
}

