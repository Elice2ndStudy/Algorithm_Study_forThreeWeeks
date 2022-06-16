package codingtest;

import java.util.*;
import java.io.*;

public class BOJ_2589 {
	public static final int[] dy = {1, 0, -1, 0};
	public static final int[] dx = {0, 1, 0, -1};

	public static int N;
	public static int M;

	public static char[][] map;

	public static int max;

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

		N = Integer.parseInt(stringTokenizer.nextToken());
		M = Integer.parseInt(stringTokenizer.nextToken());

		map = new char[N][M];

		for(int i = 0; i < N; i++){
			String word = bufferedReader.readLine();
			for(int j = 0; j < M; j++){
				map[i][j] = word.charAt(j);
			}
		}

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++){
				if(map[i][j] == 'L'){
					bfs(i, j);
				}
			}
		}

		System.out.println(max);
		bufferedReader.close();
	}

	public static void bfs(int y, int x){
		Queue<Node> queue = new LinkedList<>();
		queue.add(new Node(y, x, 0));
		boolean[][] check = new boolean[N][M];
		check[y][x] = true;

		while (!queue.isEmpty()){
			Node node = queue.poll();

			for(int i = 0; i < 4; i++){
				int ny = node.y + dy[i];
				int nx = node.x + dx[i];

				if(isValidCoord(ny, nx) && map[ny][nx] == 'L' && !check[ny][nx]){
					queue.add(new Node(ny, nx, node.cost + 1));
					check[ny][nx] = true;
				}
			}

			if(queue.isEmpty()){
				max = Math.max(max, node.cost);
				return;
			}
		}
	}

	public static boolean isValidCoord(int y, int x){
		return 0 <= y && y < N && 0 <= x && x < M;
	}
}

class Node{
	int x;
	int y;
	int cost;

	public Node(int y, int x, int cost){
		this.y = y;
		this.x = x;
		this.cost = cost;
	}
}