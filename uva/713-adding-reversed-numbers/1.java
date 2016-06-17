import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            BigInteger a = sc.nextBigInteger(), b = sc.nextBigInteger();
            a = new BigInteger(new StringBuffer(a.toString()).reverse().toString());
            b = new BigInteger(new StringBuffer(b.toString()).reverse().toString());
            BigInteger ans = a.add(b);
            ans = new BigInteger(new StringBuffer(ans.toString()).reverse().toString());
            System.out.println(ans);
        }
    }
}
