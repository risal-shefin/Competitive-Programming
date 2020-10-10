#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector <ll> graph[100009];
ll counter[100009], cnt = 1, mark[100009];
queue <ll> q;

int main()

{
    //memset(counter, 1, sizeof(counter));
    ll n;
    cin >> n;
    graph[1].push_back(0);
    for(ll i = 2; i <= n; i++) {
        ll u;
        scanf("%lld", &u);
        graph[i].push_back(u);
        q.push(i);
    }

    mark[1] = 1;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        //cout << u << endl;
        if(counter[u] == 0 && mark[u] == 1)
            continue;
        //cout << counter[u] << endl;
        counter[u] = 0;
        if(u != 0)
            mark[u] = 1;

        ll apl = graph[u][0];
        if(apl == 0) {
            cnt++;
            continue;
        }

        //cout << u << " " << apl << endl;
        counter[apl] ^= 1;
        q.push(apl);
    }

    cout << cnt << endl;

    return 0;
}