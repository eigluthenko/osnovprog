#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    vector<int> profit1(n, 0);
    vector<int> profit2(n, 0);

    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        profit1[i] = max(profit1[i - 1], prices[i] - minPrice);
    }

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        profit2[i] = max(profit2[i + 1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, profit1[i] + profit2[i]);
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Введите количество дней: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Введите цены на акции для каждого дня:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Максимальная прибыль: " << result << endl;

    return 0;
}