#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ll long long

int main()

{
	ll t;
	cin >> t;
	while(t--) {
		ll ang;
		scanf("%lld", &ang);
		
		ll n;
		for(n = 1; ; n++) {
			if( (n * ang) % 180 == 0) {
				if((n * ang) / 180 > n - 2)
					continue;
					
				break;
			}
		}
		printf("%lld\n", n);
	}
	return 0;
}