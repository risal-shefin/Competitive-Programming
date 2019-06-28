#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    char ara[1009];
    gets(ara);
    set <char> st;
    for(int i = 0; ara[i] != '\0'; i++) {
        if(ara[i] >= 'a' && ara[i] <= 'z') {
            st.insert(ara[i]);
        }
    }
    cout << st.size() << endl;
    return 0;
}
