#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        int j=n;
        for(int i=0; i<nums.size();i++){
            ans[i] = nums[i];
            ans[j++] = nums[i];
        }

        for(auto e : nums){
            cout<<e<<" ";
        }
        cout<<endl;

        return ans;
    }
};

int main() {

    vector<int> nums = {1,3,2,1};
    Solution Sol;

    Sol.getConcatenation(nums);

    return 0;
}
