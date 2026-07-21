class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
          string t = "1" + s + "1";
        int n = t.size();

        vector<char> type;
        vector<int> len;

        // Create groups
        for (int i = 0; i < n; ) {
            char c = t[i];
            int j = i;
            while (j < n && t[j] == c)
                j++;

            type.push_back(c);
            len.push_back(j - i);

            i = j;
        }

        // Count original 1s (excluding the added boundary 1s)
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        int ans = ones;

        // Check every 1-group that has 0-groups on both sides
        for (int i = 1; i + 1 < type.size(); i++) {
            if (type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0') {

                ans = max(ans, ones + len[i - 1] + len[i + 1]);
            }
        }

        // Cannot exceed original string length
        return min(ans, (int)s.size());
    }
};