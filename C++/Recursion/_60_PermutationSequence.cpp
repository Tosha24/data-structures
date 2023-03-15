// Problem: Print the kth permutation sequence possible 
// For eg: Input: n = 4, k = 9    ==>   Output: "2314"

// Approach: Brute Force Approach
/* Solution:
 * Here we first construct an array of size n starting from 1 to n.
 * Along with it, we find the factorial of n-1, here the factorial and the value of k is used to find the permutation sequence.
 * As we consider the sequence from 0th index, for finding the value at kth position, we decrease k by 1.
 * k/fact gives the index at which the sequence can be present at.
 * number[k/fact] gives the next number that must be present in the sequence.
 * we add each number in the ans String and then remove that particular number, to not consider it further.
 * We continue this until the numbers array gets empty. 
 * Finally we return the ans
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class _60_PermutationSequence {
public:
    static string getPermutation(int n, int k){
        int fact = 1;
        vector<int> numbers;
        for(int i = 1; i < n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k - 1;
        string ans = "";
        while(true){
            ans = ans + to_string(numbers[k/fact]);
            int index = k/fact;
            numbers.erase(numbers.begin() + k / fact);
            if(numbers.size() == 0){
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};

int main() {
    int n = 4;
    int k = 9;
    cout << _60_PermutationSequence::getPermutation(n, k) << endl;
    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)