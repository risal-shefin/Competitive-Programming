#include <bits/stdc++.h>
using namespace std;

int ara[100009];

int main()

{
    int n, tmp = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }

    bool mark = 0;
    sort(ara, ara + n);
    for(int i = n - 1; i >= 0; i--) {
        int cnt = lower_bound(ara, ara + n, ara[i]) - ara;
        if( (n - cnt - 1) % 2 == 0) {
            mark = 1;
            break;
        }
    }
    if(mark == 1)
        cout << "Conan" << endl;
    else
        cout << "Agasa" << endl;

    return 0;
}