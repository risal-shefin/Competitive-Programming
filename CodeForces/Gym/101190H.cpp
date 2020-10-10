#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lo -32768
#define hi 32767
#define con 32768

ll line[65540];

int main()

{
    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    string s;
    while(getline(cin, s)) {
        bool nd = 0;
        for(ll i = 0; i < s.length(); i++)
            if(s[i] == '&') {
                nd = 1;
                break;
            }

        stringstream ss(s);
        string tmp;
        if(nd) {
            ll start, stop;
            ss >> tmp >> tmp >> start >> tmp >> tmp >> tmp >> stop;

            for(ll i = start; i <= stop; i++)
                line[i+con] = 1;
//            if(start <= stop) {
//                line[start + con]++;
//                line[stop + 1 + con]--;
//            }
        }
        else {
            string sign;
            ll rng;
            ss >> tmp >> sign >> rng;

            if(sign == ">=")
                for(ll i = rng; i <= hi; i++)
                    line[i+con] = 1;
//                line[rng + con]++, line[hi + 1 + con]--;
            else
                for(ll i = rng; i >= lo; i--)
                    line[i+con] = 1;
//                line[lo + con]++, line[rng + 1 + con]--;
        }
    }

//    for(ll i = 1; i <= hi + con; i++)
//        line[i] += line[i - 1];

    bool one = 1, zero = 1;
    for(ll i = 0; i <= hi + con; i++) {
        if(line[i] == 0)
            one = 0;
        if(line[i] > 0)
            zero = 0;
    }

    if(one) {
        cout << "true" << endl;
        return 0;
    }
    if(zero) {
        cout << "false" << endl;
        return 0;
    }

    ll start = -1, chk = 0;
    for(ll i = 0; i <= hi + con; i++) {
        if(line[i] > 0 && start == -1)
            start = i;
        if(line[i] == 0 && start != -1) {

            if(chk)
                cout << " ||" << endl;
            if(start - con == lo) {
                cout << "x <= " << i - 1 - con;
            }
            else {
                cout << "x >= " << start - con << " && x <= " <<  i - 1 - con;
            }

            chk = 1;
            start = -1;
        }

        if(line[i] > 0 && i - con == hi) {
            if(chk)
                cout << " ||" << endl;
            cout << "x >= " << start - con;
        }
    }
    cout << endl;

    return 0;
}