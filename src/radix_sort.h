#pragma once

#include "bucket_sort.h"

#include <utility>
#include <vector>

template <typename T>
void radixSort(std::vector<std::pair<int,T>>& v, int bits)
{
    std::vector<std::pair<int,std::pair<int,T>>> vPrime;
    vPrime.reserve(v.size());

    for (const auto& pair : v) {
        vPrime.emplace_back(0, pair);
    }

    v.clear();

    for (int bit = 0; bit < bits; bit++) {
        for (auto& pair : vPrime) {
            int realKey = pair.second.first;
            int bitKey = (realKey >> bit) & 1;
            pair.first = bitKey;
        }
        bucketSort(vPrime, 2);
    }

    for (const auto& pair : vPrime) {
        v.push_back(pair.second);
    }
}
