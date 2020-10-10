#include <bits/stdc++.h>
using namespace std;

string s;
char a[10];
//bool vis[120][6];
long long int len, cnt = 0;

void comb(int indx, int indx2)

{
    //cout << indx2 << endl;
    if(indx2 == 3) {
        a[indx2] = '\0';
        //cout << a << endl;
        if(strcmp(a, "QAQ") == 0)
            cnt++;

        return;
    }

    for(int i = indx; i < len; i++) {
        /*if(vis[i][indx2])
            continue;*/
        a[indx2] = s[i];
        //cout << a << endl;
        //vis[i][indx2] = 1;
        comb(i + 1, indx2 + 1);
    }
}

int  main()

{
    cin >> s;
    len = s.length();
    comb(0, 0);

    printf("%I64d\n", cnt);
    return 0;
}