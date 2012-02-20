#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;
void handler()
{
    cout<<"Regegrade exception!\n";
    exit(EXIT_FAILURE);
}

void f();

int main(int argc, char *argv[])
{
    set_terminate(handler);
    try {
        f();
    } catch (long) {
        cerr<<"caught a long"<<endl;
    }

    return 0;
}

void f(){
    throw 1;
}
