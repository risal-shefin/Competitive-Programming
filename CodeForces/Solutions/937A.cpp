#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

int main()

{
    int n;
    cin >> n;
    ll cnt = 0;
    unordered_map <int, bool> mark;
    for(int i = 0; i < n; i++) {
        int in;
        cin >> in;
        if(mark[in] == 0&& in > 0) {
            cnt++;
            mark[in] = 1;
        }
    }

    cout << cnt << endl;

    return 0;
}