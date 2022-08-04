#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <bitset>
#include <algorithm>
#include <map>
#include "SEED.h"
const uint64_t SPACE = 4294967296; //2^32
using namespace std;

static std::random_device rd;
static std::mt19937 rng{rd()};
void Random(char input[], uint64_t size) {
    static std::uniform_int_distribution<> distrib(0, 255); // random dice
    for (int i = 0; i < size; i++){
        input[i] = distrib(rng);
        input[i] = (unsigned int)(input[i] % 256);
        cout << input[i] << endl;
    }
}
uint64_t cnt[256][256];
int main() {
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(str.begin(), str.end(), generator);
    string key = str.substr(0,16);
    SEED seed(key);
    ofstream fout;
    vector<pair<uint32_t, uint32_t>> V;
    for(uint64_t i = 0; i < SPACE; i++){
        if(i % 16777216 == 0)
            cout << i << endl;
        V.push_back(make_pair(i, seed.G(i)));
    }
  // for(pair<uint64_t, uint64_t> i: V){
   //     cout << i.first << " " << i.second << endl;
//    }
    fout.close();
    return 0;
}
