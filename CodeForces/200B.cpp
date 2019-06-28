#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0, in;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &in);
        sum += in;
    }
    printf("%f\n", (double)( (sum * 1.0) / (n * 1.0) ) );
}
