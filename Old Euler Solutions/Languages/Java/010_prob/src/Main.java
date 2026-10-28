import java.util.Scanner;
import java.lang.Math;

public class Main {

    static boolean isPrime(int x) {
        if (x == 0 || x == 1) {
            return false;
        }

        for (int i = (int)Math.sqrt(x); i > 1; i--) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("Find sums of Primes up to: ");
        int cap = cin.nextInt();

        long sum = 0;

        for (int i = 1; i < cap; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }

        System.out.println("\nThe sum is " + sum);
    }
}
