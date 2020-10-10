#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    string s1, s2;
    cin >> s1 >> s2;
    bool checker = 0;
    long long int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] != s2[i]) {
            if(checker == 0) {
                cnt++;
                checker = 1;
            }
        }
        else {
            checker = 0;
        }
    }
    printf("%I64d\n", cnt);
    return 0;
}