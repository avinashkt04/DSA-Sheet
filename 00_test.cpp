#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<double> nums = {-5.5, 10.25, -15.75, 20.8};

    for (int i = 0; i < nums.size(); ++i) {
        double absoluteValue = std::abs(nums[i]);
        std::cout << "Absolute value of " << nums[i] << " is " << absoluteValue << std::endl;
    }

    return 0;
}