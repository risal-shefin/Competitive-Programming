#include <bits/stdc++.h>
using namespace std;

int main()

{
    long long n, m, a, c1, c2;
    cin >> n >> m >> a;
    c1 = ceil((double)n / (double)a);
    c2 = ceil((double)m / (double)a);
    c1 = c1 * c2;
    cout << c1 << endl;

}