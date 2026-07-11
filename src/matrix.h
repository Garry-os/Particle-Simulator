#pragma once
#include <vector>

// ROWS ARE X
// COLUMNS ARE Y

class Matrix2D {
public:
    Matrix2D(size_t row, size_t col)
        :row(row), col(col), data(row * col, 0.0f) {}
    ~Matrix2D() = default;

    // Setting operator
    double& operator[](size_t r, size_t c) {
        return data[c * row + r];
    }

    // Getting operator
    const double& operator[](size_t r, size_t c) const {
        return data[c * row + r];
    }
    inline size_t get_row() const { return row; }
    inline size_t get_column() const { return col; }

    inline size_t size() const { return data.size(); }

private:
    int row, col;
    std::vector<double> data;
};
