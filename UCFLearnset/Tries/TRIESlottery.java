import java.util.*;
import java.io.*;

public class TRIESlottery {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int lot = Integer.parseInt(br.readLine());
        for (int a = 1; a <= lot; a++) {
            HashMap<String, Integer>[] map = new HashMap[2];
            for (int i = 0; i < 2; i++) map[i] = new HashMap<String, Integer>();

            int reversal = 0;
            int q = Integer.parseInt(br.readLine());

            pw.printf("Lottery #%d:\n", a);
            for (int i = 0; i < q; i++) {
                

                StringTokenizer st = new StringTokenizer(br.readLine());
                int cmd = Integer.parseInt(st.nextToken());
                String s = "";

                if (cmd != 3) s = st.nextToken();
                switch (cmd) {
                    case 1:
                        String normal = "", reversed = "";
                        for (int j = 0; j < s.length(); j++) {
                            normal += s.charAt(j);
                            reversed += s.charAt(s.length()-j-1);

                            
                            if (map[reversal].get(normal) == null) map[reversal].put(normal, 1);
                            else map[reversal].put(normal, map[reversal].get(normal)+1);

                            reversal = (reversal+1)%2;
                            if (map[reversal].get(reversed) == null) map[reversal].put(reversed, 1);
                            else map[reversal].put(reversed, map[reversal].get(reversed)+1);

                            reversal = (reversal+1)%2;
                        }
                    break;
                    case 2: pw.println(map[reversal].get(s) == null ? 0 : map[reversal].get(s));
                    break;
                    case 3: reversal = (reversal+1)%2;
                    break;
                }
            }
            pw.println();
        }

        pw.close();
        br.close();
    }
}