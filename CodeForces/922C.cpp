#include <bits/stdc++.h>
using namespace std;
bool check[25];
#define ll long long
int main() {
	
    ll n, k;
    cin >> n >> k;
    ll p = min(k, 23LL);
    for(ll i = 1; i <= p; i++) {
         ll tmp = n % i;
         if(check[tmp]) {
            cout << "No" << endl;
            return 0;
         }
         check[tmp] = 1;
    }
    cout << "Yes" << endl;
	return 0;
}
