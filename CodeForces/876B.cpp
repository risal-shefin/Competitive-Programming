#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    int ara[n + 5];
    vector <int> ans[m + 5];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        int rem = ara[i] % m;
        ans[rem].push_back(ara[i]);
    }
    bool checker = 0;
    int ansi;
    for(int i = 0; i <= m; i++) {
        if(ans[i].size() >= k) {
            checker = 1;
            ansi = i;
            break;
        }
    }
    if(checker == 1) {
        printf("Yes\n");
        for(int i = 0; i < k; i++) {
            printf("%d", ans[ansi][i]);
            if(i != k - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    else
        printf("No\n");
    return 0;
}
