import java.util.ArrayList;
// Recursion: this will print the subsequence that occurs in an array. Subsequence is a contiguous/non-contiguous sequences, which follows the order.
public class PrintSubsequence{
    public static void main(String[] args){
        int[] arr = {8, 3, 6};
        printSequence(0, arr, new ArrayList<Integer>());
    }
    static void printSequence(int index, int[] arr, ArrayList<Integer> seq){
        if(index >= arr.length){
            System.out.println(seq);
            return;
        }
        seq.add(arr[index]);
        printSequence(index + 1, arr, seq);
        seq.remove(seq.size() - 1);
        printSequence(index + 1, arr, seq);
        return;
    }
}