import java.util.*;

public class BitStrings {
    public static long fast_expo_mod(long n, long p, int m) {
        if (p == 0) return 1;

        long ans = fast_expo_mod(n, p/2, m);
        if (p % 2 == 1) {
            return ((ans*ans % m) * n) % m;
        } else {
            return ans*ans % m;
        }
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        System.out.println(fast_expo_mod(2, (long)n, (int)1e9+7));
        scan.close();
    }
}