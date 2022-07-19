// WAP to check given a number (n>0) is palindrome or not ?
class palindrome {

    static boolean isPalindrome(int input_num) {
        int temp_num = input_num;
        int rev_num = 0;
        while(temp_num > 0) {
            rev_num = rev_num*10+(temp_num%10);
            temp_num = temp_num/10;
        }
        return (input_num == rev_num);
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome(234));
        System.out.println(isPalindrome(121));
        System.out.println(isPalindrome(8));
    }
}
