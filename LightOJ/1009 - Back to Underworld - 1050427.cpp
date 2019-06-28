#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        vector <int> anode[20010], nodechk;
        int n, u, v;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++) {
            scanf("%d %d", &u, &v);
            anode[u].push_back(v);
            anode[v].push_back(u);
            nodechk.push_back(u);
            nodechk.push_back(v);
        }
          int color[20010];
        for(int j = 0; j < 20010; j++)
            color[j] = 0;
         int c1 = 0, c2 = 0, ans = 0;
          queue <int> node;
        node.push(nodechk[0]);
        color[nodechk[0]] = 1;
        c1++;
          for(int j = 0; j < nodechk.size(); j++) {
            if(color[nodechk[j]] == 0 || j == 0) {
                if(j != 0) {
                    ans += max(c1, c2);
                    c1 = 0, c2 = 0;
                    node.push(nodechk[j]);
                    color[nodechk[j]] = 1;
                    c1++;
                }
                while(!node.empty()) {
                    u = node.front();
                    node.pop();
                    for(int k = 0; k < anode[u].size(); k++) {
                        if(color[anode[u][k]] == 0) {
                            if(color[u] == 1) {
                                color[anode[u][k]] = 2;
                                c2++;
                            }
                            else {
                                color[anode[u][k]] = 1;
                                c1++;
                            }
                              node.push(anode[u][k]);
                        }
                    }
                }
            }
        }
          ans += max(c1, c2);
        printf("Case %d: %d\n", i, ans);
    }
      return 0;
}
 
