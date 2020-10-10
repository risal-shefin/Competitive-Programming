#include <bits/stdc++.h>
using namespace std;

struct data {
    int person;
    int gold;
};

bool compare(data a, data b)

{
    return a.gold < b.gold;
}

int main()

{
    int n, p;
    cin >> n >> p;
    data ara[n + 5];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ara[i].gold);
        ara[i].person = i;
    }

    map <int, bool> m;
    vector <int> v[n + 5];
    bool visit[n + 5] = {};

    for(int i = 1; i <= p; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        v[u].push_back(w);
        v[w].push_back(u);
    }

    sort(ara + 1, ara + n + 1, compare);

    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        if(visit[ ara[i].person ] == 1)
            continue;

        sum += ara[i].gold;
        if(v[ ara[i].person ].size() == 0)
            continue;

        queue <int> st;
        st.push(ara[i].person);

        while(!st.empty()) {
            int u = st.front();
            st.pop();

            for(int j = 0; j < v[u].size(); j++) {
                if(visit[ v[u][j] ] == 0) {
                    visit[ v[u][j] ] =1;
                    st.push(v[u][j] );
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}