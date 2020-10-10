#include <bits/stdc++.h>
using namespace std;

#define ll long long

char s[400009], s2[400009];

ll occ[30], cnt[30];

int main()

{
    ll n, k;
    cin >> n >> k;

    scanf(" %s", s);

    for(ll i = 0; s[i] != '\0'; i++) {
        occ[ s[i] - 'a' ]++;
    }

    for(ll i = 0; i < 26; i++) {
        if(occ[i] == 0)
            continue;

        ll tmp = min(occ[i], k);
        occ[i] -= tmp;
        k -= tmp;

        if(k == 0)
            break;
    }

    ll indx = 0;
    ll len = strlen(s);
    //cout << occ[s[0] - 'a'] << endl;
    for(ll i = len - 1; i >= 0; i--) {
        if(cnt[ s[i] - 'a' ] >= occ[s[i] - 'a' ])
            continue;
        s2[indx++] = s[i];
        cnt[ s[i] - 'a' ]++;
    }

    s2[indx] = '\0';
    len = strlen(s2);

    for(ll i = len - 1; i >= 0; i--) {
        printf("%c", s2[i]);
    }
    printf("\n");

    return 0;
}