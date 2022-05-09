#include <iostream>
#include <string>
#include "SEED.h"
using namespace std;
int main() {
    SEED seed("0000000000000000");
    string s = "0000000000000000";
    seed.encrypt(s);
    std::cout << seed.encrypt(s) << std::endl;
    return 0;
}
