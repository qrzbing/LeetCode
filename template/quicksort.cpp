#include "global.hpp"

int partition(int *arr, int left, int right)
{
    // 设定基准值
    int pivot = left, index = left + 1;
    for (int i = index; i <= right; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    // 最后一次交换基准元素和 index
    swap(arr[index - 1], arr[pivot]);
    return index - 1;
}

void quick_sort_recursion(vector<int> &nums, int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    int first = l, last = r - 1, key = nums[first];
    while (first < last)
    {
        while (first < last && nums[last] >= key)
        {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key)
        {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort_recursion(nums, l, first);
    quick_sort_recursion(nums, first + 1, r);
}

void quick_sort_recursion(int *nums, int l, int r)
{
    if (left < right)
    {
        int partition_index = partition(nums, l, r);
        quick_sort_recursion(nums, left, partition_index - 1);
        quick_sort_recursion(nums, partition_index + 1, right);
    }
}