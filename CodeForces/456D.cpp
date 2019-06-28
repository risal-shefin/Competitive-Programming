#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll indx = 0;
bool win[2700009], lose[2700009];
struct trie {
    trie *nxt[27];
    ll num;
    trie() {
        for(ll i = 0; i < 26; i++)
            nxt[i] = nullptr;
        num = ++indx;
    }
};
trie *start = new trie();
string s;
void add()
{
    trie *cur = start;
    for(ll i = 0; i < s.length(); i++) {
        if(cur -> nxt[s[i] - 'a'] == nullptr)
            cur -> nxt[ s[i] - 'a' ] = new trie();
        cur = cur -> nxt[s[i] - 'a'];
    }
}
void solve(trie *cur)
{
    win[cur -> num] = false;
    lose[cur -> num] = false;
    bool isLeaf = true;
    for(ll i = 0; i < 26; i++)
        if(cur -> nxt[i] != nullptr) {
            solve(cur -> nxt[i]);
            isLeaf = false;
            win[cur -> num] |= !win[ (cur -> nxt[i]) -> num];
            lose[cur -> num] |= !lose[ (cur -> nxt[i]) -> num];
        }
    if(isLeaf)
        lose[cur -> num] = true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        cin >> s;
        add();
    }
    solve(start);
    if(win[start -> num]) {
        if(k & 1)
            cout << "First" << endl;
        else {
            if(lose[start -> num])
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
    }
    else {
        cout << "Second" << endl;
    }
    return 0;
}
