#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;


class rle_int_map{
    struct run{
        int m_stop;
        int m_value;
    };
    int number_values;
    vector<run>m_runs;

public:
    rle_int_map(int num_values, int initial_val){
        m_runs.push_back({num_values, initial_val});
        number_values = num_values;
    }

    int get(int index) const
    {
        assert(0<=index && index<=number_values);
        int start = 0;
        int end = m_runs.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(m_runs[mid].m_stop>=index){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return m_runs[start].m_value;
    }
    int getIndex(int index) const
    {
        assert(0<=index && index<=number_values);
        int start = 0;
        int end = m_runs.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(m_runs[mid].m_stop>=index){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
    void set(int index, int value){
            int prev = index-1;
            int next = index+1;

            if(index == 1){
                if(value == get(next)){
                    m_runs.erase(m_runs.begin());
                }else{
                    m_runs.insert(m_runs.begin(),{index, value});
                }
            }
            else if(index == number_values){
                if(value == get(prev)){
                    m_runs.pop_back();
                    m_runs.pop_back();
                    m_runs.push_back({index, value});
                }else{
                    m_runs.back().m_stop = m_runs.back().m_stop-1;
                    m_runs.push_back({index, value});
                }
            }else{
                int arrIndex = getIndex(index);
                int prevIndex = arrIndex-1;
                int nextIndex = arrIndex+1;
                int prevvalue = get(prev);
                int nextvalue = get(next);
                if(prevvalue == value && nextvalue == value){
                    m_runs.erase(m_runs.begin() + prevIndex);
                    m_runs.erase(m_runs.begin()+ prevIndex);
                }else if(prevvalue == value && nextvalue!=value){
                    int size = m_runs.size();
                    m_runs.erase(remove_if(m_runs.begin(), m_runs.end(), [&index, &prev](const run &r){return (r.m_stop == index || r.m_stop == prev);}), m_runs.end());
                    if( m_runs.size() < size){
                        arrIndex = getIndex(index);
                    }
                    m_runs.insert(m_runs.begin()+prevIndex, {index, value});
                }else if(prevvalue != value && nextvalue == value){
                    m_runs.erase(m_runs.begin()+arrIndex);
                }else{
                    int size = m_runs.size();
                    m_runs.erase(remove_if(m_runs.begin(), m_runs.end(), [&index, &prev](const run &r){return (r.m_stop == index || r.m_stop == prev);}), m_runs.end());
                    if( m_runs.size() < size){
                        arrIndex = getIndex(index);
                    }
                    m_runs.insert(m_runs.begin()+arrIndex, {prev,prevvalue});
                    m_runs.insert(m_runs.begin() + arrIndex+1, {index,value});
                }
            }
    }
    void print(){
        for(int i=0;i<m_runs.size();i++){
            cout<<m_runs[i].m_stop<<"   "<<m_runs[i].m_value<<endl;
        }
    }
};
int main()
{
    rle_int_map rl(6,0);
    //rl.get(0);
    rl.set(4,1);
    rl.set(1,2);
    rl.set(2,3);
    rl.set(3,3);
    rl.set(5,1);
    rl.set(3,4);

    rl.print();
    return 0;
}
