#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)<(b)?(a):(b))
long maxSubarrayValue(int n, int* arr)
{
   long max=0;
   long currmax=arr[0];
   long currmin = arr[0];
   long maxsofr= arr[0];
   long minsofar=arr[0];
   for(int i=1;i<n;i+=2)   arr[i]=-arr[i];

   for(int i=1;i<n;i++)
   {
       currmax= MAX(arr[i],arr[i]+currmax);
       maxsofr = MAX(currmax,maxsofr);

       if(currmin>0)    currmin=arr[i];
       else     currmin += arr[i];

       minsofar = MIN(currmin,minsofar);
   }

   max = MAX(abs(minsofar),abs(maxsofr));

   return max*max;
}

/*long maxSubarrayValue(int n, int* arr)
{
     long MAX = 0;

    //negate odd indexed elements
    for(int i=1;i<n;i+=2)
    {
        arr[i] = 0 - arr[i];
    }

    long maxSoFar = arr[0];
    long currMax = arr[0];
    long currMin = arr[0];
    long minSoFar = arr[0];

    for (int i = 1; i < n; i++)
    {
        currMax = max(arr[i] , currMax + arr[i]);
        printf("%d,,",currMax);
        maxSoFar = max(maxSoFar , currMax);
        if (currMin > 0)
            currMin = arr[i];
        else
            currMin += arr[i];
        printf("%d,,",currMin);
        minSoFar = min(minSoFar , currMin);
    }
    MAX =  abs(maxSoFar) > abs(minSoFar) ? abs(maxSoFar) : abs(minSoFar);

    return MAX * MAX;
}*/

int main()
{
    long x[5]= {1,-1,1,-1,1};
    printf("%d\n",maxSubarrayValue(5,x));
    return 0;
}
