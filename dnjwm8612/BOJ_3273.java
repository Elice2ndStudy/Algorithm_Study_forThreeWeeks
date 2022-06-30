package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_3273 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] array = new int[n];
		
		for(int i = 0; i < n; i++) {
			array[i] = Integer.parseInt(st.nextToken());
		}
		
		int x = Integer.parseInt(br.readLine());
		
		Arrays.sort(array);
		
		int start = 0;
		int end = n - 1;
		int count = 0;
		
		while(true) {
			if(start == end) {
				break;
			}
			
			if(array[start] + array[end] == x) {
				count++;
			}
			if(array[start] + array[end] > x) {
				end--;
			}else {
				start++;
			}
			
		}
		
		System.out.println(count);
		br.close();
	}

}
