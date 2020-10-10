#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int half = n / 2, ans = n;
    for(int i = half; i >= 1; i--) {
        bool test = 1;
        for(int j = 0, k = i; j < i; j++, k++) {
            if(s[j] != s[k]) {
                test = 0;
                break;
            }
        }

        if(test) {
            ans = ans - i + 1;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}