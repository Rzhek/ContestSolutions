import java.io.*;
import java.util.*;

public class p010 {
    static int[][] memo;
    public static int solve(String matching, int idx) {
        if (idx >= matching.length()-1) {
            if (matching.charAt(idx) == '1') return 0;
            else return 1;
        }
        switch (matching.charAt(idx)+""+matching.charAt(idx+1)) {
            case "00": if (memo[idx][0] != -1) return memo[idx][0];
            return memo[idx][0] = Math.min(1+solve(matching.substring(0, idx)+"10"+matching.substring(idx+2, matching.length()), idx+1),
                            1+solve(matching.substring(0, idx)+"11"+matching.substring(idx+2, matching.length()), idx+1));
            case "01": if (memo[idx][1] != -1) return memo[idx][1];
            return memo[idx][1] = Math.min(1+solve(matching.substring(0, idx)+"10"+matching.substring(idx+2, matching.length()), idx+1),
                            1+solve(matching.substring(0, idx)+"00"+matching.substring(idx+2, matching.length()), idx));
            case "10": if (memo[idx][2] != -1) return memo[idx][2];
            return memo[idx][2] = solve(matching, idx+1);
            case "11": if (memo[idx][3] != -1) return memo[idx][3];
            return memo[idx][3] = solve(matching, idx+1);
        }
        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        //Get rid of middle character in odd length string (it won't matter)
        if (s.length()%2 == 1) s = s.substring(0, s.length()/2)+s.substring(s.length()/2 + 1, s.length());

        String matching = "";
        for (int i = 0; i < s.length()/2; i++) matching += (s.charAt(i) == s.charAt(s.length()-i-1)) ? 1 : 0;

        memo = new int[matching.length()+1][4];
        for (int i = 0; i < memo.length; i++) Arrays.fill(memo[i], -1);

        System.out.println(solve(matching, 0));
    }
}