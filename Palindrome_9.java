public class Palindrome_9 {
    static boolean isPalindrome(int x){
        String str = Integer.toString(x);
        int i = 0;
        int j = str.length() - 1;
        while(i<=j){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            }
            else{
                i = i + 1;
                j = j - 1;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int number = 1211;
        System.out.println(isPalindrome(number));
    }
}
