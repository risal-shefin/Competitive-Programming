#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n, h, w;
    cin >> n >> h >> w;
    int cnth = 0, cntw = 0, cnt = 0, rest = n;

    while(1) {

        if(rest >= h && cnth < 4) {
            rest -= h;
            cnth++;
        }

        if(rest >= w && cntw < 2) {
            rest -= w;
            cntw++;
        }

        if( (rest < h || cnth == 4) && (rest < w || cntw == 2) ) {
            rest = n;
            cnt++;
        }

        if(cnth == 4 && cntw == 2) {
            cout << cnt << endl;
            return 0;
        }
    }

    return 0;
}