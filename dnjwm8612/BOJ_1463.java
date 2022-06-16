package codingtest;

import java.io.*;

public class BOJ_1463 {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] dp = new int[n+1];
		dp[0] = 0;
		dp[1] = 0;
		
		for(int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			if(i % 2 == 0) {
				dp[i] = Math.min(dp[i], dp[i/2] + 1);
			}
			if(i % 3 == 0){
				dp[i] = Math.min(dp[i], dp[i/3] + 1);
			}
		}
		System.out.print(dp[n]);
//		D[12] = ?
//		3으로 나누거나 (D[12] = D[4] + 1) = (D[k] = D[k/3] + 1)
//		2로 나누거나 (D[12] = D[6] + 1) = (D[k] = D[k/2] + 1)
//		1을 빼거나 (D[12] = D[11]+1) = (D[k] = D[k-1] + 1)
//		 즉 D[12] = min(D[4] + 1, D[6] + 1, D[11] + 1)
//		-> D[k] = min(D[k/3] + 1, D[k/2] + 1, D[k-1] + 1)
	}
}
