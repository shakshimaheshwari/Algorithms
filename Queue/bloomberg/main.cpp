#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include<vector>
#include <map>

using namespace std;

int groupAnagrams(vector<string>input)
{
    int count =0;
    map<string,vector<string> >myMap;
    for(int i=0;i<input.size();i++)
        {
           string s = input[i];
           std::transform(s.begin(), s.end(), s.begin(), ::tolower);
           sort(s.begin(), s.end());
           myMap[s].push_back(input[i]);
        }

        for(map<string, vector<string> >::iterator iter = myMap.begin(); iter!= myMap.end(); iter++)
        {
            if(iter->second.size() > 1)
            {
                count+=iter->second.size();
            }
        }
        return count;

}

int main() {

        int n;
        cin>>n;
        vector<string>input;
        string *s = new string[n];
        for(int i=0;i<n;i++)
        cin>>s[i];
        for(int i=0;i<n;i++)
        input.push_back(s[i]);
        int count = groupAnagrams(input);
        cout<<count;
        return 0;
}
