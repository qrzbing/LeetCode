#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = 0; j < arr.size() - 1 - i; ++j)
        { // 这里 j 的取值范围中的 -i 代表着 i 轮后有 i 个最大数字已经被排好。
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}