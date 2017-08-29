#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MaxSubSum(vector<int>& vec){
    if (vec.size() < 1) return 0;
    int maxSum = vec[0];
    int currSum = 0;
    for (int i = 0; i < vec.size(); ++i){
        currSum = (currSum + vec[i] > vec[i]) ? (currSum + vec[i]) : vec[i];
        maxSum = (currSum > maxSum) ? currSum : maxSum;
    }
    return maxSum;
}

int main(int argc, char** argv){
    int arr[] = {9, 1, 4, -1, -10, 8};
    int n = sizeof(arr)/sizeof(int);
    vector<int> vec(arr, arr+n);
    cout << MaxSubSum(vec) << endl;
    return 1;
}