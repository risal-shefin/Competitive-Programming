#include <stdio.h>
#include <math.h>
int main()
{
    int T, i, j, k, l, n, sum, sm, check;
    char dec[20], d[5];
    char bin[40];
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        check = 0;
        scanf(" %s", dec);
        scanf(" %s", bin);
        k = 0, sum = 0, n = 7;
        for(j = 0, l = 0; ;) {
              if(dec[j] != '.' && dec[j] != '\0') {
                d[k] = dec[j];
                j++;
                k++;
            }
              if(bin[l] != '.' && bin[l] != '\0') {
                sum += (bin[l] - 48) * pow(2, n);
                l++;
                n--;
            }
              //printf("sum = %d\n", sum);
              if((dec[j] == '.' && bin[l] == '.') || (dec[j] == '\0' && bin[l] == '\0')) {
                if(k == 3) {
                    sm = (d[0] - 48) * 100 + (d[1] - 48) * 10 + (d[2] - 48);
                }
                else if(k == 2) {
                    sm = (d[0] - 48) * 10 + (d[1] - 48);
                }
                else if(k == 1) {
                    sm = (d[0] - 48);
                }
                  if(sum == sm) {
                    check = 1;
                }
                  else if(sum != sm) {
                    check = 0;
                    break;
                }
                  if(dec[j] == '\0' && bin[l] == '\0')
                    break;
                  sum = 0;
                k = 0;
                n = 7;
                j++;
                l++;
            }
        }
          if(check == 1) {
            printf("Case %d: Yes\n", i);
        }
          else {
            printf("Case %d: No\n", i);
        }
    }
      return 0;
}
