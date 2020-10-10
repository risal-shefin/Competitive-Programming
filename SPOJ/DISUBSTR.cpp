#include <bits/stdc++.h>
using namespace std;

char ara[1009];
#define ll unsigned long long
unordered_map <ll, bool> ase;

int main()

{
    int n;
    scanf("%lld", &n);
    while(n--) {
        scanf("%s", ara);
        ll len = strlen(ara);
        ll cnt = 0, hsh, gun;

        for(ll i = 0; i < len; i++) {
            hsh = 0, gun = 1;
            for(ll j = i; j < len; j++) {
                hsh += (ara[j] - 32) * gun;
                gun *= 101;

                if(ase.find(hsh) == ase.end()) {
                    cnt++;
                    ase[hsh] = 1;
                }
            }
        }

        printf("%lld\n", cnt);
        ase.clear();
    }

    return 0;
}
