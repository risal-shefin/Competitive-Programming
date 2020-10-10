#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n, m, k;
    cin >> n >> m >> k;
    int tmp = m * 2;

    int ln = 0;
    if(k % tmp != 0) {
        ln = k / tmp + 1;
    }

    else {
        ln = k / tmp;
    }

    int rem;
    int tmp2 = (ln - 1) * tmp;
    if(tmp2 == 0) {
        rem = k - 0;
    }
    else
        rem = k - tmp2;

    int rw;
    if(rem % 2 == 0) {
        rw = rem / 2;
    }
    else
        rw = rem / 2 + 1;

    char c;
    if(k % 2 == 1)
        c= 'L';
    else
        c = 'R';

    printf("%d %d %c\n", ln, rw, c);

    return 0;

}