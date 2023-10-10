// Problem: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// For eg: Input: x = 8  ==>  Output: 2   (although sqrt(8) is 2.82842... we round it to the nearest integer)

// Approach: Binary Search
/* Solution:
 * Here we apply binary search on the range of the answer. Like if we have x = 8 then we know that the square root of 8 is smaller than half the number x. So we search for the value of answer between 0 to x/2. And for each mid, we square it and check if it is equal to the number x. If it is we return mid, else if the square is smaller than the number x, we move start pointer ahead one step, else decrease the end pointer. And at last when start and end pointer crosses each other, we return end so that our answer is the ceil value and not the floor value. 
 */

public class _69_SquareRoot {
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
    public static void main(String[] args) {
        int number = 4;
        int ans = squareRoot(number);
        System.out.println(ans);
    }
}

// Time Complexity: O(logn)
// Space Complexity: O(1)