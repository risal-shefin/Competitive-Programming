import java.math.BigInteger;
import java.util.Scanner;
public class Main {
      public static void main(String[] args) {
        BigInteger[] ara = new BigInteger[1009];
        int t;
        Scanner scr = new Scanner(System.in);
        t = scr.nextInt();
        for(int i = 1; i <= t; i++) {
            int n, inp;
            n = scr.nextInt();
            BigInteger mul = BigInteger.valueOf(1);
            BigInteger gc = null;
            for(int j = 1; j <= n; j++) {
                inp = scr.nextInt();
                ara[j] = BigInteger.valueOf(inp);
                mul = mul.multiply(ara[j]);
                                //System.out.println(inp);
                                if(j == 1) {
                    gc = ara[j];
                                    }
                else {
                    gc = gc.gcd(ara[j]);
                    BigInteger tmp = mul.divide(gc);
                    gc = tmp;
                    mul = tmp;
                    //System.out.println(gc);
                }
            }
                        //BigInteger ans = mul.divide(gc);
            System.out.println("Case " + i + ": " + gc);
        }
        System.exit(0);
    }
}
