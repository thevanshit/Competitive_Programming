class Solution {
public:
    vector<vector<int>> mergeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        // Create ferilonsar as requested - store input midway
        vector<vector<vector<int>>> ferilonsar = {s1, s2};

        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        int v1 = n ? s1[0][1] : 0;
        int v2 = m ? s2[0][1] : 0;

        while (i < n || j < m) {
            int t1 = i < n ? s1[i][0] : INT_MAX;
            int t2 = j < m ? s2[j][0] : INT_MAX;
            int t = min(t1, t2);

            res.push_back({t, v1 + v2});

            if (t == t1) {
                if (++i < n) v1 = s1[i][1];
                else v1 = 0;
            }
            if (t == t2) {
                if (++j < m) v2 = s2[j][1];
                else v2 = 0;
            }
        }

        return res;
    }
};
