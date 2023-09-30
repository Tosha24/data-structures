#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Item {
    int value;
    int weight;
};

class _FractionalKnapsack {
public:
    static bool comparison(Item a, Item b){
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    static double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr + n, comparison); 

        double profit = 0.0;
        int curWeight = 0;
        for(int i = 0; i < n; i++){
            if(curWeight + arr[i].weight <= W){
                profit += arr[i].value;
                curWeight += arr[i].weight;
            }
            else{
                int remain = W - curWeight;
                profit += (arr[i].value / arr[i].weight) * remain;
                break;
            }
        }
        return profit;
    }
};

int main(){
    int N = 3, W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    cout << _FractionalKnapsack::fractionalKnapsack(W, arr, N) << endl;
    return 0;
}

// Time Complexity: O(nlogn) + O(n)
// Space Complexity: O(1)