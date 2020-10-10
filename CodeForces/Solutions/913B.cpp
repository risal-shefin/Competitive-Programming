#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <int> graph[1010];
bool visit[1010];

int main()

{

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int u;
        scanf("%d", &u);
        graph[u].push_back(i + 1);
    }

    queue <int> q;
    q.push(1);
    int cnt = 0;
    visit[1] = 1;
    bool checker = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cnt = 0;

        for(int i = 0; i < graph[u].size(); i++) {
            if(visit[graph[u][i] ] == 0) {

                visit[ graph[u][i] ] = 1;
                q.push(graph[u][i]);
            }

            if(graph[ graph[u][i] ].size() == 0) {
                cnt++;
            }
        }

        if(cnt < 3 && graph[u].size() != 0) {
            checker = 0;
            break;
        }

    }

    if(checker == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}