#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);

void Print(int** a, const int rowCount, const int colCount);

void GaussianElimination(int** matrix, int rowCount, int colCount);

int CountRowsWithAvgLessThan(int** matrix, int rowCount, int colCount, int threshold);


int main()
{
    srand((unsigned)time(NULL));

    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        matrix[i] = new int[colCount];

    Input(matrix, rowCount, colCount);

    cout << "Початкова матриця: ";
    Print(matrix, rowCount, colCount);


    GaussianElimination(matrix, rowCount, colCount);
    cout << "Трикутна матриця: ";
    Print(matrix, rowCount, colCount);

    int threshold;
    cout << "Порогове значення: ";
    cin >> threshold;

    int count = CountRowsWithAvgLessThan(matrix, rowCount, colCount, threshold);
    cout << "Кількість рядків із середнім значенням менше " << threshold << ": " << count << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}


void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}


void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}


void GaussianElimination(int** matrix, int rowCount, int colCount)
{
    for (int k = 0; k < rowCount; k++)
    {
        for (int i = k + 1; i < rowCount; i++)
        {
            if (abs(matrix[k][k]) < abs(matrix[i][k]))
            {

                for (int j = 0; j < colCount; j++)
                {
                    swap(matrix[k][j], matrix[i][j]);
                }
            }
        }

        for (int j = k + 1; j < colCount; j++)
        {
            matrix[k][j] /= matrix[k][k];
        }
        matrix[k][k] = 1;

        for (int i = k + 1; i < rowCount; i++)
        {
            int factor = matrix[i][k];
            for (int j = k; j < colCount; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }
}


int CountRowsWithAvgLessThan(int** matrix, int rowCount, int colCount, int threshold)
{
    int count = 0;
    for (int i = 0; i < rowCount; i++)
    {
        int sum = 0;
        for (int j = 0; j < colCount; j++)
        {
            sum += matrix[i][j];
        }
        double avg = sum / static_cast<double>(colCount);
        if (avg < threshold)
        {
            count++;
        }
    }
    return count;
}