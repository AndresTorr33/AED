#include <iostream>
#include <vector>

using namespace std;

// La wea en leetcode no analiza bien el output. Está bien pero marca mal

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size(), L = 0, R = 0;
        vector<int> elems={};
        int cantEliminados=0;
        while(R < N){
            if(nums[R]==val){
                R++;
            }
            else{
                nums[L] = nums[R];
                elems.emplace_back(nums[L]);
                L++;
                R++;

            }
        }
        nums = elems;
        for(auto n : nums){
            cout<<n<<" ";
        }

        return N - cantEliminados;
    }
};

int main() {

    vector<int> nums = {0,1,2,2,3,0,4,2};

    Solution Sol;
    cout<<Sol.removeElement(nums, 2);

    return 0;
}