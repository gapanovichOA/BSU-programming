import java.io.*;
import java.util.Scanner;

public class Main {

    public static long ones(int n, int k,int mod) {
        long[][] dp = new long[n + 1][n + 1];

        for (int i = 0; i <= n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j - 1]%mod + dp[i - 1][j]%mod)%mod;
            }
        }
        return (dp[n][k]);
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int mod = 1000000007;
            long answ = Main.ones(n, k,mod) % mod;
            System.out.println(answ);
        }
    }
}
