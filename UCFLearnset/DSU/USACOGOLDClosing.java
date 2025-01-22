package Learnset.DSU;
import java.util.*;
import java.io.*;

class DSU {
    int[] siz, par;

    public DSU(int n) {
        siz = new int[n];
        par = new int[n];
        for (int i = 0; i < n; i++) {
            siz[i] = 1;
            par[i] = i;
        }
    }

    public int find(int a) {
        if (par[a] != a)
            par[a] = find(par[a]);
        return par[a];
    }

    public boolean join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (siz[a] < siz[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        par[b] = a;
        siz[a] += siz[b];
        return true;
    }
}

public class USACOGOLDClosing {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("closing.in"));
	    PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("closing.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adjList.add(new ArrayList<Integer>());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int con1 = Integer.parseInt(st.nextToken()) - 1, con2 = Integer.parseInt(st.nextToken()) - 1;
            adjList.get(con1).add(con2);
            adjList.get(con2).add(con1);
        }

        Stack<Integer> stk = new Stack<Integer>();
        for (int i = 0; i < n; i++) stk.push(Integer.parseInt(br.readLine())-1);

        DSU set = new DSU(n);

        Stack<String> resStk = new Stack<>();
        int res = 1;
        boolean[] existers = new boolean[n];
        while (!stk.isEmpty()) {
            int barn = stk.pop();
            existers[barn] = true;

            int len = adjList.get(barn).size();
            for (int i = 0; i < len; i++) {
                if (existers[adjList.get(barn).get(i)]) {
                    if (set.join(barn, adjList.get(barn).get(i))) res++;
                }
            }
            if (res >= (n-stk.size())) resStk.push("YES");
            else resStk.push("NO");
        }
        while (!resStk.isEmpty()) pw.println(resStk.pop());
        pw.close();
        br.close();
    }
}
