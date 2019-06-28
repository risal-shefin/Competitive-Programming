#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long N, dec;
    int T, i, j;
    cin >> T;
      for(i = 1; i <= T; i++) {
        deque <int> b;
        deque <int> :: iterator it;
        dec = 0;
        scanf("%lld", &N);
        while(N != 0) {
            b.push_front(N % 2);
            N = N / 2;
        }
        b.push_front(0);
          next_permutation(b.begin(), b.end());
          for(it = b.end() - 1, j = 0; it >= b.begin(); it--, j++)  {
            dec += (*it * pow(2, j));
        }
          printf("Case %d: %lld\n", i, dec);
    }
      return 0;
}
