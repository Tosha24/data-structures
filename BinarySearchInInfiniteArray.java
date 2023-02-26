public class BinarySearchInInfiniteArray {
    public static void main(String[] args) {
        int[] nums = {2, 3, 5, 6, 7, 8, 10, 11, 13, 15, 18, 21, 23, 24, 28, 30};
        int target = 10;
        int range = findRange(nums, target);
        System.out.println(range);
    }
    static int findRange(int[] nums, int target){
        int size = 2;
        int start = 0;
        int end = 1;
        while(target > nums[end]){
            size = 2*size;
            start = end + 1;
            end = end + size;
        }
        return binarySearch(nums, target, start, end);
    }
    static int binarySearch(int[] nums, int target, int start, int end){
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
