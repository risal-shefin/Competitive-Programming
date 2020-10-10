#include <bits/stdc++.h>
using namespace std;

bool ispossible(int dgt, int tmpsum)

{
    return tmpsum >= 0 && tmpsum <= dgt * 9;
}

int main()

{
    int n, s;
    scanf("%d %d", &n, &s);
    string s1 = "", s2 = "";
    int sum1 = s, sum2 = s;

    for(int i = 1; i <= n; i++) {
        bool check1 = 0, check2 = 0;
        for(int j = 0, k = 9; j <= 9; j++, k--) {
            if((i == 1 && j > 0) || i > 1 || n == 1) {
                if(ispossible(n - i, sum1 - j) && check1 == 0) {
                   s1 += (j + 48);
                   sum1 -= j;
                   check1 = 1;
                }
            }

            if( (i == 1 && k > 0) || i > 1 || n == 1) {
                if(ispossible(n - i, sum2 - k) && check2 == 0) {
                   s2 += (k + 48);
                   sum2 -= k;
                   check2 = 1;
                }
            }

            if(check1 == 1 &&  check2 == 1)
                break;
        }
    }

    if(s1.length() == n)
        cout << s1 << " ";
    else
        cout << -1 << " ";

    if(s2.length() == n)
        cout << s2 << endl;
    else
        cout << -1 << endl;

    return 0;
}