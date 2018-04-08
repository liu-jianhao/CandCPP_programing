/* 假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表， */
/* 每个餐厅的名字用字符串表示。 */

/* 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个， */
/* 则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。 */

/* 示例 1: */

/* 输入: */
/* ["Shogun", "Tapioca Express", "Burger King", "KFC"] */
/* ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"] */
/* 输出: ["Shogun"] */
/* 解释: 他们唯一共同喜爱的餐厅是“Shogun”。 */
/* 示例 2: */

/* 输入: */
/* ["Shogun", "Tapioca Express", "Burger King", "KFC"] */
/* ["KFC", "Shogun", "Burger King"] */
/* 输出: ["Shogun"] */
/* 解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。 */
/* 提示: */

/* 两个列表的长度范围都在 [1, 1000]内。 */
/* 两个列表中的字符串的长度将在[1，30]的范围内。 */
/* 下标从0开始，到列表的长度减1。 */
/* 两个列表都没有重复的元素。 */



class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> tmp;
        vector<string> ret;
        vector<int> com;
        map<string, int> mp;
        int i, j;
        for(i = 0; i < list1.size(); i++)
        {
            for(j = 0; j < list2.size(); j++)
            {
                if(list1[i] == list2[j])
                {
                    tmp.push_back(list1[i]);
                    com.push_back(i + j);cd
                }
            }
        }

        for(i = 0; i < com.size(); i++)
            mp.insert(pair<string, int>(tmp[i], com[i]));


        sort(com.begin(), com.end());
        int temp = com[0];

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == temp)
            {
                ret.push_back(it->first);
            }
        }

        return ret;
    }
};


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> map1;
        for(int i = 0; i < list1.size(); ++i)
        {
            map1.insert(pair<string, int>(list1[i], i));
        }
        int sum = 9999;
        vector<string> output;
        for(int i = 0; i < list2.size(); ++i)
        {
            if(i > sum) break;
            auto iter = map1.find(list2[i]);
            if(iter == map1.end()) continue;
            int cur = i + iter->second;
            if(cur < sum)
            {
                sum = cur;
                output.clear();
                output.push_back(list2[i]);
            }
            else if(cur == sum)
            {
                output.push_back(list2[i]);
            }
        }
        return output;
    }
};

/* 144 ms */



