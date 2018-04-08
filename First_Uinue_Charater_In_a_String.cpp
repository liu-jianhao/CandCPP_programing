/* 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。 */

/* 案例: */

/* s = "leetcode" */
/* 返回 0. */

/* s = "loveleetcode", */
/* 返回 2. */


/* 注意事项：您可以假定该字符串只包含小写字母。 */


class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            auto it = mp.find(s[i]);
            if(it != mp.end())
            {
                //为什么不可以直接插入，不可以覆盖？？
                //mp.insert(pair<char, int>(s[i], 1));
                it->second = 1;
            }
            else
            {
                mp.insert(pair<char, int>(s[i], 0));
            }
        }


        for(int i = 0; i < s.size(); i++)
        {
            auto it = mp.find(s[i]);
            if(it->second == 0)
            {
                return i;
            }
        }

        return -1;
    }
};






class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};
        for(auto ch:s){
            count[ch-'a']+=1;
        }
        for(int i=0; i<s.length(); i++){
            if(count[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
