//use auto_ptr to deal with the memory leak
#include <cstdio>
#include <memory> //auto_ptr
//using namespace std;

class File
{
    FILE* f;
public:
    File(const char* fname,const char* mode)
    {
        f=fopen(fname,mode);
        if(!f)
            throw 1;
    }
    ~File()
    {
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
    } catch (int k) {
        printf("caught exception: %d\n",k);
    }

    return 0;
}

void f(const char* fname)
{
    //File* xp=new File(fname,"r");
    std::auto_ptr<File> xp=new File(fname,"r");
    puts("processing file .... ");
    throw 2;
    //delete xp; // won't happen
}
