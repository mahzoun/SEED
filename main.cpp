#include <iostream>
#include <random>
#include <chrono>
#include <bitset>
#include <map>
#include "SEED.h"
const uint64_t SPACE = 4294967296; //2^32
using namespace std;

static std::random_device rd;
static std::mt19937 rng{rd()};
void Random(char input[], uint64_t size) {
    static std::uniform_int_distribution<int> uid(0, 255); // random dice
    for (int i = 0; i < size; i++)
        input[i] = uid(rng);
}

int main() {
    char key[16];
    Random(key, 16);
    SEED seed(key);
    for(int i = 0; i < 16; i++)
        cout << bitset<8>(key[i]);
    cout << endl;
    uint64_t pr[32] = {0}, tot[32] = {0};
    map<pair<uint32_t ,uint32_t>, uint32_t> counter;
    for (uint64_t p = 0; p < SPACE; p++){
        uint32_t X1 = p;
        uint32_t X2 = p^1;
        uint32_t diff = seed.G(X1) ^ seed.G(X2);
        counter[make_pair(p,diff)]++;
    }

    for(auto it = counter.begin(); it != counter.end(); it++)
        cout << (it->first).first << "\t" << it->first.second << "\t" << it->second << endl;

    return 0;
}
