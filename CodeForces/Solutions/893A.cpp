#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin >> n;
    map <int, bool> m;
    m[1] = 1, m[2] = 1, m[3] = 0;
    bool check = 1;
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if(m[a] == 0)
            check = 0;

        for(int i = 1; i <= 3; i++) {
            if(m[i] == 0)
                m[i] = 1;
            else
                m[i] = 0;
        }
        m[a] = 1;

    }

    if(check == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}