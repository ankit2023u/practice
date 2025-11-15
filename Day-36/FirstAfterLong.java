class FirstAfterLong
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        // Calling sumEven with different ranges to test correctness
        System.out.println(sumEven(1, 3));   // Expected: 2
        System.out.println(sumEven(2, 3));   // Expected: 2
        System.out.println(sumEven(5, 10));  // Expected: 24 (6 + 8 + 10)
        System.out.println(sumEven(-5, 10)); // Expected: 24 (−4 + −2 + 0 + 2 + 4 + 6 + 8 + 10)
    }
    
    // Function to compute the sum of all even numbers between a and b (inclusive)
    public static int sumEven(int a, int b){
        
        // If 'a' is odd, move it to the next even number
        if(a % 2 != 0) a = a + 1;
        
        int sum = 0;

        // Loop from the first even number up to 'b', jumping by 2 each time
        for(int i = a; i <= b; i += 2){
            sum += i;  // accumulate only even numbers
        }
        
        return sum; // return the final computed sum
    }
}
