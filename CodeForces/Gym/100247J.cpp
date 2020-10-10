#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = -1, k = -1, a, b;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        if(k < a && ans < b)
            ans = b;
        k = max(k, a);
    }
    printf("%d\n", ans);
}