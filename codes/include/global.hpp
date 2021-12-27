#ifndef __GLOBAL_HPP__
#define __GLOBAL_HPP__

#include <iostream>

#include <string>

#include <vector>
#include <array>

// stack
#include <stack>

// queue
#include <queue>
#include <deque>

// hashmap/set
#include <unordered_map>
#include <unordered_set>
#include <set>

// math
#include <cmath>

// algorithm
#include <algorithm>

// std::bind
#include <functional>

using namespace std;

template <typename T>
void cout_vector(vector<T> vec)
{
    for (auto num : vec)
    {
        cout << num << " ";
    }
    cout << "\n";
}

#endif