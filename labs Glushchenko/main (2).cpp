#include <iostream>
#include <vector>
#include <cmath>

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && abs(i - j) <= indexDiff; ++j) {
            if (abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int indexDiff, valueDiff;
    std::cout << "Введите indexDiff: ";
    std::cin >> indexDiff;
    std::cout << "Введите valueDiff: ";
    std::cin >> valueDiff;
    
    std::cout << "Введите элементы массива nums через пробел (чтобы закончить введите дробное число (0.5)): ";
    std::vector<int> nums;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
    }

  

    // Проверка условий и вывод результата
    bool result = containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);
    std::cout << "Результат: " << (result ? "true" : "false") << std::endl;

    return 0;
}