#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18
#define sl(val) scanf("%lld", &val)

string s1, s2, s3;
string hah[] = {"", "Kuro", "Shiro", "Katie"};

int main()

{
    ll n;
    cin >> n;
    cin >> s1 >> s2 >> s3;
    map <char, ll> cnt1, cnt2, cnt3;
    ll mx1 = 0, mx2 = 0, mx3 = 0;

    for(ll i = 0; i < s1.length(); i++) {
        cnt1[ s1[i] ]++;
        mx1 = max(mx1, cnt1[ s1[i] ]);
    }

    for(ll i = 0; i < s2.length(); i++) {
        cnt2[ s2[i] ]++;
        mx2 = max(mx2, cnt2[ s2[i] ]);
    }

    for(ll i = 0; i < s3.length(); i++) {
        cnt3[ s3[i] ]++;
        mx3 = max(mx3, cnt3[ s3[i] ]);
    }


    //cout << mx1 << "  " << mx2 << "  " << mx3 << endl;
    ll pos = 0;
    ll mv = s1.length() - mx1;
    pos = min(mv, n);
    mx1 += pos;

    for(ll i = 0; i < s1.length(); i++)
    {
        mv = s1.length() - cnt1[ s1[i] ];
        mv = n - mv;
        if(mv < 0)
            continue;
        if(mv == 1 && cnt1[ s1[i] ] == s1.length())
        {
            mx1 = s1.length() - 1;
        }
        else {
            mx1 = s1.length();
            break;
        }
    }

    mv = s2.length() - mx2;
    pos = min(mv, n);
    mx2 += pos;

    for(ll i = 0; i < s2.length(); i++)
    {
        mv = s2.length() - cnt2[ s2[i] ];
        mv = n - mv;
        if(mv < 0)
            continue;
        if(mv == 1 && cnt2[ s2[i] ] == s2.length())
        {
            mx2 = s2.length() - 1;
        }
        else {
            mx2 = s2.length();
            break;
        }
    }

    mv = s3.length() - mx3;
    pos = min(mv, n);
    mx3 += pos;

    for(ll i = 0; i < s3.length(); i++)
    {
        mv = s3.length() - cnt3[ s3[i] ];
        mv = n - mv;
        if(mv < 0)
            continue;
        if(mv == 1 && cnt3[ s3[i] ] == s3.length())
        {
            mx3 = s3.length() - 1;
        }
        else {
            mx3 = s3.length();
            break;
        }
    }


    ll mx = 0, ans = 0;
    if(mx1 > mx) {
        mx = mx1;
        ans = 1;
    }
    if(mx2 > mx) {
        mx = mx2;
        ans = 2;
    }
    if(mx3 > mx) {
        mx = mx3;
        ans = 3;
    }

    //cout << mx1 << " " << mx2 << " " << mx3 << endl;

    if( (mx1 == mx && mx2 == mx) || (mx1 == mx && mx3 == mx) || (mx2 == mx && mx3 == mx) ) {
        printf("Draw\n");
        return 0;
    }

    if(ans == 1) {
        printf("Kuro\n");
        return 0;
    }
    else if(ans == 2) {
        printf("Shiro\n");
        return 0;
    }
    else {
        printf("Katie\n");
        return 0;
    }

    return 0;
}