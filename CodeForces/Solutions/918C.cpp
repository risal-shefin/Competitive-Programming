#include <bits/stdc++.h>
using namespace std;

int main() {
     string s;
     cin >> s;
     long long ans = 0;
     for(int i = 0; i < s.length(); i++) {
         int b1 = 0, b2 = 0;
         for(int j = i; j < s.length(); j++) {
           if(s[j] == '(') b1++, b2++;
           else if(s[j] == ')') b1--, b2--;
           else b1++, b2--;
           if(b1 < 0) break;
           if(b2 < 0) b2 += 2;
           if(b2 == 0) ans++;
        }
     }
     
     cout << ans << endl;
     return 0;
}