public class FindInMountainArray_1095 {
    public static void main(String[] args) {
        int[] nums = {0, 1, 2, 4, 3, 2, 1};
        int target = 3;
        int peak = findMinIndex(nums);
        int asc = binarySearch(nums, target, 0, peak);
        int desc = binarySearch(nums, target, peak + 1, nums.length - 1);
        if(asc < desc){
            System.out.println(asc);
        }
        else if(asc > desc){
            System.out.println(desc);
        }
        else{
            System.out.println(-1);
        }
    }
    static int findMinIndex(int[] nums){
        int start = 0;
        int end = nums.length - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid + 1]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
    static int binarySearch(int[] nums, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[start] < nums[end]){
                if(nums[mid] > target){
                    end = mid - 1;
                }
                else if(nums[mid] < target){
                    start = mid + 1;
                }
                else{
                    return mid;
                }
            }
            else{
                if(nums[mid] > target){
                    start = mid + 1;
                }
                else if(nums[mid] < target){
                    end = mid - 1;
                }
                else{
                    return mid;
                }
            }
        }
        return Integer.MAX_VALUE;
    }
}
