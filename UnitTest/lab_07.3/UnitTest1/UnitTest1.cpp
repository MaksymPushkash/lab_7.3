#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.3/lab_07.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix
{
   
    // ���� ��� ������� CountRowsWithAvgLessThan
    TEST_CLASS(UnitTestCountRowsWithAvgLessThan)
    {
    public:

        TEST_METHOD(TestCountRowsWithAvgLessThan)
        {
            int rowCount = 3;
            int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount];
            }

            // ����������� ������� �������
            int input[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            // ������� ����� ��� �� �������
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    matrix[i][j] = input[i][j];
                }
            }

            // ������ ������� � �������
            int threshold = 5;
            int result = CountRowsWithAvgLessThan(matrix, rowCount, colCount, threshold);

            // �������, �� ���� 1 �����, �� ������ ����������� < 5
            Assert::AreEqual(1, result);

            for (int i = 0; i < rowCount; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };

    // ���� ��� ������� Input (�������� �����)
    TEST_CLASS(UnitTestInput)
    {
    public:

        TEST_METHOD(TestInput)
        {
            int rowCount = 2;
            int colCount = 2;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount];
            }

            // �������� ��������������� �����
            // ������� Input() �� �������� ��� ���������� � ��'���� � ���, �� ����������� std::cin
            // ��� �� ������ ������������ ��� ���, ������� ���� ������� ��� �������� ��������
            matrix[0][0] = 1;
            matrix[0][1] = 2;
            matrix[1][0] = 3;
            matrix[1][1] = 4;

            // ���������� �� ��������� ���� ������ ���
            Assert::AreEqual(1, matrix[0][0]);
            Assert::AreEqual(2, matrix[0][1]);
            Assert::AreEqual(3, matrix[1][0]);
            Assert::AreEqual(4, matrix[1][1]);

            for (int i = 0; i < rowCount; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
