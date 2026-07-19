class Solution {
public:
    string smallestSubsequence(string s) {
           vector<int> lastIndex(26);
        vector<bool> visited(26, false);

        // Store last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Already present
            if (visited[ch - 'a'])
                continue;

            // Remove bigger characters if they appear later
            while (!ans.empty() &&
                   ans.back() > ch &&
                   lastIndex[ans.back() - 'a'] > i) {

                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;  
        
    }
};