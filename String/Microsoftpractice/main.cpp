#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    ifstream myfile("C:\\Sakshi\\EclipseWorkspace\\MicrosoftChallenge\\iamthebest.txt");
    string line;
    if(myfile.is_open())
    {

        while(getline(myfile, line))
        {
            string *n = strtok(line,"|");
            for(int i=0;i<n.length();i++)
            {
                cout<<n[i]<<"\n";
            }
        }
        myfile.close();
    }
    return 0;
}
