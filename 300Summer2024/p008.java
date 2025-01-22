import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Comparator;
import java.util.PriorityQueue;

public class p008 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());

        int[][] days = new int[n][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            days[i][0] = Integer.parseInt(st.nextToken());
            days[i][1] = Integer.parseInt(st.nextToken());
        }

        int res = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {public int compare(Integer a, Integer b) {return Integer.compare(b,a);}}); //Sorts in decreasing order

        int prevVisit = 0;
        for (int i = 0; i < d; i++) {
            int visit = Integer.parseInt(br.readLine());

            int mess = 0;
            for (int j = visit-1; j >= prevVisit; j--) {
                mess += days[j][0];
                pq.add(days[j][1]);
                while (mess > 0) {
                    if (pq.isEmpty()) {
                        System.out.println(-1);
                        return;
                    }
                    mess -= pq.poll();
                    res++;
                }
            }
            pq.clear();
            prevVisit = visit;
        }
        System.out.println(res);
    }
}