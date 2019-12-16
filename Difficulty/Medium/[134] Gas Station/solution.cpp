class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        for (int id = 0; id < size; id++) {
            int gas_num = 0;
            for (int i = id; i < size; i++) {
                gas_num += gas[i];
                gas_num -= cost[i];
                if (gas_num < 0) break;
            }
            if (gas_num >= 0) {
                for (int j = 0; j < id; j++) {
                    gas_num += gas[j];
                    gas_num -= cost[j];
                    if (gas_num < 0) break;
                }
                if (gas_num >= 0) return id;
            }
        }
        return -1;
    }
};


// O(n) solution
class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size=gas.size();
    int sum=0;
    int res=0;
    int total=0;
    for(int i=0; i<size; ++i){
        sum+=gas[i]-cost[i];
        if(sum<0){
            total+=sum;
            sum=0;
            res=i+1;
        }
    }
    total+=sum;
    return total<0?-1:res;
}
};