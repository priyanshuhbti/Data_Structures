#include <bits/stdc++.h>
using namespace std;

//This is the code to add two Array and then sort them accordingly ...

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Two example vectors
    std::vector<int> vector1 = {3, 6, 1, 9};
    std::vector<int> vector2 = {4, 8, 2, 7};

    // Merge the vectors
    std::vector<int> merged_vector;
    merged_vector.reserve(vector1.size() + vector2.size());
    std::merge(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), std::back_inserter(merged_vector));

    // Sort the merged vector
    std::sort(merged_vector.begin(), merged_vector.end());

    // Output merged and sorted vector
    std::cout << "Merged vector: ";
    for (int num : merged_vector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
