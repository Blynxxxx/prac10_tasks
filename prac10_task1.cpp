#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> values{2, 5};
    // Insert numbers 3, 4 at the correct place.
    values.insert(values.begin() + 1, 3);
    values.insert(values.begin() + 2, 4);

    vector<int> vec{0, 1};
    // Insert the contents of vec to values.
    values.insert(values.begin(), vec.cbegin(), vec.cend());

    vector<int> anotherVec;
    // Loop over the element of values in severse and insert to anotherVec.
    for (auto i = values.rbegin(); i != values.rend(); ++i)
    {
        anotherVec.push_back(*i);
    }

    // Print content of anotherVec.
    for (auto &j : anotherVec)
    {
        cout << anotherVec[j] << " ";
    }

    return 0;
}