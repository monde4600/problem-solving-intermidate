#include <stdio.h>
#include <stdlib.h>
int maxElement(int n, int maxSum, int k)
{
    int l=k;
    int r=k;
    int maxright= n-1;
    int count = 1;
    if(n == 1)    return maxSum;
    while(n<=maxSum && (l>0 || r<maxright))
    {
        n+=r-l+1;
        if(l>0)l--;
        if(r<maxright)r++;
        count++;
    }
    if(n<maxSum)    count += (maxSum-n)/(r-l+1)+1;
    return count-1;
}

/*int maxElement(int n, int maxSum, int k)
{
    if(n==1) return maxSum;
    int right =k;
    int left =k;
    int count = 1;
    int limitRight = n-1;

    while(n <= maxSum && (left > 0 || right < limitRight)){

        n+= right - left +1; if(left>0) left--; if(right < limitRight) right++; count++;}

        if(n<maxSum) count += (maxSum-n)/(right - left +1) +1;

        return count-1;

}
*/
int main()
{
    printf("%d\n",maxElement(3,6,1));
    return 0;
}
