import java.util.*;
import java.io.*;

public class p016 {
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken());
        ArrayList<Double[]> points = new ArrayList<Double[]>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            Double[] point = new Double[4];
            point[0] = point[2] = Double.parseDouble(st.nextToken());
            point[1] = point[3] = Double.parseDouble(st.nextToken());
            points.add(point);
        }
        solve(points, (double)s);
        pw.close();
    }

    public static void solve(ArrayList<Double[]> points, double s) {
        if (points.size() == 1) pw.println((int)Math.floor(points.get(0)[2])+" "+(int)Math.floor(points.get(0)[3]));
        if (points.size() <= 1) return;

        s /= 2;
        ArrayList<ArrayList<Double[]>> quadrents = new ArrayList<>();
        for (int i = 0; i < 4; i++) quadrents.add(new ArrayList<Double[]>());

        for (int i = 0; i < points.size(); i++) {
            double x = points.get(i)[0], y = points.get(i)[1];
            Double ogX = points.get(i)[2], ogY = points.get(i)[3];

            if (x <= s && y < s) quadrents.get(0).add(new Double[]{y, x, ogX, ogY});
            else if (x < s && y >= s) quadrents.get(1).add(new Double[]{x, y-s, ogX, ogY});
            else if (x >= s && y >= s) quadrents.get(2).add(new Double[]{x-s, y-s, ogX, ogY});
            else quadrents.get(3).add(new Double[]{s-y, s*2-x, ogX, ogY});
        }
        for (int i = 0; i < quadrents.size(); i++) solve(quadrents.get(i), s);
        
    }
}