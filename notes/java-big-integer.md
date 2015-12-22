# Java

### Basics
```java
import java.util.Scanner;
import java.math.BigInteger;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double f = sc.nextDouble;
        System.out.println(n);
    }
}
```

### Java BigInteger

#### Library
```java
import java.math.BigInteger;
```

#### Input from stdin
```java
BigInteger bi = sc.nextBigInteger();
```

#### Constants
```java
BI.ZERO;
BI.ONE;
BI.TEN;
```

### Methods
```java
BI.valueOf(int);
BI.intValue();

BI.add(BI b); // a + b
BI.subtract(BI b); // a - b
BI.multiply(BI b); // a * b
BI.divide(BI b); // a / b
BI.pow(int p); // a ^ p
BI.remainder(BI m); // a % m
BI.mod(BI m); // a % m
BI.modInverse(BI m); // a^-1 % m
BI.modPow(BI p, BI m); // a^p % m
BI.negate(); // -a

BI.not(); // ~a
BI.and(BI b); // a & b
BI.andNot(BI b); // a & ~b
BI.or(BI b); // a | b
BI.xor(BI b);
BI.shiftLeft(int n); // a << n
BI.shiftRight(int n); // a >> n

BI.max(BI b); // max(a, b)
BI.min(BI b); // min(a, b)

BI.toString(int b); // to base convertor
BI.isProbablePrime(int c); // check for prime with probability = 1 - 1/2 ^ c; c = 10 is enough
BI.gcd(BI b); // gcd(a, b)
```

* `BI` refers to `BigInteger`
* `a` refers to `this`;
