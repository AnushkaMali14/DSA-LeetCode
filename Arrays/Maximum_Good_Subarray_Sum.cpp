class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         unordered_map<long long, long long> mp;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for (int num : nums) {

            long long currPrefix = prefix + num;

            if (mp.count((long long)num + k))
                ans = max(ans, currPrefix - mp[(long long)num + k]);

            if (mp.count((long long)num - k))
                ans = max(ans, currPrefix - mp[(long long)num - k]);

            if (!mp.count(num))
                mp[num] = prefix;
            else
                mp[num] = min(mp[num], prefix);

            prefix = currPrefix;
        }

        return (ans == LLONG_MIN) ? 0 : ans;
        
    }
};
