#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    cin.ignore();
    for(int i = 1; i <= T; i++) {
        string s1, s2;
        int count1 = 0, count2 = 0, check = 1;
        map <char, int> m, m2;
        getline(cin, s1);
        getline(cin, s2);
        for(int j = 0; s1[j] != '\0'; j++) {
            s1[j] = tolower(s1[j]);
            if(s1[j] >= 'a' && s1[j] <= 'z') {
                count1++;
                m[s1[j]]++;
            }
        }
          for(int j = 0; s2[j] != '\0'; j++) {
            s2[j] = tolower(s2[j]);
            if(s2[j] >= 'a' && s2[j] <= 'z') {
                count2++;
                if(m[s2[j]] == 0) {
                    check = 0;
                    break;
                }
                m2[s2[j]]++;
                  if(m2[s2[j]] > m[s2[j]]) {
                    check = 0;
                    break;
                }
            }
          }
          if(count1 != count2 || check == 0)
            printf("Case %d: No\n",i);
        else
            printf("Case %d: Yes\n", i);
    }
      return 0;
}
