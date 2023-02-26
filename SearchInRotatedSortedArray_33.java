public class SearchInRotatedSortedArray_33 {
    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int start = 0;
        int end = nums.length - 1;
        int pivot = findPivot(nums, start, end);
        if(target >= nums[start]){
            int ans = binarySearch(nums, target, start, pivot);
            System.out.println(ans);
        }
        else if(target <= nums[end]){
            int ans = binarySearch(nums, target, pivot + 1, end);
            System.out.println(ans);
        }
        else{
            System.out.println(-1);
        }
    }
    static int findPivot(int[] nums, int start, int end){
        while(start < end){
            int mid = start + (end - start)/2;
            if(mid < end && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(nums[mid] >= nums[start]){
                start = mid + 1;
            }
            else if(nums[mid] <= nums[end]){
                end = mid - 1;
            }
        }
        return start;
    }
    static int binarySearch(int[] nums, int target, int start, int end){
//        if(start == end){
//            if(target == nums[start]){
//                return start;
//            }
//            else{
//                return -1;
//            }
//        }
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target > nums[mid]){
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
}