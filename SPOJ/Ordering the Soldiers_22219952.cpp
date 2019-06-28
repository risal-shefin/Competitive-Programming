#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
ll val[200009];
int main()
 {
ll t;
cin >> t;
while(t--) {
vector <ll> v;
ll n;
scanf("%lld", &n);
v.push_back(0);
for(ll i = 1; i <= n; i++) {
   ll in;
   scanf("%lld", &in);
      ll pos = i - in;
      v.insert(v.begin() + pos, i);
}
   for(ll i = 1; i <= n; i++) {
   val[ v[i] ] = i;
}
   for(ll i = 1; i <= n; i++) {
   if(i != 1)
    printf(" ");
   printf("%lld", val[i]);
}
printf("\n");
}
return 0;
}
