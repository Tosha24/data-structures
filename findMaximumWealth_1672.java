public class findMaximumWealth_1672 {
    public static void main(String[] args) {
        int[][] accounts = {{1, 2, 3}, {3, 2, 3}};
        System.out.println(maximumWealth(accounts));
    }
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
}
