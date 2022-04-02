import java.io.*;
import java.util.Scanner;

public class Main {

    public static int matrixOrder(int[] p) {
        int n = p.length - 1;
        int[][] dp = new int[n][n];

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        for (int l = 1; l < n; ++l) {
            for (int i = 0; i < n - l; ++i) {
                int j = i + l;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = Math.min(dp[i][j],
                            dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
                }
            }
        }
        return dp[0][n - 1];
    }

    public static void main(String[] args) {
        try (Scanner sc= new Scanner(new File("input.txt"))){
            int n=sc.nextInt();
            int[] test=new int[n+1];
            test[0]=sc.nextInt();
            for(int i=1;i<=n;i++){
                test[i]=sc.nextInt();
                if(i<n){
                int value=sc.nextInt();
                }
            }
            PrintWriter writer=new PrintWriter(new FileWriter("output.txt"));
            writer.println(Main.matrixOrder(test));
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
