#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Print a Matrix Row-Wise and Column-Wise
void printMatrixRowWise(const vector<vector<int>>& matrix) 
{
    cout << "Row-wise:" << endl;
    for (const auto& row : matrix) 
    {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

void printMatrixColumnWise(const vector<vector<int>>& matrix) 
{
    cout << "Column-wise:" << endl;
    if (matrix.empty()) return;
    int rows = matrix.size(), cols = matrix[0].size();
    for (int col = 0; col < cols; ++col) 
    {
        for (int row = 0; row < rows; ++row) 
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     printMatrixRowWise(matrix);
//     printMatrixColumnWise(matrix);
//     return 0;
// }

// 2. Calculate the Total Sum of Elements in a Matrix
int totalSum(const vector<vector<int>>& matrix) 
{
    int sum = 0;
    for (const auto& row : matrix)
        for (int val : row)
            sum += val;
    return sum;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     cout << "Total sum: " << totalSum(matrix) << endl;
//     return 0;
// }

// 3. Calculate the Sum of Each Row and Each Column in a Matrix
vector<int> rowSums(const vector<vector<int>>& matrix) 
{
    vector<int> sums;
    for (const auto& row : matrix)
    {
        int sum = 0;
        for (int val : row) sum += val;
        sums.push_back(sum);
    }
    return sums;
}

vector<int> colSums(const vector<vector<int>>& matrix) 
{
    if (matrix.empty()) return {};
    int cols = matrix[0].size();
    vector<int> sums(cols, 0);
    for (const auto& row : matrix)
        for (int col = 0; col < cols; ++col)
            sums[col] += row[col];
    return sums;
}

// int main () {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     vector<int> rSums = rowSums(matrix);
//     vector<int> cSums = colSums(matrix);
//     cout << "Row sums: ";
//     for (int s : rSums) cout << s << " ";
//     cout << endl;
//     cout << "Column sums: ";
//     for (int s : cSums) cout << s << " ";
//     cout << endl;
//     return 0;
// }

// 4. Find the Maximum and Minimum Values in Each Row of a Matrix
vector<pair<int, int>> rowMaxMin(const vector<vector<int>>& matrix) 
{
    vector<pair<int, int>> result;
    for (const auto& row : matrix) 
    {
        int mx = row[0], mn = row[0];
        for (int val : row) 
        {
            mx = max(mx, val);
            mn = min(mn, val);
        }
        result.push_back({mx, mn});
    }
    return result;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     auto res = rowMaxMin(matrix);
//     for (int i = 0; i < res.size(); ++i)
//         cout << "Row " << i << " max: " << res[i].first << ", min: " << res[i].second << endl;
//     return 0;
// }

// 5. Find the Maximum and Minimum Values in Each Column of a Matrix
vector<pair<int, int>> colMaxMin(const vector<vector<int>>& matrix) 
{
    if (matrix.empty()) return {};
    int cols = matrix[0].size(), rows = matrix.size();
    vector<pair<int, int>> result;
    for (int col = 0; col < cols; ++col) 
    {
        int mx = matrix[0][col], mn = matrix[0][col];
        for (int row = 0; row < rows; ++row) 
        {
            mx = max(mx, matrix[row][col]);
            mn = min(mn, matrix[row][col]);
        }
        result.push_back({mx, mn});
    }
    return result;
}

// int main () {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     auto res = colMaxMin(matrix);
//     for (int i = 0; i < res.size(); ++i)
//         cout << "Col " << i << " max: " << res[i].first << ", min: " << res[i].second << endl;
//     return 0;
// }

// 6. Add and Subtract Two Matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b) 
{
    int rows = a.size(), cols = a[0].size();
    vector<vector<int>> res(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            res[i][j] = a[i][j] + b[i][j];
    return res;
}

vector<vector<int>> subtractMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b) 
{
    int rows = a.size(), cols = a[0].size();
    vector<vector<int>> res(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            res[i][j] = a[i][j] - b[i][j];
    return res;
}

void printMatrix(const vector<vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

// int main() {
//     vector<vector<int>> a = {
//         {1, 2, 3},
//         {4, 5, 6}
//     };
//     vector<vector<int>> b = {
//         {7, 8, 9},
//         {1, 2, 3}
//     };
//     cout << "Addition:" << endl;
//     printMatrix(addMatrices(a, b));
//     cout << "Subtraction:" << endl;
//     printMatrix(subtractMatrices(a, b));
//     return 0;
// }

// 7. Print the Upper and Lower Triangle of a Matrix
void printUpperTriangle(const vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    cout << "Upper triangle:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
            if (i <= j) cout << matrix[i][j] << " ";
            else cout << "  ";
        cout << endl;
    }
}

void printLowerTriangle(const vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    cout << "Lower triangle:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
            if (i >= j) cout << matrix[i][j] << " ";
            else cout << "  ";
        cout << endl;
    }
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     printUpperTriangle(matrix);
//     printLowerTriangle(matrix);
//     return 0;
// }

// 8. Print the Left and Right Diagonals of a Matrix
void printLeftDiagonal(const vector<vector<int>>& matrix) 
{
    cout << "Left diagonal: ";
    for (int i = 0; i < matrix.size(); ++i)
        cout << matrix[i][i] << " ";
    cout << endl;
}

void printRightDiagonal(const vector<vector<int>>& matrix) 
{
    cout << "Right diagonal: ";
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
        cout << matrix[i][n - i - 1] << " ";
    cout << endl;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     printLeftDiagonal(matrix);
//     printRightDiagonal(matrix);
//     return 0;
// }

// 9. Print the Boundary Elements of a Matrix
void printBoundary(const vector<vector<int>>& matrix) 
{
    int rows = matrix.size(), cols = matrix[0].size();
    cout << "Boundary elements: ";
    for (int i = 0; i < cols; ++i) cout << matrix[0][i] << " ";
    for (int i = 1; i < rows - 1; ++i) cout << matrix[i][cols - 1] << " ";
    if (rows > 1)
        for (int i = cols - 1; i >= 0; --i) cout << matrix[rows - 1][i] << " ";
    for (int i = rows - 2; i > 0; --i) cout << matrix[i][0] << " ";
    cout << endl;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12}
//     };
//     printBoundary(matrix);
//     return 0;
// }

// 10. Sort the Matrix Row-Wise and Column-Wise
void sortRows(vector<vector<int>>& matrix) 
{
    for (auto& row : matrix)
        sort(row.begin(), row.end());
}

void sortCols(vector<vector<int>>& matrix) 
{
    if (matrix.empty()) return;
    int rows = matrix.size(), cols = matrix[0].size();
    for (int col = 0; col < cols; ++col) 
    {
        vector<int> temp;
        for (int row = 0; row < rows; ++row)
            temp.push_back(matrix[row][col]);
        sort(temp.begin(), temp.end());
        for (int row = 0; row < rows; ++row)
            matrix[row][col] = temp[row];
    }
}

// int main() {
//     vector<vector<int>> matrix = {
//         {3, 2, 1},
//         {6, 5, 4},
//         {9, 8, 7}
//     };
//     sortRows(matrix);
//     cout << "Row-wise sorted:" << endl;
//     printMatrix(matrix);
//     sortCols(matrix);
//     cout << "Column-wise sorted:" << endl;
//     printMatrix(matrix);
//     return 0;
// }

// 11. Print the Matrix in a Zig-Zag Pattern
void printZigZag(const vector<vector<int>>& matrix) 
{
    int rows = matrix.size();
    cout << "Zig-zag pattern:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        if (i % 2 == 0)
            for (int val : matrix[i]) cout << val << " ";
        else
            for (int j = matrix[i].size() - 1; j >= 0; --j) cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };
//     printZigZag(matrix);
//     return 0;
// }

// 12. Check if a Matrix is Symmetric
bool isSymmetric(const vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] != matrix[j][i]) return false;
    return true;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {2, 5, 6},
//         {3, 6, 9}
//     };
//     cout << (isSymmetric(matrix) ? "Symmetric" : "Not symmetric") << endl;
//     return 0;
// }

// 13. Check if a Matrix is an Identity Matrix
bool isIdentity(const vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                return false;
    return true;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 0, 0},
//         {0, 1, 0},
//         {0, 0, 1}
//     };
//     cout << (isIdentity(matrix) ? "Identity matrix" : "Not identity matrix") << endl;
//     return 0;
// }

// 14. Check if a Matrix is Sparse (Mostly Zeroes)
bool isSparse(const vector<vector<int>>& matrix) 
{
    int total = matrix.size() * matrix[0].size();
    int zeroCount = 0;
    for (const auto& row : matrix)
        for (int val : row)
            if (val == 0) ++zeroCount;
    return zeroCount > total / 2;
}

// int main() {
//     vector<vector<int>> matrix = {
//         {0, 0, 1},
//         {0, 0, 0},
//         {0, 0, 0}
//     };
//     cout << (isSparse(matrix) ? "Sparse matrix" : "Not sparse matrix") << endl;
//     return 0;
// }

// 15. Find the Inverse of a Matrix
// For simplicity, only for 2x2 matrix
vector<vector<double>> inverse2x2(const vector<vector<int>>& matrix) 
{
    int a = matrix[0][0], b = matrix[0][1], c = matrix[1][0], d = matrix[1][1];
    int det = a * d - b * c;
    vector<vector<double>> inv(2, vector<double>(2));
    if (det == 0) return inv;
    inv[0][0] = d / (double)det;
    inv[0][1] = -b / (double)det;
    inv[1][0] = -c / (double)det;
    inv[1][1] = a / (double)det;
    return inv;
}

void printMatrixDouble(const vector<vector<double>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (double val : row) cout << val << " ";
        cout << endl;
    }
}

// int main() {
//     vector<vector<int>> matrix = {
//         {4, 7},
//         {2, 6}
//     };
//     cout << "Inverse:" << endl;
//     printMatrixDouble(inverse2x2(matrix));
//     return 0;
// }
