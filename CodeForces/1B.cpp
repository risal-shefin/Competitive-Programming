#include <bits/stdc++.h>
using namespace std;
int main()
{
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map <char, int> m;
    for(int i = 0; i < alp.length(); i++) {
        m[alp[i]] = i + 1;
    }
    int n, check;
    scanf("%d", &n);
    while(n--) {
        char s1[100];
        scanf(" %s", s1);
        check = 0;
        if(s1[0] == 'R' && (s1[1] >= '0' && s1[1] <= '9')) {
            for(int h = 2; s1[h] != '\0'; h++) {
                if((s1[h] == 'C')) {
                    check = 1;
                    break;
                }
            }
        }
        if(check == 0) {
            int ans = 0, j, tmp = 0;
            for(j = 0; s1[j] >= 'A'; j++) {
                ans = ans * 26 + m[s1[j]];
            }
            for( ; s1[j] != '\0'; j++)
                tmp = tmp * 10 + s1[j] - 48;
            printf("R%dC%d\n", tmp, ans);
        }
        else {
            stringstream ss (s1);
            string s2 = "";
            char c;
            int tmp, tc;
            ss >> c >> tmp >> c >> tc;
            while(tc > 0) {
                if(tc % 26 == 0) {
                    tc = tc / 26 - 1;
                    s2 += 'Z';
                }
                else {
                    int tm = tc % 26;
                    tc = tc / 26;
                    s2 += alp[tm - 1];
                }
            }
            reverse(s2.begin(), s2.end());
            printf("%s%d\n", s2.c_str(), tmp);
        }
    }
}
