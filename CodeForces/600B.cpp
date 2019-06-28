#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int ara1[a + 5], ara2[b + 5];
    for(int i = 0; i < a; i++)
        scanf("%d", &ara1[i]);
    sort(ara1, ara1 + a);
    for(int j = 0; j < b; j++) {
        scanf("%d", &ara2[j]);
        printf("%d", upper_bound(ara1, ara1 + a, ara2[j]) - ara1);
        if(j != b - 1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
