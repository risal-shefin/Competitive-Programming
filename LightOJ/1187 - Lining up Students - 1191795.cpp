#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        int id = 1;
        for(int i = 1; i <= n; i++) {
            int in;
            scanf("%d", &in);
            if(i - in <= id && i != 1) id++;
        }
        printf("Case %d: %d\n", ++caseno, id);
    }
    return 0;
}
