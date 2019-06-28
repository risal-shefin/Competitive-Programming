#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    int mx = INT_MIN;
    int pos1 = 1, pos2 = 1000000;
    int time1 = 0, time2 = 0;
    for(int i = 1; i <= n; i++) {
        int in;
        scanf("%d", &in);
        int tmp1 = abs(in - pos1);
        int tmp2 = abs(in - pos2);
        if(tmp1 < tmp2) {
            mx = max(mx, tmp1);
        }
        else {
            mx = max(mx, tmp2);
        }
    }
    cout << mx << endl;
    return 0;
}
