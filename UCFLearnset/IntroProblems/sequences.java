package Learnset.IntroProblems;
import java.util.*;

public class sequences {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int c = scan.nextInt();
        for (int tests = 0; tests < c; tests++) {

            int n = scan.nextInt(), k = scan.nextInt();
            
            int[] arr = new int[n]; //Grab original sequence
            for (int i = 0; i < n; i++) arr[i] = scan.nextInt();

            for (int i = 0; i < k; i++) {
                int[] connect = new int[arr.length - 1];
                for (int j = 0; j < arr.length - 1; j++) connect[j] = arr[j]+arr[j+1];
                arr = connect;
            }

            for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
            System.out.println();
        }
        scan.close();
    }
}