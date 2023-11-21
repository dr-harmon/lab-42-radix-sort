#pragma once

#include <utility>
#include <vector>

template <typename T>
void bucketSort(std::vector<std::pair<int,T>>& v, int maxKey)
{
    std::vector<std::vector<T>> buckets(maxKey + 1);

    for (const auto& pair : v) {
        buckets[pair.first].push_back(pair.second);
    }

    v.clear();

    for (int i = 0; i < buckets.size(); i++) {
        for (const auto& element : buckets[i]) {
            v.emplace_back(std::make_pair(i, element));
        }
    }
}
