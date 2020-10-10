#include <bits/stdc++.h>
using namespace std;

bool isPossible(int num)

{
    int lo = 1, hi = 10;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;

        int pw = 2, pw2;
        for(int i = 2; i <= mid; i++)
            pw *= 2;

        pw2 = pw / 2;

        int nm = (pw - 1) * pw2;

        if(nm == num)
            return 1;
        else if(nm > num)
            hi = mid - 1;
        else
            lo = mid + 1;

    }

    return 0;
}

int main()

{
    int n;
    scanf("%d", &n);
    int sqt = sqrt(n);

    int ans = INT_MIN;
    for(int i = 1; i <= sqt; i++) {
        if(n % i == 0) {
            int m = n / i;

            if(isPossible(m))
                ans = max(ans, m);
            if(isPossible(i))
                ans = max(ans, i);
        }
    }

    cout << ans << endl;
}