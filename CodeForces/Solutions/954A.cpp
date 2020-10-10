#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == 'U' && s[i + 1] == 'R') {
            s[i] = '#';
            s[i + 1] = '#';
            n--;
            i++;
        }

        else if(s[i] == 'R' && s[i + 1] == 'U') {
            s[i] = '#';
            s[i + 1] = '#';
            n--;
            i++;
        }
    }

    printf("%d\n", n);

    return 0;
}