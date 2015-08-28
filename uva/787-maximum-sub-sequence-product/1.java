import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;

class Main {

    private static BigInteger minimum;
    private static void init() {
        minimum = BigInteger.valueOf(-100000).pow(101);
    }

    public static void main(String[] args) {
        init();
        Scanner cin = new Scanner(System.in);
        ArrayList<BigInteger> v = new ArrayList<BigInteger>();
        boolean hasZero = false;
        BigInteger ans = minimum;
        while (cin.hasNext()) {
            int tmp = cin.nextInt();
            if (tmp == -999999) {
                System.out.println(ans.max(max_prod(v)));
                ans = minimum;
                v.clear();
                continue;
            }
            if (tmp == 0) {
                ans = BigInteger.ZERO;
                ans = ans.max(max_prod(v));
                v.clear();
                continue;
            }
            v.add(BigInteger.valueOf(tmp));
        }
    }

    private static BigInteger max_prod(ArrayList<BigInteger> v) {
        if (v.isEmpty())
            return minimum;
        BigInteger ans = v.get(0);
        ArrayList<BigInteger> dp = new ArrayList<BigInteger>();
        for (int i = 0; i < v.size(); i++) {
            dp.add(BigInteger.ONE);
            for (int j = 0; j <= i; j++) {
                dp.set(i, dp.get(i).multiply(v.get(j)));
            }
        }

        for (int i = 0; i < v.size(); i++) {
            ans = ans.max(dp.get(i));
            for (int j = 0; j < i; j++)
                ans = ans.max(dp.get(i).divide(dp.get(j)));
        }

        return ans;
    }
}