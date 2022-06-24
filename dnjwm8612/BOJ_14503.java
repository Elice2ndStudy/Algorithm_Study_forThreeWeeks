package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14503 {
	public static final int[] dy = {-1, 0, 1, 0};
	public static final int[] dx = {0, 1, 0, -1};
	public static int n, m, cnt;
	
	public static int[][] map;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		
		st = new StringTokenizer(br.readLine());
		int row = Integer.parseInt(st.nextToken());
		int col = Integer.parseInt(st.nextToken());
		int dir = Integer.parseInt(st.nextToken());
		
		
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken()); 
			}
		}
		
		cleanFloor(row, col, dir);
		
		System.out.println(cnt);
	}
	
	public static void cleanFloor(int row, int col, int dir) {
		if(map[row][col] == 0) {
			map[row][col] = 2;
			cnt++;
		}
		
		boolean check = false;
		int initDir = dir; 
		for(int i = 0 ; i < 4; i++) {
			int nextDir = (dir + 3) % 4;
			int ny = dy[nextDir] + row;
			int nx = dx[nextDir] + col;
			
			if(isValidCoord(ny, nx) &&  map[ny][nx] == 0) {
				cleanFloor(ny, nx, nextDir);
				check = true;
				break;
			}
			dir = nextDir;	
		}
		
		if(!check) {
			int backDir = ( initDir + 2 ) % 4;
			int ny = dy[backDir] + row;
			int nx = dx[backDir] + col;
			
			if(isValidCoord(ny, nx) && map[ny][nx] != 1) {
				cleanFloor(ny, nx, initDir);
			}
		}
		
	}
	
	public static boolean isValidCoord (int row, int col) {
		return 0 < row && row < n && 0 < col && col < m;
	}
}
