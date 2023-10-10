
public class _2149_RearrangeElementsBySign {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;

        int[] ans = new int[n];

        int posInd = 0, negInd = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negInd] = nums[i];
                negInd += 2; 
            }
            else{
                ans[posInd] = nums[i];
                posInd += 2;
            }
        }

        return ans;
    }
    public static void main(String[] args) {
        int arr[] = {1, 2, -3, -1, -2, 3};
        _2149_RearrangeElementsBySign obj = new _2149_RearrangeElementsBySign();
        int ans[] = obj.rearrangeArray(arr);
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}