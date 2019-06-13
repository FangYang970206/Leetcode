class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";
        string s = "11";
        for (int i {}; i < n - 2; i++){
            string temp = "";
            char c = 0;
            int num = 0;
            for (auto it = s.begin(); it != s.end(); it++){
                if (c && *it == c)
                    num += 1;
                else if (c && *it != c){
                    temp += to_string(num) + c;
                    num = 1;
                    c = *it;
                }
                else{
                    num = 1;
                    c = *it;
                }
            }
            temp += to_string(num) + c;
            s = temp;
        }
        return s;
    }
};