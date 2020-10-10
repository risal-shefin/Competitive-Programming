#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)

{
    return a > b;
}

int main()

{
    int t;
    scanf("%d", &t);
    int vol, siz[t + 5];
    long long sum = 0;
    for(int i = 0; i < t; i++) {
        scanf("%d", &vol);
        sum += vol;
    }

    for(int i = 0; i < t; i++)
        scanf("%d", &siz[i]);

    sort(siz, siz + t, compare);
    long long tmp = siz[0] + siz[1];
    if(tmp >= sum)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}