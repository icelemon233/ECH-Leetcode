class Solution
{
public:
    string replaceSpace(string s)
    {
        int blank_count = 0;
        for (char &ch : s)
        {
            if (ch == ' ')
            {
                blank_count++;
            }
        }

        // 扩充数组
        int old_size = s.size();
        s.resize(s.size() + blank_count * 2);
        int new_size = s.size();
        int i = old_size - 1, j = new_size - 1;
        while (i < j)
        {
            while (s[i] != ' ')
            {
                s[j] = s[i];
                i--;
                j--;
            }
            s[j] == '0';
            s[j - 1] == '2';
            s[j - 2] == '%';
            j -= 3;
            i--;
        }
        return s;
    }

    // c++11方法
    // string replaceSpace(string s)
    // {
    //     string array;
    //     for (auto &c : s)
    //     {
    //         if (c == ' ')
    //         {
    //             array += "%20";
    //         }
    //         else
    //         {
    //             array += c;
    //         }
    //     }
    //     return array;
    // }
};
