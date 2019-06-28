#include <bits/stdc++.h>
using namespace std;
struct charset {
    char ch;
    int power;
};
bool cmp(charset a, charset b)
{
    return a.power > b.power;
}
int main()
{
    int n;
    cin >> n;
    string s[n + 5];
    charset charvalue[15];
    map <char, int> powerofch;
    map <char, bool> first;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < s[i].length(); j++) {
            powerofch[ s[i][j] ] += pow(10, s[i].length() - j - 1);
        }
        first[ s[i][0] ] = 1;
    }
    //cout << powerofch['f'] <<  " sdfsf " << powerofch['i'] << endl;
    for(int i = 0; i <= 9; i++) {
        char ch = i + 'a';
        charvalue[i].ch = ch;
        charvalue[i].power = powerofch[ch];
    }
    sort(charvalue, charvalue + 10, cmp);
    map <char, int> restoringnum;
    map <int, bool> mark;
    bool state = 0;
    for(int i = 0; i < 10; i++) {
        if( first[ charvalue[i].ch ] == 1 && state == 0) {
            restoringnum[ charvalue[i].ch ] = 1;
            mark[1] = 1;
            state = 1;
        }
        else {
            for(int j = 0; j < 10; j++) {
                if(mark[j] == 0) {
                    if( first[ charvalue[i].ch ] == 1 && j == 0) {
                        j++;
                        continue;
                    }
                    restoringnum[ charvalue[i].ch ] = j;
                    mark[j] = 1;
                    break;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int tmp = 0;
        for(int j = 0; j < s[i].length(); j++) {
            tmp = tmp * 10 + restoringnum[ s[i][j] ];
            //cout << s[i][j] << "   " << restoringnum[ s[i][j] ] << endl;
        }
        sum += tmp;
    }
    cout << sum << endl;
    return 0;
}
