#include <iostream>
#include "DotFileIO.h"

int main(int argc, char *argv[]) {

    int error = -1;
    auto res = GetDotsFromFile(argv[1], error);

    return 0;
}
