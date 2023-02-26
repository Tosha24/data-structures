public class SplitArrayLargestSum_410 {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        int m = 2;
        System.out.println(splitArray(nums, m));
    }
    static int splitArray(int[] nums, int m){
        int start = maximumInArray(nums);
        int end = sumOfArray(nums);
        while(start < end){
            int mid = start + (end - start)/2;      // 10 - 15 - 21
            int pieces = findPieces(nums, mid);     // pieces = 2
            if(pieces <= m){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
    static int findPieces(int[] nums, int mid){
        int sum = 0;
        int pieces = 0;
        int i = 0;
        while(i < nums.length){
            if(sum + nums[i] <= mid){
                sum = sum + nums[i];
                i = i + 1;
            }
            else{
                pieces = pieces + 1;
                sum = 0;
            }
        }
        return pieces + 1;
    }
    static int maximumInArray(int[] nums){
        int max = 0;
        for(int i:nums){
            if(i > max){
                max = i;
            }
        }
        return max;
    }
    static int sumOfArray(int[] nums){
        int sum = 0;
        for(int i: nums){
            sum = sum + i;
        }
        return sum;
    }
}
