/* 给定两个字符串 s 和 t，判断它们是否是同构的。 */

/* 如果 s 中的字符可以被替换最终变成 t ，则两个字符串是同构的。 */

/* 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。 */

/* 例如， */

/* 给定 "egg", "add", 返回 true. */

/* 给定 "foo", "bar", 返回 false. */

/* 给定 "paper", "title", 返回 true. */

/* 注意： */

/* 你可以假设 s 和 t 具有相同的长度。 */


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp1, mp2;
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            auto it1 = mp1.find(s[i]);
            if(it1 == mp1.end())
            {
                mp1.insert(pair<char, char>(s[i], t[i]));
            }
            else if(it1->second != t[i])
            {
                count++;
            }

            auto it2 = mp2.find(t[i]);
            if(it2 == mp2.end())
            {
                mp2.insert(pair<char, char>(t[i], s[i]));
            }
            else if(it2->second != s[i])
            {
                count++;
            }
        }


        if(count > 0)
        {
            return false;
        }

        return true;
    }
};




class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        if (n==0)
            return true;

        vector<int>  table1(128,0);
        vector<int>  table2(128,0);



        int index1 =1;
        int index2 =1;
        int tmp = 0;
        for(int i=0;i<n;i++){
            if(!table1[s[i]])
            {
                table1[s[i]] = index1;
                index1 ++;
            }
            if(!table2[t[i]])
            {
                table2[t[i]] = index2;
                index2 ++;
            }
        }

        for(int i=0;i<n;i++){
            if(table1[s[i]]!=table2[t[i]])
                return false;
        }




    return true;

    }
};
