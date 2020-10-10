#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long 

vector <ll> v;

int main()

{
	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	ll sqt = sqrt(y);
	
	ll cnt = 0, mns = 0;
	for(ll i = 1; i <= sqt; i++) {
		if(y % i != 0)
		     continue;
		ll d = y / i;
		if(i >= l && i <= r)
		    v.push_back(i);
        if(d != i && d >= l && d <= r)
            v.push_back(d);
	}

    for(ll i = 0; i < v.size(); i++) {
        for(ll j = 0; j < v.size(); j++) {
            if(__gcd(v[i], v[j]) != x)
                 continue;
            ll lcm = (v[i] * v[j]) / x;
            if(lcm != y)
               continue;
            cnt++;
        }
    }
	
	cout << cnt << endl;
	return 0;
}