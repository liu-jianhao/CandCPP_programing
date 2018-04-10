/* 集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。 */

/* 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。 */

/* 示例 1: */

/* 输入: nums = [1,2,2,4] */
/* 输出: [2,3] */
/* 注意: */

/* 给定数组的长度范围是 [2, 10000]。 */
/* 给定的数组是无序的。 */



class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        auto n = nums.size();
        sort(nums.begin(), nums.end());
        int sum1 = 0, sum2 = 0, sub;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == nums[i+1])
                ret.push_back(nums[i]);
            sum1 += nums[i];
        }

        sum2 = (1 + n) * n / 2;
        if(sum2 > sum1)
        {
            sub = sum2 - sum1;
            ret.push_back(ret[0] + sub);
        }
        else
        {
            sub = sum1 - sum2;
            ret.push_back(ret[0] - sub);
        }

        return ret;
    }
};







class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            int c= abs(nums[i]);
            tot += c;
            if (nums[c - 1] > 0)
                nums[c - 1] = -nums[c - 1];
        }

        int pt = (1+n)*n/2;
        int lost,dp;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
            {
                lost = i+1;
                break;
            }

        dp = lost - pt + tot;
        ret.push_back(dp);
        ret.push_back(lost);
        return ret;
    }
};
