#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d", &n);
    int mn1 = INT_MAX, mn2 = INT_MIN;
    for(int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mn1 = min(mn1, b);
        mn2 = max(mn2, a);
    }
    //cout << "   " << mn1 << "  " << mn2 << endl;
    scanf("%d", &m);
    int mn3 = INT_MIN, mn4 = INT_MAX;
    for(int j = 1; j <= m; j++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mn3 = max(mn3, a);
        mn4 = min(mn4, b);
    }
    //cout << "   " << mn3 << "  " << mn4 << endl;
    int ans1 = 0, ans2 = 0;
    if(mn3 > mn1) {
        ans1 = mn3 - mn1;
    }
    if(mn2 > mn4)
        ans2 = mn2 - mn4;
    cout << max(ans1, ans2) << endl;
    return 0;
}
