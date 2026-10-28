/*
    Find the 10 001st prime number
*/

import java.util.Scanner;

public class Main {
    static boolean isPrime(long x) {
        if (x == 0 || x == 1) {
            return false;
        }

        for (int i = (int)Math.sqrt(x); i > 1; i--) {
            if(x % i == 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("What number location of prime do you want to find? ");
        int num = cin.nextInt();

        int count = 0; long prime = 0;

        do {
            if(isPrime(++prime)) {
                count++;
            }
        } while(count < num);

        System.out.println();
        System.out.println("The prime number at location, " + num + ", is " + prime);
    }
}
