public class FindSmallestLetterGreaterThanTarget_744 {
    public static void main(String[] args) {
        char[] letters = {'x', 'x', 'y', 'y'};
        char target = 'z';
        System.out.println(nextLetter(letters, target));
    }
    static char nextLetter(char[] letters, char target){
        if(target > letters[letters.length - 1]){
            return letters[0];
        }
        int start = 0;
        int end = letters.length - 1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(target > letters[mid]){
                start = mid + 1;
            }
            else if(target < letters[mid]){
                end = mid - 1;
            }
            else {
                start = start + 1;
                break;
            }
        }
        return letters[start];
    }
}
