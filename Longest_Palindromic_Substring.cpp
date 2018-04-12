/* 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。 */

/* 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。 */

/* 注意: */
/* 假设字符串的长度不会超过 1010。 */

/* 示例 1: */

/* 输入: */
/* "abccccdd" */

/* 输出: */
/* 7 */

/* 解释: */
/* 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。 */




class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int ou = 0, ji = 0, ge = 0;
        int sum = 0;
        for(char c : s)
        {
            mp[c]++;
        }

        for(auto s : mp)
        {
            if(s.second % 2 == 0)
            {
                ou += s.second;
            }
            else
            {
                ji += s.second;
                ge++;
            }
        }
        //统计所有的字母，最终等于所有的出现为偶数的次数+所有奇数的次数-（奇数的个数 - 1）,如果没有奇数则不减
        if(ji == 0)
        {
            sum = ou;
        }
        else
        {
            sum = ou + ji - (ge - 1);
        }
        return sum;
    }
};
