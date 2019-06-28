#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s1, tmp;
    cin >> s1;
    tmp = s1;
    reverse(tmp.begin(), tmp.end());
    cout << s1 << tmp << endl;
    return 0;
}
