#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x = 1, y = 1;
    map <int, bool> mark;
    mark[1] = 1;
    for(int i = 1; i <= 1020; i++) {
        int tmp = x+ y;
        mark[tmp] = 1;
        x = y;
        y = tmp;
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(mark[i] == 1)
            cout << "O";
        else
            cout << "o";
    }
    cout << endl;
    return 0;
}
