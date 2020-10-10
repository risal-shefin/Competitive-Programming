#include<stdio.h>
#include<stdbool.h>
long long int B[100000005];
bool A[100000005];
int main()
{
    long long int X=100000000,i,j,p=2,q,Y;
    for(i=0; i<=X; i++)
    {
        A[i]=1;
    }
    for(i=2; i*i<=X; )
    {
        if(A[i] != 0)
        {
            for(j=i; (i*j) <= X; j++)
            {
                if(A[i*j]!=0)
                {
                    A[i*j]=0;
                }
            }
        }
        if(i==2)
        {
            i++;
        }
        else
        {
            i+=2;
        }
    }
    B[1]=2;
    for(i=3; i<=X; i+=2)
    {
        if(A[i]!=0)
        {
            B[p]=i;
            p++;
        }
    }
    scanf("%lld",&q);
    for(i=0; i<q; i++)
    {
        scanf("%lld",&Y);
        printf("%lld\n",B[Y]);
    }
    return 0;
}
