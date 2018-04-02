/* 给定一个整数数列，找出其中和为特定值的那两个数。 */

/* 你可以假设每个输入都只会有一种答案，同样的元素不能被重用。 */

/* 示例: */

/* 给定 nums = [2, 7, 11, 15], target = 9 */

/* 因为 nums[0] + nums[1] = 2 + 7 = 9 */
/* 所以返回 [0, 1] */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for(i = 0; i < nums.size() - 1; i++){
            int temp = target - nums[i];
            for(j = i+1; j < nums.size(); j++){
                if(nums[j] == temp){
                    vector<int> ret = {i, j};
                    return ret;
                }
            }
        }
    }
};
