
import java.util.Scanner;

public class Coa1 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for(int i =0; i < t; i++){
			new Coa1().solve(sc);
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

		for(int i=0; i<h; i++){
			for(int j = 0; j < w; j++){
				if(map[i][j] == '#') continue;

				int c = 0;
				int k = j-1;
				
				//count to left
				while( k>=0 && map[i][k] != '#'){
					c++;
					k--;
				}
				
				if(c < 2) continue;

				c = 0;
				k = j+1;
				//count to right
				while(k<w && map[i][k] != '#'){
					c++;
					k++;
				}

				if(c < 2) continue;

				c = 0;
				k = i-1;
				//count to up
				while(k>=0 && map[k][j] != '#'){
					c++;
					k--;
				}

				if(c < 2) continue;

				c = 0;
				k = i+1;
				
				//count to bot
				while(k<h && map[k][j] != '#'){
					c++;
					k++;
				}

				if(c < 2) continue;

				count++;
			}
		}
		System.out.println(count);
	}

}
