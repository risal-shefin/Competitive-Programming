#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x, y;
    cin >> x >> y;
    if(y == 0) {
        printf("No\n");
        return 0;
    }
    if(y == 1) {
        if(x == 0) {
            printf("Yes\n");
            return 0;
        }
        else {
            printf("No\n");
            return 0;
        }
    }
    if(y > x + 1) {
        printf("No\n");
        return 0;
    }
    int ori = y - 1;
    int cop = ori;
    if((x - cop) % 2 == 0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
