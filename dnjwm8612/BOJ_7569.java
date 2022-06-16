package codingtest;

import java.io.*;
import java.util.*;

public class BOJ_7569 {
	public static int[] dy = {1, 0, -1, 0, 0, 0};
	public static int[] dx = {0, 1, 0, -1, 0, 0};
	public static int[] dz = {0, 0, 0, 0, 1, -1};
	
	public static int m, n, h;
	public static int[][][] board;
	public static StringTokenizer st;
	public static Queue<Node> queue;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		board = new int[h][n][m];
		queue = new LinkedList<Node>();
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < n; j++) {
					st = new StringTokenizer(br.readLine());
				for(int t = 0; t < m; t++) {
					int state = Integer.parseInt(st.nextToken());					
					board[i][j][t] = state;
					if(state == 1) {
						queue.add(new Node(j, t, i, 0));
					}
				}
			}
		}
		
		if(queue.isEmpty()) {
			for(int i = 0; i < h; i++) {
				for(int j = 0; j < n; j++) {
					for(int t = 0; t < m; t++) {
						if(board[i][j][t] == 0) {
							System.out.println(-1);
							return;
						}
					}
				}
			}
			System.out.println(0);
			return;
		}
		
		int result = bfs();
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < n; j++) {
				for(int t = 0; t < m; t++) {
					if(board[i][j][t] == 0) {
						System.out.println(-1);
						return;
					}
				}
			}
		}
		
		System.out.print(result);
		
	}
	
	public static int bfs() {
		int cost = 0;
		while(!queue.isEmpty()) {
			Node node = queue.poll();
			for(int i = 0; i< 6; i++) {
				int ny = node.y + dy[i];
				int nx = node.x + dx[i];
				int nz = node.z + dz[i];
				
				if(isValidCoord(ny, nx, nz) && board[nz][ny][nx] == 0) {
					queue.add(new Node(ny, nx, nz, node.cost + 1));
					board[nz][ny][nx] = 1;
				}
			}
			cost = node.cost; 
		}
		
		return cost;
	}
	
	public static boolean isValidCoord(int y, int x, int z) {
		return 0 <= y && y < n && 0 <= x && x < m && 0 <= z && z < h; 
	}

}


class Node{
	int y;
	int x;
	int z;
	int cost;
	
	public Node(int y, int x, int z, int cost) {
		this.y = y;
		this.x = x;
		this.z = z;
		this.cost = cost;
	}
	
}