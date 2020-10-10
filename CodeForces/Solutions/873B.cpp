#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char c;
  
    int sum = 0, result = 0;
    map <int, int> m;
    
    for(int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if(c == '1')
            sum++;
        else
            sum--;
        if(sum == 0)  
            result = max(result, i);
        if(m[sum] == 0) m[sum] = i;
        else result = max(result, i - m[sum]);
     }

     printf("%d\n", result);
}