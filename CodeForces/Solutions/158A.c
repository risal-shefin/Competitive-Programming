#include <stdio.h>
int main()

{
    int n, k, i, count = 0;
    int a[100];
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > 0) {
            if(i < k) {
                count++;
            }

            if(i >= k && a[k - 1] == a[i]) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}