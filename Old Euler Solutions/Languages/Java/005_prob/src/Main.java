/*
    2520 is the smallest number that can be divided by
    each of the numbers from 1 to 10 without any remainder.

    What is the smallest positive number that is evenly
    divisible by all the numbers from 1 to 20?
*/

public class Main {
    static boolean div(long x) {
        for (int i = 1; i < 21; i++) {
            if (x % i != 0) {
                return false;
            }
        }
        return true;
    }

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
        long largest = 1;

        for (int i = 0; i < 20; i++) {
            if (isPrime(i)) {
                largest *= i;
            }
        }

        while(!div(largest)) {
            largest++;
        }

        System.out.println("The largest positive is " + largest);
    }
}
