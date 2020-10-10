#include <bits/stdc++.h>
using namespace std;

int main()

{
    vector < pair<string, int> > round;
    map <string, int> m;
    map <string, int> :: iterator it;
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
       pair<string, int> tmp;
       cin >> tmp.first >> tmp.second;
       round.push_back(tmp);
       m[tmp.first] += tmp.second;
    }

    int mx = INT_MIN;
    for(it = m.begin(); it != m.end(); it++) {
          mx = max(it -> second, mx);
     } 
 

     map <string, int> m2;
     for(int i = 0; i < n; i++) {
         m2[round[i].first] += round[i].second;
          
         if(m2[round[i].first] >= mx && m[round[i].first] >= mx) {
              cout << round[i].first << endl;
               return 0;
         }
     }
}