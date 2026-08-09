class Solution {
public:
    int largestInteger(int n, int s) {
        // Only number with digit sum 0 is 0 itself
        if (s == 0) return 0;

        // Maximum achievable sum with n digits is 9 * n
        if (s > 9 * n) return -1;

        int result = 0;
        int remaining = s;

        for (int i = 0; i < n; i++) {
            int remaining_positions = n - i - 1;
            int max_possible_future = 9 * remaining_positions;

            // Try largest digit first, ensuring we can still reach sum s
            for (int d = 9; d >= 0; d--) {
                if (d <= remaining && remaining - d <= max_possible_future) {
                    result = result * 10 + d;
                    remaining -= d;
                    break;
                }
            }
        }

        return result;
    }
};
