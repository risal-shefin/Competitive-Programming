#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define x first
#define y second

pll point[8], tmp[8];
ll dp[1 << 8][1 << 8], chk = 0;

ll sqd(pll &a, pll &b)

{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool isRectangle()

{
    if(sqd(tmp[0], tmp[1]) == sqd(tmp[2], tmp[3])) {

        if(sqd(tmp[0], tmp[3]) == sqd(tmp[1], tmp[2]))
            return sqd(tmp[0], tmp[2]) == sqd(tmp[1], tmp[3]);

        else if(sqd(tmp[0], tmp[2]) == sqd(tmp[1], tmp[3]))
            return sqd(tmp[0], tmp[3]) == sqd(tmp[1], tmp[2]);
    }
    else if(sqd(tmp[0], tmp[2]) == sqd(tmp[1], tmp[3])) {

        if(sqd(tmp[0], tmp[3]) == sqd(tmp[1], tmp[2]))
            return sqd(tmp[0], tmp[1]) == sqd(tmp[2], tmp[3]);

        else if(sqd(tmp[0], tmp[3]) == sqd(tmp[2], tmp[1]))
            return sqd(tmp[0], tmp[1]) == sqd(tmp[3], tmp[2]);
    }
    else if(sqd(tmp[0], tmp[3]) == sqd(tmp[2], tmp[1])) {

        if(sqd(tmp[0], tmp[2]) == sqd(tmp[3], tmp[1]))
            return sqd(tmp[0], tmp[1]) == sqd(tmp[2], tmp[3]);

        else if(sqd(tmp[0], tmp[1]) == sqd(tmp[2], tmp[3]))
            return sqd(tmp[0], tmp[2]) == sqd(tmp[1], tmp[3]);
    }
    return 0;
}

bool isSquare()

{
    ll d1 = sqd(tmp[0], tmp[1]), d2 = sqd(tmp[0], tmp[2]), d3 = sqd(tmp[0], tmp[3]);
    if(d2 == d3 && d1 > d2) {
        ll d4 = sqd(tmp[1], tmp[2]), d5 = sqd(tmp[1], tmp[3]), d6 = sqd(tmp[3], tmp[2]);
        if(d4 == d5 && d2 + d4 == d1 && d1 == d6)
            return 1;
        else
            return 0;
    }
    else if(d1 == d2 && d3 > d2) {
        ll d4 = sqd(tmp[3], tmp[2]), d5 = sqd(tmp[1], tmp[3]), d6 = sqd(tmp[1], tmp[2]);
        if(d4 == d5 && d2 + d4 == d3 && d3 == d6)
            return 1;
        else
            return 0;
    }
    else if(d1 == d3 && d2 > d1) {
        ll d4 = sqd(tmp[1], tmp[2]), d5 = sqd(tmp[2], tmp[3]), d6 = sqd(tmp[3], tmp[1]);
        if(d4 == d5 && d1 + d4 == d2 && d2 == d6)
            return 1;
        else
            return 0;
    }
    return 0;
}

ll solve(ll rec, ll sq)

{
    ll &ret = dp[rec][sq];
    if(ret != -1)
        return ret;

    ll cnt = 0, indx = 0, cnt2 = 0;
    for(ll i = 0; i < 8; i++) {
        if((rec >> i) & 1) {
            tmp[indx++] = point[i];
            cnt++;
        }
    }
    if(cnt == 4) {
        if(isRectangle()) {
            cout << "YES" << endl;

            bool f = 0;
            for(ll i = 0; i < 8; i++) {
                if((sq >> i) & 1) {
                    if(f) printf(" ");
                    printf("%lld", i+1);
                    f = 1;
                }
            }
            printf("\n");

            f = 0;
            for(ll i = 0; i < 8; i++) {
                if((rec >> i) & 1) {
                    if(f) printf(" ");
                    printf("%lld", i+1);
                    f = 1;
                }
            }
            printf("\n");
            exit(0);
        }
        else
            return ret = 0;
    }
    else if(cnt == 0) {
        for(ll i = 0; i < 8; i++) {
            if((sq >> i) & 1) {
                cnt2++;
                tmp[indx++] = point[i];
            }
        }

        if(cnt2 == 4) {
            if(isSquare()) {
                for(ll i = 0; i < 8; i++) {
                    if((rec >> i) & 1 || (sq >> i) & 1)
                        continue;
                    ret = solve(rec | (1 << i), sq);
                }
                return ret;
            }
            else
                return ret = 0;
        }
        else {
            for(ll i = 0; i < 8; i++) {
                if((sq >> i) & 1)
                    continue;
                ret = solve(0, sq | (1 << i));
            }
            return ret;
        }
    }
    else {
        for(ll i = 0; i < 8; i++) {
            if((rec >> i) & 1  || (sq >> i) & 1)
                continue;
            ret = solve(rec | (1 << i), sq);
        }
        return ret;
    }

}

int main()

{
    memset(dp, -1, sizeof(dp));
    for(ll i = 0; i < 8; i++)
        scanf("%lld %lld", &point[i].x, &point[i].y);

    ll ret = solve(0, 0);
    cout << "NO" << endl;

    return 0;
}