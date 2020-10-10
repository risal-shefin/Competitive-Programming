#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    string s;
    cin >> s;
    set <char> st;
    for(int i = 0; i < s.length(); i++) {
        st.insert(s[i]);
    }

    if(st.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    }
    else {
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}