#include <iostream>
#include <vector>

class Solution {
public:
    int n;
    bool numsPairs(std::vector<int>& nums, int diff, int p){
        int c=0;
        for(int i=0; i<n-1; i++)
            if (nums[i+1]-nums[i]<=diff) {
                c++;
                if (c>=p) return 1;
                i++;//can not be adjacent  
            }
        return 0;
    }
    int minimizeMax(std::vector<int>& nums, int p) {
        if (p==0) return 0; // edge case
        n=nums.size();
        std::sort(nums.begin(), nums.end());

        int l=0, r=nums[n-1]-nums[0], m, ans;
        while(l<=r){
            m=l+(r-l)/2;
            if (numsPairs(nums, m, p)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        
        return ans;   
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 9, 7, 1};
    int p = 2;
    
    int result = solution.minimizeMax(nums, p);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
