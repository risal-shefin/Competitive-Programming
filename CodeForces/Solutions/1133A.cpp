#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll h1, m1, h2, m2;
    scanf("%lld:%lld", &h1, &m1);
    scanf("%lld:%lld", &h2, &m2);
    ll t1 = h1 * 60 + m1;
    ll t2 = h2 * 60 + m2;

    ll dif = t2 - t1;
    ll mid = dif / 2;

    ll ansh = h1 + (mid / 60);
    mid %= 60;
    ll ansm = m1 + mid;
    if(ansm >= 60) {
        ansh++;
        ansm %= 60;
    }

    if(ansh < 10)
        cout << "0";
    cout << ansh << ":";
    if(ansm < 10)
        cout << "0";
    cout << ansm << endl;

    return 0;
}