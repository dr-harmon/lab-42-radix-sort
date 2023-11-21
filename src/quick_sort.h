#pragma once

#include <functional>
#include <random>
#include <utility>
#include <vector>

std::random_device rd;
std::mt19937 mt(rd());

int getPivotIndex(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(mt);
}

template <typename T>
using IsLess = std::function<bool(const T&,const T&)>;

template <typename T>
int partition(std::vector<T>& v, int low, int high, IsLess<T> isLess)
{
    int pivotIndex = getPivotIndex(low, high);
    T pivot = v[pivotIndex];
    std::swap(v[pivotIndex], v[high]);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (isLess(v[j], pivot)) {
            i++;
            std::swap(v[i], v[j]);
        }
    }

    std::swap(v[i + 1], v[high]);

    return i + 1;
}

template <typename T>
void quickSort(std::vector<T>& v, int low, int high, IsLess<T> isLess)
{
    if (low >= high) {
        return;
    }

    int middle = partition(v, low, high, isLess);
    quickSort(v, low, middle - 1, isLess);
    quickSort(v, middle + 1, high, isLess);
}

template <typename T>
void quickSort(std::vector<T>& v, IsLess<T> isLess)
{
    quickSort(v, 0, v.size() - 1, isLess);
}
