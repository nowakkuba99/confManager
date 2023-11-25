#include "ConfHandle.h"
#include <string>

int main()
{
    confManager::ConfHandle confHandle("test.conf");

    std::string s;
    int i;
    float f;
    double d;

    confHandle.get("string",s);
    confHandle.get("int",i);
    confHandle.get("float",f);


    std::cout<<s<<"\n"<<i<<"\n"<<f<<"\n";

    return EXIT_SUCCESS;
}