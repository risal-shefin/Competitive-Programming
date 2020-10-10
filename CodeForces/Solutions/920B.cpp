#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct student {
    int l;
    int r;
    int i;

    student(int left, int right, int indx) {
        l = left;
        r = right;
        i = indx;
    }

    student() {}
} pupil[1009];

int ans[1009];

bool operator <(student a, student b) {
    if(a.l != b.l)
        return a.l > b.l;
    return a.i > b.i;
}

int main()

{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        priority_queue <student> q;
        for(int i = 0; i < n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            q.push( student(l, r, i));
        }

        int time = 1;
        while(!q.empty()) {
            student u = q.top();
            q.pop();

            if(u.r >= time) {
                time = max(u.l, time);
                ans[u.i] = time;
                time++;
            }
            else
                ans[u.i] = 0;
        }

        for(int i = 0; i < n; i++) {
            printf("%d", ans[i]);
            if(i != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}