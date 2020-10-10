#include <stdio.h>
int main()

{
    int M, N, row1, col1, row2, col2;
    int xtr1 = 0, xtr2 = 0, dm1, dm2;
    scanf("%d %d", &M, &N);

    col1 = M;
    row1 = N / 2;
    if(N % 2 != 0) {
        xtr1 = M / 2;
    }
    dm1 = row1 * col1 + xtr1;

    col2 = M / 2;
    row2 = N;
    if(M % 2 != 0) {
        xtr2 = N / 2;
    }
    dm2 = row2 * col2 + xtr2;

    if(dm1 >= dm2) {
        printf("%d\n", dm1);
    }

    else {
        printf("%d\n", dm2);
    }

    return 0;
}