//joseph ring
//Suppose that there are k good guys and k bad guys. In the circle the first k are good guys and the last k bad guys. You have to determine such minimal m that all the bad guys will be executed before the first good guy.
//Input:
//The input file consists of separate lines containing k. The last line in the input file contains 0. You can suppose that 0 < k < 14.
//Output:
//The output file will consist of separate lines containing m corresponding to k in the input file.

#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool check(int k, int m){
    int n=k*2, p=0;
    for (int i=0; i<k; i++){
        p = (p+m)%n;
        if (p < k) return false;
        n--;
    }
    return true;
}

int solve(int k)
{
    int ret = k+1;
    while (!check(k, ret-1)) ret++;
    return ret;
}

int table[14];

int main()
{
    for (int i=0; i<14; i++)
        table[i] = solve(i);
    int k;
    while (cin>>k){
        assert(0<k&&k<14);
        cout<<table[k]<<endl;
    }
    return 0;
}

