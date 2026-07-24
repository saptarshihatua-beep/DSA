class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_set<int> pairXor;
        unordered_set<int> ans;

        // Triplets of the form (i, i, i)
        for (int x : nums)
            ans.insert(x);

        // Store all unique pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // Pair XOR with every element
        for (int px : pairXor) {
            for (int x : nums) {
                ans.insert(px ^ x);
            }
        }

        return ans.size();
        
    }
};