#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
int main()
{
    ll n;
    cin >> n;
    if(n == 1) {
        printf("Ehab\n");
        return 0;
    }
    bool state = 0;
    while(1) {
        if(n == 0) {
            if(state == 0) {
                printf("Ehab\n");
                return 0;
            }
            else {
                printf("Mahmoud\n");
                return 0;
            }
        }
        if(state == 0) {
            if(n % 2 == 1)
                n = 1;
            else
                n = 0;
        }
        else {
            if(n % 2 == 0)
                n = 1;
            else
                n = 0;
        }
        state ^= 1;
    }
    return 0;
}
