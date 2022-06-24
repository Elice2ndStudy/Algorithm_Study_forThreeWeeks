package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class BOJ_2580 {
	public static final int max = 9;
	public static int count;
	public static int[][] map;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		map = new int[max][max];
		
		for(int i = 0; i < max; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < max; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		sudoku(0, 0);
	}
	
	public static void sudoku(int row, int col) {
		if(col == 9) {
			sudoku(row + 1, 0);
			return;
		}
		
		if(row == 9) {
			StringBuffer sb = new StringBuffer();
			for(int i = 0; i < max; i++) {
				for(int j = 0; j < max; j++) {
					if(j > 0) {
						sb.append(" ");
					}
					sb.append(map[i][j]);
				}
				if(i != 8) {
					sb.append("\n");
				}
			}
			System.out.print(sb.toString());
			System.exit(0);
		}
		
		if(map[row][col] == 0) {
			for(int i = 1; i <= max; i++) {
				if(verification(row, col, i)) {
					map[row][col] = i;
					sudoku(row, col + 1);
				}
			}
			map[row][col] = 0;
			return;
		}
		
		sudoku(row, col + 1);
	}

	public static boolean verification(int row, int col, int num) {
		
		for(int i = 0; i < max; i++) {
			if(map[row][i] == num) {
				return false;
			}
		}
		
		for(int i = 0; i < max; i++) {
			if(map[i][col] == num) {
				return false;
			}
		}
		
		int setRow = (row / 3) * 3;
		int setCol = (col / 3) * 3;
		
		for(int i = setRow; i < setRow + 3; i++) {
			for(int j = setCol; j < setCol + 3; j++) {
				if(map[i][j] == num) {
					return false;
				}
			}
		}
		
		return true;
	}
}
