package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ_15686 {
	public static int n, m, answer;

	public static boolean[] check;
	public static List<Node> house, chicken;

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		answer = Integer.MAX_VALUE;

		house = new ArrayList<>();
		chicken = new ArrayList<>();

		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) {
				int index = Integer.parseInt(st.nextToken());
				if(index == 1) {
					house.add(new Node(i, j));
				} else if(index == 2) {
					chicken.add(new Node(i, j));
				}
			}
		}

		check = new boolean[chicken.size()];
		backTracking(0, 0);
		System.out.println(answer);
	}

	public static void backTracking(int count, int index) {
		if(count == m) {
			int sum = 0;
			for(int i = 0; i < house.size(); i++) {
				int houseY = house.get(i).y;
				int houseX = house.get(i).x;
				int min = Integer.MAX_VALUE;

				for(int j = 0; j < chicken.size(); j++) {
					if(check[j]) {
						int chickenY = chicken.get(j).y;
						int chickenX = chicken.get(j).x;
						min = Math.min(getDist(houseY, houseX, chickenY, chickenX), min);
					}
				}
				sum += min;
				if(sum > answer) {
					return;
				}
			}
			answer = Math.min(sum, answer);
			return;
		}

		for(int i = index; i < chicken.size(); i++) {
			if(!check[i]) {
				check[i] = true;
				backTracking(count + 1, i + 1);
				check[i] = false;
			}
		}
	}

	public static int getDist(int houseY, int houseX, int chickenY, int chickenX) {
		return Math.abs(houseY - chickenY) + Math.abs(houseX - chickenX);
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