/* 给定一个整数数组，除了某个元素外其余元素均出现两次。请找出这个只出现一次的元素。 */

/* class Solution { */
/*     public: */
/*         int singleNumber(vector<int>& nums) { */
/*             sort(nums.begin(), nums.end()); */
/*             int i; */
/*             for(i = 0; i < nums.size(); i+=2){ */
/*                 if(nums[i] != nums[i+1]) */
/*                     break; */
/*             } */
/*             return nums[i]; */
/*         } */
/* }; */

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int x;

            x = 0;
            for(int i = 0;i<nums.size();i++)
                x ^= nums[i];

            return x;
        }
};
