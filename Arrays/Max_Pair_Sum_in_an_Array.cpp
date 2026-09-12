class Solution {
public:
    int findMaxDigit(int num) {
        int maxi = 0;

        while (num > 0) {
            maxi = max(maxi, num % 10);
            num /= 10;
        }

        return maxi;
    }

    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int digit1 = findMaxDigit(nums[i]);
                int digit2 = findMaxDigit(nums[j]);

                if (digit1 == digit2) {
                    ans = max(ans, nums[i] + nums[j]);
                }
            }
        }

        return ans;
    }
};
