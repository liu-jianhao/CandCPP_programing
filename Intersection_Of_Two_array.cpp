/* 给定两个数组，写一个函数来计算它们的交集。 */

/* 例子: */

/*  给定 num1= [1, 2, 2, 1], nums2 = [2, 2], 返回 [2]. */

/* 提示: */

/* 每个在结果中的元素必定是唯一的。 */
/* 我们可以不考虑输出结果的顺序。 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record(nums1.begin(),nums1.end());
        set<int> resultSet;
        for(int i = 0; i < nums2.size(); i++){
            if(record.find(nums2[i]) != record.end()){
                resultSet.insert(nums2[i]);
            }
        }
        return vector<int>(resultSet.begin(),resultSet.end());
    }
};
