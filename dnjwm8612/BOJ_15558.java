package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_15558 {
	public static int n, k;
	public static int[][] board;
	public static boolean[][] check;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		board = new int[2][n];
		check = new boolean[2][n];
		
		for(int i = 0; i < 2; i++) {
			board[i] = Arrays.stream(br.readLine().split(""))
	                .map(String::trim).mapToInt(Integer::parseInt).toArray();
		}
		
		System.out.println(bfs());
	}
	
	public static int bfs() {
		Queue<Node> queue = new LinkedList<Node>();
		queue.add(new Node(0, 0, 0));
		int[] dy = {0, 0, 1, -1};
		int[] dx = {1, -1, k, k};
		
		while(!queue.isEmpty()) {
			Node node = queue.poll();
			for(int i = 0; i < 4; i++) {
				int ny = dy[i] + node.y;
				int nx = dx[i] + node.x;
				if(isValidCoord(ny)) {
					if(nx >= n) {
						return 1;
					}
					if(nx > node.index && board[ny][nx] != 0 && !check[ny][nx]) {
						queue.add(new Node(ny, nx, node.index + 1));
						check[ny][nx] = true;
					}
				}
			}
		}
		return 0;
	}
	
	public static boolean isValidCoord(int y) {
		return 0 <= y && y < 2;
	}
}

class Node{
	int y;
	int x;
	int index;
	public Node(int y, int x, int index) {
		this.y = y;
		this.x = x;
		this.index = index;
	}
}
