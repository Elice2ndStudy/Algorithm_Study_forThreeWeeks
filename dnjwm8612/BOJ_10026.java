package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class BOJ_10026 {
	public static int[] dy = {1, 0, -1, 0};
	public static int[] dx = {0, 1, 0, -1};
	
	public static int n;
	public static char[][] board;
	public static boolean[][] check;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		board = new char[n][n];
		check = new boolean[n][n];
		
		int count = 0;
		
		for(int i = 0; i < n; i++) {
			String str = br.readLine();
			for(int j = 0; j < n; j++) {
				board[i][j] = str.charAt(j);
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!check[i][j]) {
					check[i][j] = true;
					dfs(i, j, board[i][j]);
					count++;
				}
			}
		}
		
		int normal = count;
		count = 0;
		
		for(int i = 0; i < n; i++) {
			Arrays.fill(check[i], false);
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] == 'G') {
					board[i][j] = 'R';
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!check[i][j]) {
					check[i][j] = true;
					dfs(i, j, board[i][j]);
					count++;
				}
			}
		}
		
		System.out.println(normal + " " + count);
	}
	
	public static void dfs(int y, int x, char color) {
		for(int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			
			if(isValidCoord(ny, nx) && !check[ny][nx] && board[ny][nx] == color) {
				check[ny][nx] = true;
				dfs(ny, nx, color);
			}
		}
		
		
	}
	
	public static boolean isValidCoord(int y, int x) {
		return 0 <= y && y < n && 0 <= x && x < n; 
	}
	
}