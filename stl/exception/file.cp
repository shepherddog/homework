#include <cstdio>
using namespace std;

class File
{
    FILE* f;
public:
    File(const char* fname,const char* mode){
        f=fopen(fname,mode);
        if(!f)
            throw 1;
    }
    ~File(){
        if(f)
        {
            fclose(f);
            puts("File closed");
        }
    }
};

int main(int argc, char *argv[])
{
    void f(const char*);
    try {
        f("file1.dat");
    } catch (int x) {
        printf("Caught exception : %d\n",x);
    }

    return 0;
}

void f(const char* fname)
{
    File x(fname,"r");
    puts("processing file...");
    throw 2;
}
