leetcode31.cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) k -- ;
        // k == 0 说明数组是降序的，下一个排列就是翻转过来
        if (k == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            //k是满足这个条件的最靠后的: nums[k - 1] < nums[k]
            int t;
            // 从后向前找到第一个索引t满足nums[t] > nums[k-1]
            for (int i = nums.size() - 1; i > k - 1; i--) {
                if (nums[i] > nums[k - 1]) {
                    t = i;
                    break;
                }
            }
            //t和k-1处的交换，然后后半部分翻转
            swap(nums[t], nums[k - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
