package codingtest;

import java.io.*;
import java.util.Arrays;

public class BOJ_11057 {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[][] dp = new int[n+1][10];
		Arrays.fill(dp[0], 1);
		
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < 10; j++) {
				for(int t = j; t < 10; t++) {
					dp[i][j] += dp[i-1][t];
					dp[i][j] %= 10007;
				}
			}
		}
		
		System.out.println(dp[n][0] % 10007);
	}
}
