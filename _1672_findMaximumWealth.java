// Problem: You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has. A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
// For eg: Input: accounts = [[1,2,3],[3,2,1]]   ==>  Output: 6

public class _1672_findMaximumWealth {
    static int maximumWealth(int[][] accounts){
        int max = 0;
        for(int i = 0; i< accounts.length; i++){
            int rowSum = 0;
            for(int j = 0; j<accounts[i].length; j++){
                rowSum = rowSum + accounts[i][j];
            }
            if(rowSum > max){
                max = rowSum;
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int[][] accounts = {{1, 2, 3}, {3, 2, 3}};
        System.out.println(maximumWealth(accounts));
    }
}
