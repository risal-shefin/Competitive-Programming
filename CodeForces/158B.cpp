#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    //int ara[n + 5];
    int in, in1 = 0, in2 = 0, in3= 0, cnt = 0;
    for(int i = 1 ; i <= n; i++) {
        scanf("%d", &in);
        if(in == 1) {
            if(in3 > 0) {
                cnt++;
                in3--;
            }
            else
                in1++;
        }
        else if(in == 2) {
            if(in2 > 0) {
                cnt++;
                in2--;
            }
            else
                in2++;
        }
        else if(in == 3) {
            if(in1 > 0) {
                cnt++;
                in1--;
            }
            else
                in3++;
        }
        else if(in == 4)
            cnt++;
    }
    cnt += in3;
    if(in2 > 0 && in1 > 0){
        int tmp = min(in2, in1);
        cnt += tmp;
        in1 -= 2 * tmp;
        in2 -= tmp;
    }
    if(in2 > 0) {
        cnt += in2 / 4;
        if(in2 % 4 != 0)
            cnt++;
    }
    if(in1 > 0) {
        cnt += in1 / 4;
        if(in1 % 4 != 0)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
