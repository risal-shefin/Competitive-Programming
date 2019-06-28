#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    int ara[n + 5];
    for(int i = 1; i <= n; i++) {
        int in;
        scanf("%d", &in);
        ara[i] = in;
    }
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        int tmp = ara[i];
        int tmp2 = ara[tmp];
        //cout << i << "  " << tmp << "  " << tmp2 << endl;
        if(ara[tmp2] == i) {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        cout << "YES" <<endl;
    else
        cout << "NO" << endl;
    return 0;
}
