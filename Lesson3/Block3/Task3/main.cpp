#include <iostream>

using namespace std;

int * input_sparse_matrix(int *, int *);

void print_sparse_matrix(int [], int);

int * sum_sparse_matrixs(int *, int *, int *, int, int *, int);

int * mul_sparse_matrixs(int *, int *, int *, int, int *, int);

int main()
{
    // Using coordinate list
    int *sparse_matrix_1 = nullptr;
    int sparse_matrix_size_1 = 0;
    sparse_matrix_1 = input_sparse_matrix(sparse_matrix_1, &sparse_matrix_size_1);
    cout << 0 << " " << sparse_matrix_1 << endl;
    cout << 0 << " " << sparse_matrix_size_1 << endl;
    print_sparse_matrix(sparse_matrix_1, sparse_matrix_size_1);

    int *sparse_matrix_2 = nullptr;
    int sparse_matrix_size_2 = 0;
    sparse_matrix_2 = input_sparse_matrix(sparse_matrix_2, &sparse_matrix_size_2);
    cout << 0 << " " << sparse_matrix_2 << endl;
    print_sparse_matrix(sparse_matrix_2, sparse_matrix_size_2);

    int *sum_two_matrix = nullptr;
    int sum_two_matrix_size = 0;
    sum_two_matrix = sum_sparse_matrixs(sum_two_matrix,
                                        &sum_two_matrix_size,
                                        sparse_matrix_1,
                                        sparse_matrix_size_1,
                                        sparse_matrix_2,
                                        sparse_matrix_size_2
                                        );
    print_sparse_matrix(sum_two_matrix, sum_two_matrix_size);

    int *mul_two_matrix = nullptr;
    int mul_two_matrix_size = 0;
    mul_two_matrix = mul_sparse_matrixs(mul_two_matrix,
                                        &mul_two_matrix_size,
                                        sparse_matrix_1,
                                        sparse_matrix_size_1,
                                        sparse_matrix_2,
                                        sparse_matrix_size_2
                                        );
    print_sparse_matrix(mul_two_matrix, mul_two_matrix_size);

    return 0;
}

int * input_sparse_matrix(int *sparse_matrix, int *sparse_matrix_size_1) {
    int val_number = 0;
    cout << "Enter number of non-zero values in matrix: ";
    cin >> val_number;
    cout << 1 << " " << sparse_matrix << endl;
    // Create just list where each three items - new coordinate and value
    sparse_matrix = new int [val_number * 3];
    cout << 2 << " " << sparse_matrix << endl;
    int line = 0, column = 0, value = 0;
    for (int i = 0; i < val_number; i++) {
        cout << "Enter line, column and value (line and column should be 0 and bigger): ";
        cin >> line >> column >> value;
        *(sparse_matrix + i * 3) = line;
        *(sparse_matrix + i * 3 + 1) = column;
        *(sparse_matrix + i * 3 + 2) = value;
    }
    *sparse_matrix_size_1 = val_number * 3;

    return sparse_matrix;
}

void print_sparse_matrix(int sparse_matrix[], int matrix_size) {
    cout << 3 << " " << sparse_matrix << endl;
    cout << matrix_size << endl;

    for (int i = 0; i < matrix_size; i += 3) {
        cout << "Line: " << *(sparse_matrix + i);
        cout << " Column: " << *(sparse_matrix + i + 1);
        cout << " Value: " << *(sparse_matrix + i + 2) << endl;
    }
}

