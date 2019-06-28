#include <bits/stdc++.h>
#define siz 10000000
char ara[siz];
using namespace std;
int main()
{
    ara[1] = '1';
    for(int i = 3; i * i <= siz; i += 2) {
        if(ara[i] == '\0') {
            for(int j = 3; i * j <= siz; j += 2) {
                ara[i * j] = '1';
            }
        }
    }
    vector <int> v;
      for(int i = 3; i <= siz / 2; i += 2) {
        if(ara[i] == '\0')
            v.push_back(i);
    }
    v.push_back(siz);
      int T;
    cin >> T;
    for(int j = 1; j <= T; j++) {
        int n;
        cin >> n;
        long long int count = 0;
          if(ara[n - 2] == '\0' && ((n - 2) % 2 != 0 || (n - 2) == 2))
            count++;
          for(int i = 0; v[i] <= n / 2; i++) {
            if(ara[n - v[i]] == '\0' && (n - v[i]) % 2 != 0)
                count++;
        }
          cout << "Case " << j << ": " << count << endl;
    }
}
