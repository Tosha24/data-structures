public class SquareRoot_69 {
    public static void main(String[] args) {
        int number = 4;
        int ans = squareRoot(number);
        System.out.println(ans);
    }
    static int squareRoot(int number){
        int start = 0;
        int end = number/2 + 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int square = mid * mid;
            if(square == number){
                return mid;
            }
            else if(square < number){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return end;
    }
}