int * sum_sparse_matrixs(int *new_sparse_matrix,
                         int *new_sparse_matrix_size,
                         int *sparse_matrix_1,
                         int sparse_matrix_size_1,
                         int *sparse_matrix_2,
                         int sparse_matrix_size_2
                         ) {

    *new_sparse_matrix_size = sparse_matrix_size_1 + sparse_matrix_size_2;
    new_sparse_matrix = new int [*new_sparse_matrix_size];
    int new_matrix_index = 0;

    for (int i = 0; i < sparse_matrix_size_1; i += 3) {
        bool find_flag = false;

        for (int j = 0; j < sparse_matrix_size_2; j += 3) {

            // Add values with the same line and column values
            if (*(sparse_matrix_1 + i) == *(sparse_matrix_2 + j) and
                *(sparse_matrix_1 + i + 1) == *(sparse_matrix_2 + j + 1) and
                (*(sparse_matrix_1 + i + 2) + *(sparse_matrix_2 + j + 2)) != 0
                )
            {
                *(new_sparse_matrix + new_matrix_index) = *(sparse_matrix_1 + i);
                *(new_sparse_matrix + new_matrix_index + 1) = *(sparse_matrix_1 + i + 1);
                *(new_sparse_matrix + new_matrix_index + 2) = *(sparse_matrix_1 + i + 2) + *(sparse_matrix_2 + j + 2);
                new_matrix_index += 3;
                find_flag = true;
                break;
            }
        }

        // If items with the same line and column values are not exist -
        // just add coordinate from the first matrix
        if (!find_flag) {
            *(new_sparse_matrix + new_matrix_index) = *(sparse_matrix_1 + i);
            *(new_sparse_matrix + new_matrix_index + 1) = *(sparse_matrix_1 + i + 1);
            *(new_sparse_matrix + new_matrix_index + 2) = *(sparse_matrix_1 + i + 2);
            new_matrix_index += 3;
        }

    }

    // Add the rest of values from the second matrix
    for (int i = 0; i < sparse_matrix_size_2; i += 3) {
        bool find_flag = false;
        // Search items from the second matrix in new matrix
        for (int j = 0; j < *new_sparse_matrix_size; j += 3) {
            if (*(sparse_matrix_2 + i) == *(new_sparse_matrix + j) and
                *(sparse_matrix_2 + i + 1) == *(new_sparse_matrix + j + 1))
            {
                find_flag = true;
                break;
            }
        }

        // If items with the same line and column values are not exist -
        // add coordinate from the second matrix
        if (!find_flag) {
            *(new_sparse_matrix + new_matrix_index) = *(sparse_matrix_2 + i);
            *(new_sparse_matrix + new_matrix_index + 1) = *(sparse_matrix_2 + i + 1);
            *(new_sparse_matrix + new_matrix_index + 2) = *(sparse_matrix_2 + i + 2);
            new_matrix_index += 3;
        }
    }

    // Delete all zero values
    int *temp_matrix = new int [new_matrix_index];
    for (int i = 0; i < new_matrix_index; i++) {
        *(temp_matrix + i) = *(new_sparse_matrix + i);
    }
    *new_sparse_matrix_size = new_matrix_index;
    delete new_sparse_matrix;
    new_sparse_matrix = temp_matrix;

    return new_sparse_matrix;
}


int * mul_sparse_matrixs(int *new_sparse_matrix,
                         int *new_sparse_matrix_size,
                         int *sparse_matrix_1,
                         int sparse_matrix_size_1,
                         int *sparse_matrix_2,
                         int sparse_matrix_size_2
                         ) {

    *new_sparse_matrix_size = sparse_matrix_size_1 + sparse_matrix_size_2;
    new_sparse_matrix = new int [*new_sparse_matrix_size];
    int new_matrix_index = 0;

    // Check if values from the first matrix have non-zero multipliers from the second matrix
    for (int i = 0; i < sparse_matrix_size_1; i += 3) {

        for (int j = 0; j < sparse_matrix_size_2; j += 3) {
            // Compare line numbers and column numbers
            if (*(sparse_matrix_1 + i) == *(sparse_matrix_2 + j + 1) and
                *(sparse_matrix_1 + i + 1) == *(sparse_matrix_2 + j)) {

                // Find coordinate in new matrix
                bool find_flag = false;
                for (int k = 0; k < new_matrix_index; k += 3) {
                    if (*(sparse_matrix_1 + i) == *(new_sparse_matrix + k) and
                        *(sparse_matrix_2 + j + 1) == *(new_sparse_matrix + k + 1))
                    {
                        *(new_sparse_matrix + k + 2) += *(sparse_matrix_1 + i + 2) * *(sparse_matrix_2 + j + 2);
                        find_flag = true;
                        break;
                    }

                }
                // Add them if doesn't exist
                if (!find_flag) {
                    *(new_sparse_matrix + new_matrix_index) = *(sparse_matrix_1 + i);
                    *(new_sparse_matrix + new_matrix_index + 1) = *(sparse_matrix_2 + j + 1);
                    *(new_sparse_matrix + new_matrix_index + 2) = *(sparse_matrix_1 + i + 2) * *(sparse_matrix_2 + j + 2);
                    new_matrix_index += 3;
                }
                break;
            }
        }
    }

    int number_zero_values = 0;
    // Count number of zero values after multiplication
    for (int i = 0; i < new_matrix_index; i += 3) {
        if (*(new_sparse_matrix + i + 2) == 0) {
            number_zero_values++;
        }
    }

    // Delete all zero values
    int *temp_matrix = new int [new_matrix_index - number_zero_values];
    for (int i = 0; i < new_matrix_index; i++) {
        if (*(new_sparse_matrix + i + 2) != 0) {
            *(temp_matrix + i) = *(new_sparse_matrix + i);
            *(temp_matrix + i + 1) = *(new_sparse_matrix + i + 1);
            *(temp_matrix + i + 2) = *(new_sparse_matrix + i + 2);
        }
    }

    // Set new size of new matrix (after deleting zero values)
    *new_sparse_matrix_size = new_matrix_index - number_zero_values;
    delete new_sparse_matrix;
    new_sparse_matrix = temp_matrix;

    return new_sparse_matrix;
}
