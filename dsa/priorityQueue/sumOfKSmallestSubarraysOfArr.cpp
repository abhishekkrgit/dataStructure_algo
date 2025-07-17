class Solution {
    int MOD = 1e9 + 7;
    pair<int,long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long totalSum = 0;
        long long windowSubArraysSum = 0;
        long long windowSum = 0;
        int i = 0, j = 0;
        while (j < n) {
            windowSum += nums[j];
            long long windowLen = j - i + 1;
            windowSubArraysSum += 1LL * nums[j] * windowLen;

            while (i <= j && windowSum > target) { // windowSum should not cross the target
                windowSubArraysSum -= windowSum;
                windowSum -= nums[i++];
            }

            long long subArrayCntEndingAtJ = j - i + 1;
            count += subArrayCntEndingAtJ;
            totalSum += windowSubArraysSum;
            j++;
        }

        return {count, totalSum};
    }

    long long sumOfKSmallestSubarraysSum(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        while (low < high) {
            int midSum = low + (high - low) / 2;
            auto [count, _] = countAndSum(nums, n, midSum);
            if (count >= k)
                high = midSum;
            else
                low = midSum + 1;
        }

        auto [count, totalSum] = countAndSum(nums, n, high);
        if(count > k){
            long long extraSum = 1LL * (count-k)*high;
            return totalSum -  extraSum;
        }

        return totalSum;
    }

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long rightSum = sumOfKSmallestSubarraysSum(nums, right);
        long long leftSum = sumOfKSmallestSubarraysSum(nums, left - 1);
        long long ans = (rightSum % MOD - leftSum % MOD + MOD) % MOD;
        return (int)ans;
    }
};
