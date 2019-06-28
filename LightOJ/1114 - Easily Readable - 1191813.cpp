#include <bits/stdc++.h>
using namespace std;
#define ll long long
char in1[150], in2[10009];
int main()
{
    //freopen("out.txt", "w", stdout);
    //std::ios::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        //cout << t;
        ll tot;
        scanf("%lld", &tot);;
        getchar();
        map <string, ll> m;
        for(ll i = 1; i <= tot; i++) {
            scanf("%s", in1);
            ll ln = strlen(in1);
            string s(in1, in1 + ln);
            /*string tmp = "";
            tmp += s[0] + s[ s.length() - 1];;*/
            if(s.length() > 3)
                sort(s.begin() + 1, s.end() - 1);
            m[s]++;
        }
          ll tot2;
        scanf("%lld", &tot2);
        printf("Case %lld:\n", ++caseno);;
        getchar();
        for(ll i = 1; i <= tot2; i++) {
            ll cnt = 1;
            gets(in2);
            ll ln = strlen(in2);
            string sent(in2, in2 + ln), word;
            stringstream ss(sent);
            while(ss >> word) {
                /*string tmp = "";
                tmp += word[0] + word[ word.length() - 1];*/
                if(word.length() > 3)
                    sort(word.begin() + 1, word.end() - 1);
                cnt *= m[word];
            }
            printf("%lld\n", cnt);
        }
    }
    return 0;
}
