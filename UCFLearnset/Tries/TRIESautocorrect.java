/*
 * Author: Leonard Gofman
 * Best Regards
 */

import java.util.*;
import java.io.*;

public class TRIESautocorrect {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        
        Trie t = new Trie();
        for (int i = 0; i < n; i++) t.insert(br.readLine()); //Insert into dictionary

        for (int i = 0; i < m; i++) {
            String str = br.readLine();
            String typing = "";

            int res = 0;
            for (int j = 0; j < str.length(); j++) { //Start typing our word
                typing += str.charAt(j);
                res++;

                int[] autocorrect = t.search(typing, str);
                int gain = autocorrect[0], loss = autocorrect[1];
        
                if (gain >= loss) res += loss; //If the autocorrect helps us
                else res += gain; //the autocorrect is useless

                typing += str.substring(j+1, j+1+gain);
                j = j+gain; //j will add to itself on the next iteration so no +1
            }
            System.out.println(res);
        }
    }    
}

class Trie {
    class Node {
        Node[] nodes;
        char popularLetter;
        boolean isWord;
        public Node() {
            nodes = new Node[26];
            popularLetter = ' ';
            isWord = false;
        }

        public void insert(String str, int idx) {
            if (idx == str.length()) { //Base case
                if (popularLetter == ' ') isWord = true;
                return;
            }
            if (popularLetter == ' ') popularLetter = str.charAt(idx); //letter of most common word
            int letterIdx = str.charAt(idx)-'a'; //Index of the letter for the node list
            if (nodes[letterIdx] == null) nodes[letterIdx] = new Node();
            nodes[letterIdx].insert(str, idx+1); 
            return;
        }

        public int[] search(String str, String fullStr, int idx, int gains, int loss) {
            if (popularLetter == ' ') return new int[]{gains, loss};

            if (idx < str.length()) {
                if (nodes[str.charAt(idx)-'a'] == null) return new int[]{gains, gains}; //Since we couldn't find a word
                return nodes[str.charAt(idx)-'a'].search(str, fullStr, idx+1, gains, loss);
            }
            if (isWord) return new int[]{gains, loss};

            if (loss > 1) loss++;
            else if (idx < fullStr.length() && fullStr.charAt(idx) == popularLetter) gains++;
            else loss++;

            return nodes[popularLetter-'a'].search(str, fullStr, idx+1, gains, loss); //Search the popular letter
        }
    }
    Node root;
    public Trie() {root = new Node();}
    public void insert(String str) {root.insert(str, 0);}
    public int[] search(String str, String fullStr) {return root.search(str, fullStr, 0, 0, 1);}
}
