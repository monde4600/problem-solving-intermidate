#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *x,const void *y )
{

    return *(const int*)x- *(const int*)y;
}
int maxPairs(int skillLevel_count, int* skillLevel, int minDiff)
{
    qsort(skillLevel,skillLevel_count,sizeof(int),cmp);
    int l=0;
    int r= skillLevel_count/2 +1;
    while(r-l>1)
    {
        int m=(r+l)/2;
        int good=1;
        for(int i=0;i<m;i++)    good&=(skillLevel[skillLevel_count-m+i]-skillLevel[i]>=minDiff);

        if(good) l=m;
        else r=m;
    }
    return l;
}


int main()
{
    int x[]={3,4,5,2,1,1};
    printf("%d",maxPairs(6,x,3));
    return 0;
}
