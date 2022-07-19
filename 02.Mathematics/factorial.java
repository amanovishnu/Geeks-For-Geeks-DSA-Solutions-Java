class factorial {

    // Iterative Approach
    static int iterativeFactorial(int input) {
        int result = 1;
        if(input == 1 || input == 0)
            return result;
        for(int i=2; i<=input; i++)
            result = result*i;
        return result;
    }

    // Recursive Approach
    static int recursiveFactorial(int input) {
        if (input == 0)
            return 1;
        else
            return input*recursiveFactorial(input-1);
    }

    public static void main(String[] args) {
        System.out.println(iterativeFactorial(0));
        System.out.println(recursiveFactorial(0));
    }
}
