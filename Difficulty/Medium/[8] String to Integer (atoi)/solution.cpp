class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0 || str.find_first_not_of(' ') == string::npos)
            return 0;
        if (str.size() == 1 && !isdigit(str[0]))
            return 0;
        int i = 0;
        char flag = ' ';
        i = str.find_first_not_of(' ');
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
            return 0;
        else if (str[i] == '-'){
            flag = '-';
            i += 1;
        }
        else if (str[i] == '+'){
            flag = '+';
            i += 1;
        }
        long res = 0;
        for(; i < str.size(); ++i){
            if (isdigit(str[i])){
                res *= 10;
                res += int(str[i]) - 48;
            }
            else
                break;
            if (res > INT_MAX)
                if (flag == '-')
                    return INT_MIN;
                else
                    return INT_MAX;
        }
        if (res)
            if (flag == '-')
                return -int(res);
            else
                return int(res);
        else
            return 0;          
    }
    
};