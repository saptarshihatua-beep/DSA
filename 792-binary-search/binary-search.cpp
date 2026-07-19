class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,heigh=n-1;
        while (low<=heigh){
            int mid= low+(heigh-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(target>nums[mid]){
                low= mid +1;

            }else{
            heigh= mid-1;
            }
        }
        return -1;
    


    }
};