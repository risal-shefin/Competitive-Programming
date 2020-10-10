#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    int n, m;
    cin >> n >> m;
    vector <double> v;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        double cost = (a * 1.0) / (b * 1.0);
        v.push_back(cost);
    }

    sort(v.begin(), v.end());
    double ans = v[0] * m;
    printf("%0.10f\n", ans);
    return 0;
}