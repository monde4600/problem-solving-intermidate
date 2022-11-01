#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void swap(int *x,int *y)
{
    int tem=*x;
    *x=*y;
    *y=tem;
}

int sortedSum(int a_count, int* a)
{
    long long ans=0,m=1e9+7;
    for(int i=0;i<a_count;i++)
    {

        int j=i;
        while(j>0 && a[j-1]>a[j])
        {
            swap(&a[j],&a[j-1]);
            j--;
        }
        for(j=0;j<=i;j++)
        {
            ans=(ans+a[j]*(j+1))%m;
        }
    }
    return ans%m;
}
int main()
{
    int x[]={9,5,8};
    printf("%d\n",sortedSum(3, x));
    return 0;
}
