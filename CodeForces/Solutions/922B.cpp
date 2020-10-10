#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long

bool check[2502][2502];

int main()

{
    int n;
    cin >> n;
    int ara[3];
    map <string, bool> m;

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x = i, y = j;

            int z = x ^ y;

            if(x + y <= z)
                continue;
            if(x + z <= y)
                continue;
            if(y + z <= x)
                continue;
            if(z <= n) {

                ara[0] = x;
                ara[1] = y;
                ara[2] = z;
                sort(ara, ara + 3);

                if(check[ ara[0] ][ ara[1] ] == 1)
                    continue;
                check[ ara[0] ][ ara[1] ] = 1;
                cnt++;

                //cout << x << "  " << y << "  " << z << endl;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}