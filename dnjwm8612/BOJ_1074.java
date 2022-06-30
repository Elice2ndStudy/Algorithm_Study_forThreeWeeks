package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1074 {
	public static int count;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int size = (int)Math.pow(2, N);
		
		getZ(size, r, c);
		System.out.println(count);
	}

	
	public static void getZ(int size, int r, int c) {
		if(size == 1) {
			return;
		}
		
		int half = size / 2;
		
		if(r < half && c < half) {
			getZ(half, r, c);
		}else if(r < half && c >= half) {
			count += (size * size) / 4;
			getZ(half, r, c - half);
		}else if(r >= half && c < half) {
			count += ((size * size) / 4) * 2;
			getZ(half, r - half, c);
		}else {
			count += ((size * size) / 4) * 3;
			getZ(half, r - half, c - half);
		}
	}
}
