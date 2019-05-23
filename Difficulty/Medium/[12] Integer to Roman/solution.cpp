class Solution {
public:
    string intToRoman(int num) {
        string r;
        func1(r, num, 1000, 'M');
        func1(r, num, 100, 'C');
        func1(r, num, 10, 'X');
        func1(r, num, 1, 'I');
        return r;
    }
    void func1(string& r, int& num, int div, char c){
        if (num >= div){
            if (c == 'M'){
                int temp = int(num / div);
                string s(temp, c);
                r += s;
                num = num % div;
            }
            else if (c == 'C'){
                func2(r, num, div, c, 'D', 'M');
            }
            else if (c == 'X'){
                func2(r, num, div, c, 'L', 'C');
            }
            else if (c == 'I'){
                func2(r, num, div, c, 'V', 'X');
            }
        }
    }
    void func2(string& r, int& num, int div, char c, char top1, char top2){
        int temp = int(num / div);
        if (temp != 4 && temp != 9){
            if (temp < 4){
                string s(temp, c);
                r += s;
            }
            else{
                string s(temp - 5, c);
                r += top1;
                r += s;
            }
        }
        else if (temp == 4){
            r += c;
            r += top1;
        }
        else{
            r += c;
            r += top2;
        }
        num = num % div;
    }
};