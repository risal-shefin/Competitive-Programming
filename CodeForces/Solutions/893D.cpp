#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n, d;
    int sum = 0;
    int checker = 1, cnt = 0, cnt2 = 0;
    scanf("%d %d", &n, &d);
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        sum += t;
        if(sum > d)
            checker = 0;

        if(t == 0) {
            if(sum < 0) {
                cnt++;
            }

            sum = 0;
        }
    }

    if(checker == 1)
        cout << cnt << endl;
    else
        cout << -1 << endl;

    return 0;
}