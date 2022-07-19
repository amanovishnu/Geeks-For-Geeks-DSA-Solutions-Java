// WAP to count the  no of digits in a number n given (n>=0) ?
import java.lang.Math;

class countDigits {

    // Approach #1
    static int countApproach1(int n) {
        int result = 0;
        while (n > 0) {
            n = n / 10;
            result++;
        }
        return result;
    }

    // Approach #2
    static int countApproach2(int n) {
        if (n==0)
            return 0;
        else
            return (1+countApproach2(n/10));
    }

    // Approach #3
    static int countApproach3(double n){
        return (int)Math.floor(Math.log10(n))+1;
    }

    public static void main(String[] args) {
        int input = 123456;
        System.out.println(countApproach1(input));
        System.out.println(countApproach2(input));
        System.out.println(countApproach3(input));
    }
}
