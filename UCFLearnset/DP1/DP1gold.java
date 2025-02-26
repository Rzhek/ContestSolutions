import java.util.*;
import java.io.*;
public class DP1gold {
    static int[][][] memo;
    public static int dp(int[] bags, int idx1, int idx2, int turn) {
        if (idx1 == idx2) return turn%2==0 ? bags[idx1] : -bags[idx1];

        if (memo[idx1][idx2][turn%2] != 0) return memo[idx1][idx2][turn%2]; 

        if (turn%2 == 0) { //Our turn
            return memo[idx1][idx2][0] = Math.max(bags[idx1]+dp(bags, idx1+1, idx2, turn+1), bags[idx2]+dp(bags, idx1, idx2-1, turn+1));
        } else { //Our partners turn
            return memo[idx1][idx2][1] = Math.min(-bags[idx1]+dp(bags, idx1+1, idx2, turn+1), -bags[idx2]+dp(bags, idx1, idx2-1, turn+1));
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int tests = Integer.parseInt(br.readLine());
        while (tests-- != 0) { //Run all tests
            int n = Integer.parseInt(br.readLine());
            memo = new int[n+1][n+1][2]; //Setup memo
            StringTokenizer st = new StringTokenizer(br.readLine());

            //Get bags of gold
            int[] bags = new int[n];
            for (int i = 0; i < n; i++) bags[i] = Integer.parseInt(st.nextToken());

            System.out.println(dp(bags, 0, n-1, 0));
        }
    }
}
