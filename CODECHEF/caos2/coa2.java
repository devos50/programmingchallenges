package Aug2013;

import java.util.Scanner;

public class coa2 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for(int i =0; i < t; i++){
			new coa2().solve(sc);
		}

	}

	public void solve(Scanner sc){

		int count = 0;

		int h = sc.nextInt();
		int w = sc.nextInt();

		char[][] map = new char[h][w];
		for(int i=0; i<h; i++){
			map[i] = sc.next().toCharArray();
		}

		int[][] up = new int[h][w];
		int[][] down = new int[h][w];
		int[][] left = new int[h][w];
		int[][] right = new int[h][w];

		// Bereken waardes van links af
		for(int i = 0; i<h; i++){
			for(int j=1; j<w; j++){
				if(map[i][j-1] == '#' || map[i][j] == '#') continue;
				else left[i][j] = left[i][j-1] + 1;
			}
		}

		// Bereken waardes van rechts af
		for(int i = 0; i<h; i++){
			for(int j=w-2; j>=0; j--){
				if(map[i][j+1] == '#' || map[i][j] == '#') continue;
				else right[i][j] = right[i][j+1] + 1;
			}
		}

		// Bereken waardes van boven af
		for(int i = 0; i<w; i++){
			for(int j=1; j<h; j++){
				if(map[j-1][i] == '#' || map[j][i] == '#') continue;
				else up[j][i] = up[j-1][i] + 1;
			}
		}

		// Bereken waardes van onder af
		for(int i = 0; i<w; i++){
			for(int j=h-2; j>=0; j--){
				if(map[j+1][i] == '#' || map[j][i] == '#') continue;
				else down[j][i] = down[j+1][i] + 1;
			}
		}
		
		
		for(int i = 2; i<h-2; i++){
			for(int j=2; j<w-2; j++){
				if(map[i][j] == '#') continue;
				if(up[i][j] < 2 || down[i][j] < 2 || left[i][j] < 2 || right[i][j] < 2) continue;
				else count++;
			}
		}
		
		
		for(int i = 0; i<h; i++){
			for(int j=0; j<w; j++){
				System.out.print(Math.min(up[i][j], Math.min(down[i][j], Math.min(left[i][j], right[i][j]))) + " ");
			}
			System.out.println();
		}
		

		System.out.println(count);
	}

}
