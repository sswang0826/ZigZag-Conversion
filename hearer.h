class Solution {
public:
    string convert(string s, int numRows) {
        string output;
        
        bool finish = false;
        int row = 0;
        int last_insert = -1;
        int add_num = 2 * numRows - 2;
        if (add_num == 0)
            add_num = 1;
        while (!finish)
        {
            for (int i = 0; (i-row) < (int)s.size(); i += add_num)
            {
                if ((i - row) >= 0 && (i - row != last_insert))
                {
                    output.push_back(s[i - row]);
                    last_insert = i - row;
                }
                if ((i + row != last_insert) && ((i + row) < s.size()))
                {
                    output.push_back(s[i + row]);
                    last_insert = i + row;
                }
            }
            row++;
            if (row > numRows - 1)
                finish = true;
        }
        return output;
    }
};
