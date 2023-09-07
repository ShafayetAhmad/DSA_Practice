class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int ,int> frq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) frq[nums[i]]++;
            else if(nums[i]==1) frq[nums[i]]++;
            else frq[nums[i]]++;
            
        }
        nums.clear();
        for(int i=0;i<frq[0];i++){
            nums.push_back(0);
            
        }
        for(int i=0;i<frq[1];i++){
            nums.push_back(1);
            
        }
        for(int i=0;i<frq[2];i++){
            nums.push_back(2);
            
        }
        
    }
};