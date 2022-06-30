package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_1992 {
	public static int[][] map;
	public static StringBuffer sb = new StringBuffer();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			String word = br.readLine();
			for(int j = 0; j < N; j++) {
				map[i][j] = word.charAt(j) - '0';
			}
		}
		
		quadTree(N, 0, 0);
		System.out.println(sb.toString());
		
	}
	
	public static void quadTree(int size, int y, int x) {
		if(isPossible(size, y, x)) {
			sb.append(map[y][x]);
			return;
		}
		
		int newSize = size / 2;
		
		sb.append('(');
		
		quadTree(newSize, y, x);
		quadTree(newSize, y, x + newSize);
		quadTree(newSize, y + newSize, x);
		quadTree(newSize, y + newSize, x + newSize);
		
		sb.append(')');
	}
	
	public static boolean isPossible(int size, int y, int x) {
		int num = map[y][x];
		
		for(int i = y; i < y + size; i++) {
			for(int j = x; j < x + size; j++) {
				if(num != map[i][j]) {
					return false;
				}
			}
		}
		
		return true;
	}
}
