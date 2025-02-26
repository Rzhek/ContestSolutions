import java.util.*;
import java.io.*;
public class DFSBFScalc {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        while (n-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            boolean[] seen = new boolean[(int)1e7];
            Queue<Integer[]> q = new LinkedList<>();
            q.add(new Integer[]{0, 0});

            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            int ans = -1;
            while (!q.isEmpty()) {
                Integer[] takeQ = q.poll();
                int val = takeQ[0];
                if (seen[val]) continue;
                seen[val] = true;

                int[] vals = {(val+a)%(int)1e6, (val*b)%(int)1e6, (val/c)%(int)1e6};
                for (int i = 0; i < vals.length; i++) {
                    if (vals[i] == t) {
                        ans = takeQ[1]+1;
                        break;
                    }
                }
                if (ans != -1) break;
                for (int i = 0; i < vals.length; i++) q.add(new Integer[]{vals[i], takeQ[1]+1});
            }
            System.out.println(ans);
        }

    }
}
