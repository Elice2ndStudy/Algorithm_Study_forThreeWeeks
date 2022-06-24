package codingtest;

import java.io.*;
import java.util.StringTokenizer;

public class BOJ_16987 {
	public static int n;
	public static int[][] eggs;
	public static int max;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		eggs = new int[n][2];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			eggs[i][0] = Integer.parseInt(st.nextToken());
			eggs[i][1] = Integer.parseInt(st.nextToken());
		}
		eggBreakUp(0, 0);
		
		System.out.println(max);
	}

	public static void eggBreakUp(int cnt, int index) {
		if(index == n) {
			max = Math.max(max, cnt);
			return;
		}
		
		if(eggs[index][0] < 1 || cnt == n - 1) {
			eggBreakUp(cnt, index + 1);
			return;
		}
		
		int nCnt = cnt;
		for(int i = 0; i < n; i++) {
			if(index != i && eggs[i][0] > 0) {
				eggs[i][0] -= eggs[index][1];
				eggs[index][0] -= eggs[i][1];
				
				if(eggs[i][0] < 1) {
					cnt++;
				}
				if( eggs[index][0] < 1){
					cnt++;
				}
				
				eggBreakUp(cnt, index + 1);
				
				eggs[i][0] += eggs[index][1];
				eggs[index][0] += eggs[i][1];
				cnt = nCnt;
			}
		}
		
	}
}
