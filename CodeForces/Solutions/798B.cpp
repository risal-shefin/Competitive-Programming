#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin >> n;
    string s[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int m = INT_MAX;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            string tmp = s[j];

            int len = 0;
            while(s[i] != tmp) {

                if(len == s[j].length()) {
                    printf("-1\n");
                    return 0;
                }

                char f = tmp[0];
                for(int l = 1; l < tmp.length(); l++) {
                    tmp[l - 1] = tmp[l];
                }

                tmp[tmp.length() - 1] = f;
                len++;
                sum++;
            }

        }

        m = min(m, sum);
    }

    cout << m << endl;

    return 0;
}