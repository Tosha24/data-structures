public class TwoSum_1 {
    static int[] twoSum(int[] nums, int target){
        for(int i=0; i<nums.length; i++){
            for(int j=i+1; j<nums.length; j++){
                if(nums[i] + nums[j] == target){
                    return new int[]{i, j};
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        int[] array = {2,7,11,15};
        int target = 9;
        int[] result = twoSum(array, target);
        System.out.print("[");
        for(int i : result){
            System.out.print(i + ",");
        }
        System.out.print("]");
    }
}
