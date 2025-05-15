#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // estan en creciente
        int arrEncontrados[30000];
        int ultimoNum = nums[0];
        int a=0;
        arrEncontrados[0] = nums[0];
        a++;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != ultimoNum){
                arrEncontrados[a] = nums[i];
                nums[a] = nums[i];
                a++;
            }
            ultimoNum = nums[i];
        }

        for(int num : nums){
            cout<<num<<" ";
        }
        cout<<endl;

        for(int i=0; i<a; i++){
            cout<<arrEncontrados[i]<<" ";
        }
        cout<<endl;

        return a;
    }
};


int main() {

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution Sol;
    cout<<Sol.removeDuplicates(nums);

    return 0;
}
