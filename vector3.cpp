#include <iostream>
#include <vector>

using namespace std;

// Function to generate combinations recursively
void generateCombinations(vector<int>& nums, vector<int>& combination, int start, int k, vector<vector<int>>& result) {
    if (k == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i <= nums.size() - k; ++i) {
        combination.push_back(nums[i]);
        generateCombinations(nums, combination, i + 1, k - 1, result);
        combination.pop_back();
    }
}

// Function to generate all combinations of given size from the input vector
vector<vector<int>> combine(vector<int>& nums, int k) {
    vector<vector<int>> result;
    vector<int> combination;
    generateCombinations(nums, combination, 0, k, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4,5};
    int k = 2;
    int count=0;
    
    vector<vector<int>> result = combine(nums, k);
    
    cout << "Combinations of size " << k << " are:\n";
for (int i = 0; i < result.size(); ++i) {
    cout << "[";
    for (int j = 0; j < result[i].size(); ++j) {
        if(result[i][0]==1){
            count++;
        }
    }
   if(count)
}


    return 0;
}
