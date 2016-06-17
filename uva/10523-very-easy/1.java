import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            BigInteger a = sc.nextBigInteger();
            BigInteger ans = BigInteger.ZERO;
            for (int i = 1; i <= n; i++) {
                ans = ans.add(BigInteger.valueOf(i).multiply(a.pow(i)));
            }
            System.out.println(ans);
        }
    }
}
