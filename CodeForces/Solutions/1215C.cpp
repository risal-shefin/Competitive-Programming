#include <bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;
deque <ll> dq[2];

vector <pair<ll, ll>> ans;

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    cin >> a >> b;
    ll ca = 0, cb = 0;
    for(ll i = 0; i < a.length(); i++) {
        if(a[i] == 'b')
            cb++;
        else
            ca++;
    }
    for(ll i = 0; i < b.length(); i++) {
        if(b[i] == 'b')
            cb++;
        else
            ca++;

        if(a[i] != b[i]) {
            if(b[i] == 'a')
                dq[0].push_back(i);
            else
                dq[1].push_back(i);
        }
    }

    if(ca % 2 != 0 || cb % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    for(ll i = 0; i < b.length(); i++) {
        if(a[i] == b[i])
            continue;

        if(b[i] == 'a' && dq[0].size() == 1) {
            dq[0].pop_front();
            swap(a[i], b[i]);
            dq[1].push_front(i);
            ans.push_back(make_pair(i+1, i+1));
        }
        if(b[i] == 'b' && dq[1].size() == 1) {
            dq[1].pop_front();
            swap(a[i], b[i]);
            dq[0].push_front(i);
            ans.push_back(make_pair(i+1, i+1));
        }

        //cout << i << " " << b[i] << endl;
        dq[b[i] - 'a'].pop_front();
        ans.push_back(make_pair(i + 1, dq[b[i] - 'a'].front() + 1 ));
        swap(a[i], b[ dq[b[i] - 'a'].front() ]);
        dq[b[i] - 'a'].pop_front();
    }

    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}