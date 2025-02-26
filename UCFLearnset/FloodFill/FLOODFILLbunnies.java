import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FLOODFILLbunnies {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        while (tests-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());

            int[] cordPeter = {0, 0}, cordCotton = {0, 0};
            char[][] grid = new char[r][c];
            for (int i = 0; i < r; i++) {
                String row = br.readLine();
                for (int j = 0; j < c; j++) {
                    grid[i][j] = row.charAt(j);
                    if (grid[i][j] == 'P') { //Found peter rabbit position
                        cordPeter[0] = i;
                        cordPeter[1] = j;
                    } else if (grid[i][j] == 'C') {//Found cottontail rabbit position
                        cordCotton[0] = i;
                        cordCotton[1] = j;
                    }
                }
            }
            floodFill(grid, cordPeter);
            if (grid[cordPeter[0]][cordPeter[1]] == grid[cordCotton[0]][cordCotton[1]]) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

    }
    public static void floodFill(char[][] grid, int[] pos) {
        int i = pos[0], j = pos[1];
        if (grid[i][j] == '#') return;
        grid[i][j] = '#';
        
        if (i+1 < grid.length) floodFill(grid, new int[]{i+1, j});
        if (i-1 >= 0) floodFill(grid, new int[]{i-1, j});
        if (j+1 < grid[i].length) floodFill(grid, new int[]{i, j+1});
        if (j-1 >= 0) floodFill(grid, new int[]{i, j-1});
        return;
    }
}