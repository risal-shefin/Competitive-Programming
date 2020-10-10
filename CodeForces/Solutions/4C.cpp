#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    map <string, int> m;
    string s;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        cin >> s;
        if(m[s] == 0) {
            printf("OK\n");
        }
        else {
            cout << s;
            cout << m[s] << endl;
        }
        m[s]++;
    }

    return 0;
}