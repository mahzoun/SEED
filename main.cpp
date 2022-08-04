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
    for (int i = 0; i < size; i++) {
        input[i] = distrib(rng);
        input[i] = (unsigned int) (input[i] % 256);
        cout << input[i] << endl;
    }
}

bool sortbysecond(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

uint64_t cnt[256][256];

int main() {
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(str.begin(), str.end(), generator);
    string key = str.substr(0, 16);
    SEED seed(key);
    ofstream fout("GFunction.txt");
    vector<pair<uint32_t, uint32_t>> V;
    for (uint64_t i = 0; i < 1024; i++) {
        if (i % 16777216 == 0)
            cout << i << endl;
        V.push_back(make_pair(i, seed.G(i)));
    }
    sort(V.begin(), V.end(), sortbysecond);
    uint64_t i = 0;
    while(i < V.size()) {

        uint64_t j = i;
        uint32_t cur = V[i].second;
        while (V[j].second == V[i].second) {
            j++;
        }
        if (j > i + 1) {
            for (uint64_t k = i; k < j; k++) {
                fout << V[k].first << " " << V[k].second << " " << j - i << endl;
            }
            fout << endl << endl;
        }
        i = j;
    }
    fout.close();
    return 0;
}
