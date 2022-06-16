package codingtest;

import java.util.*;
import java.io.*;

public class BOJ_2573 {
    public static final int[] dy = {1, 0, -1, 0};
    public static final int[] dx = {0, 1, 0, -1};

    public static int N;
    public static int M;
    public static int year;
    public static int[][] map;
    public static int[][] melt;
    public static boolean[][] check;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());
        map = new int[N][M];
        melt = new int[N][M];

        for(int i = 0; i < N; i++){
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());

            for(int j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }



        while (true){
            int cnt = 0;
            check = new boolean[N][M];

            melting();
            
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++){
                    if(map[i][j] != 0 && !check[i][j]){
                        is_zone(i, j);
                        cnt++;
                    }
                }
            }

            if(cnt == 0){
                System.out.println(0);
                break;
            } else if(cnt >= 2){
                System.out.println(year);
                break;
            }

            year++;
        }

        bufferedReader.close();
    }

    public static void is_zone(int y, int x){
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(new Node(y, x));
        check[y][x] = true;

        while (!queue.isEmpty()){
            Node node = queue.poll();
            for(int i = 0; i < 4; i++){
                int ny = node.y + dy[i];
                int nx = node.x + dx[i];

                if(isValidCoord(ny, nx)){
                    if(map[ny][nx] > 0 && !check[ny][nx]){
                        queue.add(new Node(ny, nx));
                        check[ny][nx] = true;
                    }else if(map[ny][nx] == 0){
                        melt[node.y][node.x]++;
                    }
                }
            }
        }
    }

    public static void melting(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] -= melt[i][j];
                if(map[i][j] < 0){
                   map[i][j] = 0;
                }
                melt[i][j] = 0;
            }
        }


    }

    public static boolean isValidCoord(int y, int x){
        return 0 <= y && y < N && 0 <= x && x < M;
    }

}
//
//class Node{
//    int x;
//    int y;
//
//    public Node(int y, int x){
//        this.y = y;
//        this.x = x;
//    }
//}

