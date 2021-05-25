#include "file.h"

#include<iostream>
#include<string>

int main()
{
    //todo
    std::string path = "../data/helix";

    File::rm_dir(path);

    return 0;
   
}