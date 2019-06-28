#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
       int n, m;
       long long t = 0, ans;
       scanf("%d %d", &n, &m);
       map <int, bool> isRidden[25], isOnWheel;
       map <int, int> inWheel, WheelCount, LeaveCount;
       list <int> l;
       list <int> :: iterator it;
       for(int i = 1; i <= n; i++)
         l.push_back(i);
         while(1) {
            for(int i = 1; i <= m; i++) {
                  t += 5;
                  if(inWheel[i] != 0) {
                    isOnWheel[ inWheel[i] ] = 0;
                    //cout << inWheel[i] << " Out  " << i << endl;
                    l.push_back( inWheel[i] );
                    LeaveCount[ inWheel[i] ]++;
                    inWheel[i] = 0;
                    ans = t;
                }
                  for(it = l.begin(); it != l.end(); it++) {
                      if(isRidden[*it][i] == 0 && isOnWheel[*it] == 0 && inWheel[i] == 0) {
                        isRidden[*it][i] = 1;
                        inWheel[i] = *it;
                        isOnWheel[*it] = 1;
                        l.remove(*it);
                        WheelCount[*it]++;
                        //cout << *it << " IN  " << i << "  " << isRidden[1][2] << endl;
                        ans = t;
                        break;
                    }
                }
                }
              bool checker = 0;
              for(int i = 1; i <= n; i++) {
                if(WheelCount[i] != m || LeaveCount[i] != m) {
                    checker = 1;
                    break;
                }
            }
              if(checker == 0)
                break;
       }
         printf("Case %d: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
