#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minimumnumberofgates(vector<int>&arrival, vector<int>&departure)
{
    if(arrival.size()==0 && departure.size() == 0)
        return 0;
    if(arrival.size() != departure.size()) return 0;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int no_of_planes =1;
    int finalresult = 1;
    int i=1; int j =0;
    while(i<arrival.size()&& j<departure.size())
    {
        if(arrival[i]<departure[j])
        {
            no_of_planes++;
            i++;
            if(no_of_planes > finalresult)
                finalresult = no_of_planes;
        }
        else
        {
            no_of_planes --;
            j++;
        }
    }
    return finalresult;


}
int main()
{
    vector<int>arrival;
    arrival.push_back(900);
    arrival.push_back(940);
    arrival.push_back(950);
    arrival.push_back(1100);
    arrival.push_back(1500);
    arrival.push_back(1800);

    vector<int>departure;
    departure.push_back(910);
    departure.push_back(1120);
    departure.push_back(1130);
    departure.push_back(1200);
    departure.push_back(1900);
    departure.push_back(2000);

    int gatesreqd = minimumnumberofgates(arrival, departure);
    cout<<gatesreqd;
    return 0;
}
