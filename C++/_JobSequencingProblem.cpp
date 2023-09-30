// Problem: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

/* Intuition: 
* 1. Sort the array of structures according to the profit of the jobs
* 2. Find the max deadline of the jobs
* 3. Create a job_slot array of size max_deadline + 1 and initialize all the values to -1
* 4. Traverse through the array and check if the job_slot[j] is empty or not
* 5. If empty, then insert the job id in the job_slot[j] and increment the total_profit and job_count
* 6. Return the job_count and total_profit
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

class _JobSequencingProblem {
public:
    bool static comparison(Job a, Job b){
        return (a.profit > b.profit);   
    }
    static vector<int> JobScheduling(Job arr[], int n){
        vector<int> result;
        sort(arr, arr + n, comparison);
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }

        int job_slot[maxDeadline + 1];
        for(int i = 1; i < maxDeadline + 1; i++){
            job_slot[i] = -1;
        }

        int total_profit = 0, job_count = 0;
        for(int i = 0; i < n; i++){
            for(int j = arr[i].deadline; j > 0; j--){
                if(job_slot[j] == -1){
                    job_slot[j] = arr[i].id;
                    total_profit += arr[i].profit;
                    job_count += 1;
                    break;
                }
            }
        }
        result.push_back(job_count);
        result.push_back(total_profit);
        return result;
    }
};

int main(){
    int N = 4;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> result = _JobSequencingProblem::JobScheduling(arr, N);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ", ";
    }
    return 0;
}

// Time Complexity: O(NlogN) + O(N*M)  --> O(NlogN) for sorting the array, O(N*M) for traversing through the array and also checking for the deadlines
// Space Complexity: O(M)  --> O(M) for creating the job_slot array maximum deadline array 