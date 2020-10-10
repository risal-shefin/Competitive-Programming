#include <bits/stdc++.h>
using namespace std;

#define ll register unsigned short int
const int siz = 50002;

char y[50009], x[50009];
bitset <siz> M[30], M2[30], L[siz], num1, num2, carry;
int m;
bool chk = 0;

bitset <siz> operator +(const bitset <siz> &a, const bitset <siz> &b)

{
    num1 = a, num2 = b, chk = 0;
    while(num2 != 0) {
        carry = num1 & num2;
        num1 ^= num2;
        num2 = (carry << 1);

        /// extra part
        if(num2[m + 1] == 1) {
            chk = 1;
            num2[m + 1] = 0;
        }
    }
    return num1;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, ans = 0;

    cin >> (y + 1) >> (x + 1);
    ll n = strlen(y + 1);
    m = strlen(x + 1);

    for(i = 1; i <= m; i++)
        M[x[i] - 'a'][i] = 1;

    for(i = 0; i < 27; i++) {
        for(j = 1; j <= m; j++)
            M2[i][j] = !M[i][j];
    }

    for(i = 1; i <= m; i++)
        L[0][i] = 1;

    for(j = 1; j <= n; j++) {

        L[j] = L[j - 1] + (L[j - 1] & M[y[j] - 'a']);
        L[j] |= (L[j - 1] & M2[y[j] - 'a']);
        ans += chk;
    }

    cout << ans << endl;

    return 0;
}
