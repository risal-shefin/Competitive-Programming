#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

int main()

{
    ll n, a, b;
    cin >> n >> a >> b;

    ll sega, segb;
    ll tot = 0, tmp = n;
    while(tmp != 1) {
        tot++;
        tmp /= 2;
    }

    if(a % 2 == 0) {
        sega = a / 2;
    }
    else {
        sega = a / 2 + 1;
    }

    if(b % 2 == 0) {
        segb = b / 2;
    }
    else {
        segb = b / 2 + 1;
    }

    ll level = 1;
    if(sega == segb)
    {
        if(level == tot)
        {
            cout << "Final!" << endl;
            return 0;
        }
        else
        {
            cout << level << endl;
            return 0;
        }
    }
    while(1) {
        level++;

        if(sega % 2 == 0)
        {
            sega = sega / 2;
        }
        else {
            sega = sega / 2 + 1;
        }

        if(segb % 2 == 0)
        {
            segb = segb / 2;
        }
        else {
            segb = segb / 2 + 1;
        }

        //cout << sega << " " << segb << endl;
        if(sega == segb) {
            if(level == tot) {
                cout << "Final!" << endl;
                return 0;
            }
            else {
                cout << level << endl;
                return 0;
            }
        }
    }

    return 0;
}