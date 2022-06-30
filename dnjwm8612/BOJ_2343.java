package codingtest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2343 {
	public static int[] array;
	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

		int N = Integer.parseInt(stringTokenizer.nextToken());
		int M = Integer.parseInt(stringTokenizer.nextToken());
		int min = 0;
		int max = 0;

		array = new int[N];

		stringTokenizer = new StringTokenizer(bufferedReader.readLine());

		for(int i = 0; i < N; i++){
			array[i] = Integer.parseInt(stringTokenizer.nextToken());
			max += array[i];
			if(min < array[i]){
				min = array[i];
			}
		}

		while (min <= max){
			int mid = (min + max) / 2;
			int result = blueray(mid, N, M);

			if(result == -1){
				min = mid + 1;
			}else if(result == 0){
				max = mid - 1;
			}else if(result == 1){
				max = mid - 1;
			}
		}

		System.out.println(min);

	}

	// -1 : 해당 크기로 블루레이를 횟수 만큼으로 나눌수 없음
	// 0 : 가능
	// 1 : 블루레이 나누는 크기가 크다
	public static int blueray(int mid, int n, int m){
		int count = 1;
		int temp = 0;

		for(int i = 0; i < n; i++){
			if(temp + array[i] > mid){
				count++;
				temp = 0;

				if(count > m){
					return -1;
				}
			}

			temp += array[i];
		}

		return count == m ? 0 : 1;
	}
}
