#include <iostream>
#include <vector>

using namespace std;
class int_map{

    vector<int>nums;
    int initial_val;
public:
    int_map(int num_values, int initial_value){
        nums.resize(num_values, initial_value);
        initial_val = initial_value;
    }
    int get(int index) const
    {
        if(index >= nums.size()) return -1;
        return nums[index];
    }
    void set(int index, int value){
        if(index >= nums.size()){
            nums.resize(index+1, initial_val);
        }
        nums[index] = value;
    }
    void print(){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<endl;
        }
    }
};

int main()
{
    int_map imap(5,0);
    imap.get(3);
    imap.set(3,7);
    imap.set(7,8);
    imap.print();
    return 0;
}
