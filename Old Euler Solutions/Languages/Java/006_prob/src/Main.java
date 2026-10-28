/*
    Find the difference between the sum of the squares of
    the first one hundred natural numbers and the square of the sum.
*/

import java.util.Scanner;

public class Main {
    static long sumSq(int x) {
        if (x == 1) {
            return 1;
        }

        return (long)Math.pow(x,2) + sumSq(x-1);
    }

    static long sqSum(int x) {
        long sum = 0;
        for (int i = x; i > 0; i--) {
            sum += i;
        }

        return (long)Math.pow(sum,2);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int find_num = cin.nextInt();

        System.out.println();

        System.out.println("Difference between the sum of the squares of the first " + find_num + " natural numbers");
        System.out.println("and the square of the sum of the first " + find_num + " natural numbers is "
                + (sqSum(find_num) - sumSq(find_num)) + '.');

    }
}
