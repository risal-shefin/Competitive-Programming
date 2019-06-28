#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
int cnt[200009];
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
          vector <pii> ara;
        set <int> distinct;
        map <int, int> m;
        int counter = 1;
          for(int i = 1; i <= n; i++) {
           int a, b;
           scanf("%d %d", &a, &b);
           ara.push_back(make_pair(a, b));
           distinct.insert(a);
           distinct.insert(b);
        }
        vector <int> v(distinct.begin(), distinct.end());
          for(int i = 0; i < v.size(); i++) {
            m[ v[i] ] = counter;
            counter += 2;
        }
          for(int i = 0; i < ara.size(); i++) {
            cnt[ m[ ara[i].first] ]++;
            cnt[ m[ ara[i].second] + 1]--;
        }
          for(int i = 1; i <= counter; i++)
            cnt[i] += cnt[i - 1];
          printf("Case %d:\n", ++caseno);
        while(q--) {
            int num;
            scanf("%d", &num);
            int pos = lower_bound(v.begin(), v.end(), num) - v.begin();
            //cout << " lower: " << v[pos] << endl;
              if(pos == v.size()) {
                printf("0\n");
                continue;
            }
              int indx = m[ v[pos] ];
            if(v[pos] > num)
                indx--;
            printf("%d\n", cnt[indx]);
        }
        memset(cnt, 0, sizeof(cnt));
    }
      return 0;
}
 
