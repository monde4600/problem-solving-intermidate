#include <stdio.h>
#include <stdlib.h>

int cmp(void *a,void *b)
{
    return *(int*)a-*(int*)b;
}

int minOperations(int arr_count, int* arr, int threshold, int d)
{
    qsort(arr,arr_count,sizeof(int),cmp);
    int DP[200001][2]={0};

    int mino=(unsigned int)~0/2 ;
    printf("..%d..\n",mino);
    for(int i=0;i<arr_count;i++)
    {
        int steps=0;
        while(1)
        {
            DP[arr[i]][0]++;
            DP[arr[i]][1]+=steps;
            if(DP[arr[i]][0]>=threshold)
                mino = (mino>=DP[arr[i]][1])?DP[arr[i]][1]:mino;
            if(!arr[i]) break;

            arr[i]/=d;
            steps++;
        }


    }
    /*for(int i=0;i<arr_count;i++)
        printf("%d,,",DP[0][1]);*/
//printf("\n");
    return mino;
}

int main()
{
    int arr[]= {64,30,25,33};
    printf("%d",minOperations(4,arr,2,2));

    return 0;
}
