public class FirstAndLastPositionOfElementInSortedArray_34 {
    public static void main(String[] args) {
        int[] nums = {5, 7, 7, 7, 7, 8, 8, 10};
        int target = 7;
        int[] ans = searchRange(nums, target);
        for(int item: ans){
            System.out.println(item);
        }
    }
    static int[] searchRange(int[] nums, int target){
        int[] ans = {-1, -1};
        int start = findIndex(nums, target, true);
        int end = findIndex(nums, target, false);
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
    static int findIndex(int[] nums, int target, boolean findStartIndex){
        int ans = 0;
        int start = 0;
        int end = nums.length - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target > nums[mid]){
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                ans = mid;
                if(findStartIndex){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
}
