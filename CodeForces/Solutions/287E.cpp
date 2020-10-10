#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 50)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz =1e6 + 10;
ll ara[sz];
bool close[sz];

int main()
{
	ll n; sl(n);
	for1(i,n) sl(ara[i]);
	
	ll m; sl(m);
	for1(i, m) {
		ll pos; sl(pos);
		close[pos] = 1;
	}
	
	stack <ll> st;
	
	rep1(i, n) {
		if(st.empty()) {
			st.push(i);
			continue;
		}
		
		ll pos = st.top();
		
		if(ara[i] == ara[pos]) {
			
			if(close[i])
				st.push(i);
			else if(!close[pos]) {
				close[pos] = 1;
				st.pop();
			}
			else
				st.pop();
		}
		else
			st.push(i);
	}
	
	if(!st.empty()) {
		pf("NO\n");
		return 0;
	}
	
	pf("YES\n");
	for1(i, n) {
		if(i != 1) pf(" ");
		if(close[i]) pf("-");
		
		pf("%lld", ara[i] );
	}
	pn;
	
	return 0;
}