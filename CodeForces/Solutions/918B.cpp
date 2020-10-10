#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    string s1;
    string s2;
};

int main()

{
    map <string, string> m1;
    map <string, string> m2;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        m1[s2] = s1;
    }

    node str[m + 5];
    for(int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        string tmp = "";
        for(int j = 0; j < s2.length() - 1; j++)
            tmp += s2[j];
        str[i].s1 = s1;
        str[i].s2 = tmp;
    }

    for(int i = 0; i < m; i++) {
        cout << str[i].s1 << " " << str[i].s2 << ";" << " #" << m1[ str[i].s2 ] << endl;
    }

    return 0;
}