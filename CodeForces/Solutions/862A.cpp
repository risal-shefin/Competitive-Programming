#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n, x;
    cin >> n >> x;
    int ans = x;
    int in;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &in);
        if(in < x)
            ans--;
        else if(in == x)
            ans++;
    }
    cout << ans << endl;

    return 0;
}