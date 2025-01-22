import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class Permutations {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        ArrayList<Integer> res = IntStream.rangeClosed(1, n).boxed()
                                .sorted((a, b) -> {
                                    //Sort by even first, odd second, else in ascending order
                                    if (a%2 == 1 && b%2 == 0) return 1;
                                    else if (a%2 == 0 && b%2 == 1) return -1;
                                    return a-b; 
                                })
                                .collect(Collectors.toCollection(ArrayList<Integer>::new));

        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        if (n > 3 || n == 1) {
            Iterator<Integer> iter = res.iterator();
            while (iter.hasNext()) pw.print(iter.next()+" ");
            pw.println();
        } else {
            pw.print("NO SOLUTION");
        }
        pw.close();
        scan.close();
    }
}