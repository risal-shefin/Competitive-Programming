#include <bits/stdc++.h>

using namespace std;

struct ab {
    char a;
    char b;
};

int main()

{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    vector <ab> v;
    unordered_map <string, bool> mark;
    unordered_map <char, char> mark2;

    for(int i = 0; i < n; i++) {
        if(s1[i] != s2[i]) {

            if(mark2[ s1[i] ] == mark2[ s2[i] ] && mark2[ s1[i] ] != '\0')
                continue;

            mark2[ s1[i] ] = s2[i];
            mark2[ s2[i] ] = s1[i];
            string tmp = "";
            if(s1[i] < s2[i]) {
                tmp += s1[i];
                tmp += s2[i];
            }
            else {
                tmp += s2[i];
                tmp += s1[i];
            }

            if(mark[tmp] == 0) {
                ab tp;
                tp.a = s1[i];
                tp.b = s2[i];
                v.push_back(tp);
                mark[tmp] = 1;
            }

        }
    }

    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++) {
        printf("%c %c\n", v[i].a, v[i].b);
    }

    return 0;
}