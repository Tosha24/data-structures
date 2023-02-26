public class FindNumberOfEvenDigit_1295 {
    public static void main(String[] args) {
        int[] nums = {12,345,22,6,7896};
        System.out.println(findNumber(nums));
    }
    static int findNumber(int[] nums){
        int count = 0;
        for(int item : nums){
            if(even(item)){
                count += 1;
            }
        }
        return count;
    }
    static boolean even(int num){
        int numberOfDigits = digits(num);
        return (numberOfDigits%2==0);
    }
    static int digits(int num){
        return ((int)(Math.log10(num)) + 1);
    }
}
