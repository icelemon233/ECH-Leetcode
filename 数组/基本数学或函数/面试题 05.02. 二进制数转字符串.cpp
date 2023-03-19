class Solution
{
public:
    string printBin(double num)
    {
        string bin = "0.";
        for (int i = 0; i < 6; ++i)
        {
            num *= 2;
            if (num < 1)
                bin += '0';
            else
            {
                bin += '1';
                if (--num == 0)
                    return bin;
            }
        }
        return "ERROR";
    }
};