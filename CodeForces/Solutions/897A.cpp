#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    string s;
    cin >> s;


    while(m--) {
        int l, r;
        char a, b;
        scanf("%d %d", &l, &r);
        scanf(" %c %c", &a, &b);

        for(int i = l; i <= r; i++) {
            if(s[i - 1] == a)
                s[i - 1] = b;
        }
    }

    cout << s << endl;
    return 0;

}