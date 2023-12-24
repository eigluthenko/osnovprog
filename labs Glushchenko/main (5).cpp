#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0); 

    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
    
        for (int j = 0; j < cols; ++j) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }

        stack<int> s;
        for (int j = 0; j <= cols; ++j) {
            while (!s.empty() && (j == cols || heights[j] < heights[s.top()])) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? j : j - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(j);
        }
    }

    return maxArea;
}

int main() {
    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> cols;

    vector<vector<char>> matrix(rows, vector<char>(cols, '0'));

    cout << "Введите элементы матрицы (подряд, через пробел):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = maximalRectangle(matrix);
    cout << "Максимальная площадь прямоугольника: " << result << endl;

    return 0;
}