#include <iostream>
#include <vector>

using namespace std;

class Matrica {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    Matrica() {
        rows = 0;
        cols = 0;
    }

    Matrica(int r, int c) {
        rows = r;
        cols = c;
        mat.resize(rows, vector<int>(cols));
    }

    friend istream& operator>>(istream& is, Matrica& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                is >> m.mat[i][j];
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Matrica& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                os << m.mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    vector<int>& operator[](int i) {
        return mat[i];
    }

    Matrica operator+(const Matrica& m) const {
        Matrica res(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return res;
    }

    Matrica operator-(const Matrica& m) const {
        Matrica res(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return res;
    }

    Matrica operator*(const int scalar) const {
        Matrica result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    bool operator==(const Matrica& other) const {
        return (rows == other.rows && cols == other.cols && data == other.data);
    }

    bool operator!=(const Matrica& other) const {
        return !(*this == other);
    }

    Matrica& operator=(const Matrica& other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
        return *this;
    }

    Matrica(const std::vector<int>& vec) : rows(1), cols(vec.size()), data(1, vec) {}

    operator std::vector<int>() const {
        if (rows != 1) {
            throw std::invalid_argument("Matrix must have only one row.");
        }
        return data[0];
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    Matrica m(rows, cols);
    std::cout << "Enter the matrix elements:" << std::endl;
    std::cin >> m;
    std::cout << "The matrix is:" << std::endl;
    std::cout << m << std::endl;

    int option;
    do {
        std::cout << "Select an option:" << std::endl;
        std::cout << "1. Add matrices" << std::endl;
        std::cout << "2. Subtract matrices" << std::endl;
        std::cout << "3. Multiply matrices" << std::endl;
        std::cout << "4. Add scalar" << std::endl;
        std::cout << "5. Subtract scalar" << std::endl;
        std::cout << "6. Multiply scalar" << std::endl;
        std::cout << "7. Check for equality" << std::endl;
        std::cout << "8. Convert to vector" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cin >> option;

         switch (option) {
                        case 1: {
                std::cout << "Enter the second matrix:" << std::endl;
                Matrica m2(rows, cols);
                std::cin >> m2;
                std::cout << "The sum is:" << std::endl;
                std::cout << m + m2 << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter the second matrix:" << std::endl;
                Matrica m2(rows, cols);
                std::cin >> m2;
                std::cout << "The difference is:" << std::endl;
                std::cout << m - m2 << std::endl;
                break;
            }
            case 3: {
                std::cout << "Enter the second matrix:" << std::endl;
                int otherCols;
                std::cin >> otherCols;
                Matrica m2(cols, otherCols);
                std::cin >> m2;
                std::cout << "The product is:" << std::endl;
                std::cout << m * m2 << std::endl;
                break;
            }
            case 4: {
                int scalar;
                std::cout << "Enter the scalar:" << std::endl;
                std::cin >> scalar;
                std::cout << "The sum is:" << std::endl;
                std::cout << m + scalar << std::endl;
                break;
            }
            case 5: {
                int scalar;
                std::cout << "Enter the scalar:" << std::endl;
                std::cin >> scalar;
                std::cout << "The difference is:" << std::endl;
                std::cout << m - scalar << std::endl;
                break;
            }
            case 6: {
                int scalar;
                std::cout << "Enter the scalar:" << std::endl;
                std::cin >> scalar;
                std::cout << "The product is:" << std::endl;
                std::cout << m * scalar << std::endl;
                break;
            }
            case 7: {
                std::cout << "Enter the second matrix:" << std::endl;
                Matrica m2(rows, cols);
                std::cin >> m2;
                std::cout << "The matrices are ";
                if (m == m2) {
                    std::cout << "equal." << std::endl;
                } else {
                    std::cout << "not equal." << std::endl;
                }
                break;
            }
                 case 8: {
                std::vector<int> vec = static_cast<std::vector<int>>(m);
                std::cout << "The matrix as a vector is: ";
                for (int i = 0; i < vec.size(); i++) {
                    std::cout << vec[i] << " ";
                }
                std::cout << std::endl;
                break;
            }
                        case 0: {
                int scalar;
                std::cout << "Enter scalar value: ";
                std::cin >> scalar;
                Matrica result(rows, cols);
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        result[i][j] = data[i][j] * scalar;
                    }
                }
                std::cout << "Result of multiplication: " << std::endl;
                std::cout << result;
                break;
            }
         }
    }
    return 0;
}
         


