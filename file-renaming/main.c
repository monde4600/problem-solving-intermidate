#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int cmp(void *a,void *b)
{
    return *(int*)a-*(int*)b;
}*/
#define MOD 1000000007
/*int renameFile(char* newName,char* oldName)
{
    long old_len=strlen(oldName);
    long new_len=strlen(newName);

    long temp_arr[old_len+1];
    long OCC_arr[old_len+1];
    for(long i=0;i<old_len+1;i++)  temp_arr[i]=1;

    for(long i=1;i<new_len+1;i++)
    {
        for(long z=0;z<old_len+1;z++)    OCC_arr[z]=0;
        for(long j=i;j<old_len+1;j++)
        {
            OCC_arr[j]=OCC_arr[j-1];
            if(newName[i-1]==oldName[j-1])    OCC_arr[j]+=temp_arr[j-1];

        }
        for(long k=0;k<old_len+1;k++)
            temp_arr[k]=OCC_arr[k];


    }
    return OCC_arr[old_len] % MOD;
}
*/

int renameFile(char* newName,char* oldName)
{
    long old_l=strlen(oldName);
    long new_l=strlen(newName);

    long temp_arr[old_l+1],OCC_arr[old_l+1];

    for(long i=0;i<old_l+1;i++)  temp_arr[i]=1;

    for(long i=1;i<new_l+1;i++)
    {
        for(long c=0;c<old_l+1;c++) OCC_arr[c]=0;

        for(long j=i;j<old_l+1;j++)
        {
            OCC_arr[j] = OCC_arr[j-1];
            if(oldName[j-1]==newName[i-1])  OCC_arr[j]+=temp_arr[j-1];
         //   printf("%d\n",OCC_t[j]);
        }

        for(int g=0;g<=old_l;g++)   temp_arr[g]=OCC_arr[g];
    }
    return OCC_arr[old_l]%MOD;
}
int main()
{
    /*int arr[]={1,79,7,65,5,7};
    qsort(arr,6,sizeof(int),cmp);
    for(int i= 0; i<6;i++)
    printf("%d\n",arr[i]);
    printf("%d",9%10);*/
    printf("%d",renameFile("ab","ababa"));
    return 0;
}
