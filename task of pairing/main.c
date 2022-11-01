#include <stdio.h>
#include <stdlib.h>
long taskOfPairing(int freq_count, long* freq) {

    long maxtot=0;
    long max[100000] = {0} ;

    int i=0,j=0;
    while(i<freq_count)
    {
        while(freq[i] && i<freq_count)
        {
            max[j]+=freq[i++];
        }
        max[j]/=2;
        maxtot+=max[j];
        i++;
        j++;
    }
    return maxtot;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
