#include <bits/stdc++.h>
#include "StringData.h"
using namespace std;

struct calculation
{
    int index;
    std::chrono::duration<double> totalTime;
};

typedef struct calculation structure;

structure calculateTime(std::function<int(vector<string>, string)> func, vector<string> container, string element)
{
    structure toReturn;
    auto time1 = std::chrono::system_clock::now();
    toReturn.index = func(container, element);
    auto time2 = std::chrono::system_clock::now();
    toReturn.totalTime = time2 - time1;
    return toReturn;
}

int linearSearch(vector<string>container, string element)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(vector<string> container, string element)
{
    int min = 0;
    int max = container.size() - 1;
    int mid = (min + max) / 2;
    while (container[mid] != element)
    {
        if (element > container[mid] and max > mid)
        {
            int tempmid = mid;
            mid = int(ceil((double(mid) + double(max)) / 2));
            int min = tempmid + 1;
        }
        else if (element < container[mid] and min < mid)
        {
            int tempmid = mid;
            mid = (mid + min) / 2;
            max = tempmid - 1;
        }
        else
        {
            return -1;
        }
    }
    return mid;
}

int main()
{
    vector<string> container = getStringData();
    structure result;
    result = calculateTime(linearSearch, container, "not_here");
    cout << "Search for 'not_here' with Linear Search: i=" << result.index << " t=" << result.totalTime.count() << "s" << endl;
    result = calculateTime(binarySearch, container, "not_here");
    cout << "Search for 'not_here' with Binary Search: i=" << result.index << " t=" << result.totalTime.count() << "s" << endl;
    result = calculateTime(linearSearch, container, "mzzzz");
    cout << "Search for 'mzzzz' with Linear Search: i=" << result.index << " t=" << result.totalTime.count() << "s" << endl;
    result = calculateTime(binarySearch, container, "mzzzz");
    cout << "Search for 'mzzzz' with Binary Search: i=" << result.index << " t=" << result.totalTime.count() << "s" << endl;
    result = calculateTime(linearSearch, container, "aaaaa");
    cout << "Search for 'aaaaa' with Linear Search: i=" << result.index << " t=" << result.totalTime.count() << "s" << endl;
    result = calculateTime(binarySearch, container, "aaaaa");
    cout << "Search for 'aaaaa' with Binary Search: i=" << result.index << " t=" << result.totalTime.count() << "s" << endl;
    return 0;
}

eoiofujosfuosfuoseu
