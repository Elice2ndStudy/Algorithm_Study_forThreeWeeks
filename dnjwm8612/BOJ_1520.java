package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1520 {
	public static int[] dy = {1, 0, -1, 0};
	public static int[] dx = {0, 1, 0, -1};

	public static int m, n;
	public static int[][] board;
	public static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		board = new int[m][n];
		dp = new int[m][n];

		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
			Arrays.fill(dp[i], -1);
		}

		
		System.out.println(bfs(0, 0));
	}

	public static int bfs(int y, int x) {
		if(y == m - 1 && x == n - 1) {
			return 1;
		}

		if(dp[y][x] == -1) {
			dp[y][x] = 0;
			for(int i = 0; i < 4; i++) {
				int ny = dy[i] + y;
				int nx = dx[i] + x;

				if(isValidCoord(ny, nx) && board[ny][nx] < board[y][x]) {
					dp[y][x] += bfs(ny, nx);
				}
			}
		}else {
			return dp[y][x]; 
		}
		return dp[y][x];
	}

	public static boolean isValidCoord(int y, int x) {
		return 0 <= y && y < m && 0 <= x && x < n; 
	}
}

class Node{
	int y;
	int x;

	public Node(int y, int x) {
		this.y = y;
		this.x = x;
	}
}
