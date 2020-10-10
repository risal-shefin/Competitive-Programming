#include <bits/stdc++.h>
using namespace std;

int main()

{
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    int a[len1 + 5];
    for(int i = 0; i < len1; i++)
        scanf("%d", &a[i]);

    int lo = 0, hi = len1, ans;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        bitset <200009> mark;

        for(int i = 0; i < mid; i++)
            mark[a[i] - 1] = 1;

        int j = 0, cnt = 0;
        for(int i = 0; i < len2; i++) {
            for(; j < len1; j++) {
                if(s1[j] == s2[i] && mark[j] == 0) {
                    j++;
                    cnt++;
                    break;
                }
            }
        }

        if(cnt == len2) {
            ans = mid;
            lo = mid + 1;
        }

        else
            hi = mid - 1;
    }

    printf("%d\n", ans);

    return 0;
}