//vec1.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> tokens;
    string token;
    while(cin>>token)
        tokens.push_back(token);
    int ntok=tokens.size();
    cout<<"There are "<<ntok<<" tokens:"<<endl;
    for (int i = 0; i<ntok; ++i)
    {
        cout<<i<<": "<<tokens[i]<<endl;
    }
    return 0;
}
