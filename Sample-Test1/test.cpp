#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
#include <gtest/gtest.h>
#include <vector>
#include <fstream>
#include <string>
#include "../ConsoleApplication9/func.h" 

using namespace std;

// Тестуємо сортування за зростанням
TEST(ArrayMethodsTest, SortAscendWorks) {
    vector<int> v = { 5, 2, 8, 1, 9 };
    vector<int> expected = { 1, 2, 5, 8, 9 };

    sortAscend(v);

    EXPECT_EQ(v, expected); // Перевіряємо, чи масив став таким, як ми очікували
}

// Тестуємо сортування за спаданням
TEST(ArrayMethodsTest, SortDescendWorks) {
    vector<int> v = { 5, 2, 8, 1, 9 };
    vector<int> expected = { 9, 8, 5, 2, 1 };

    sortDescend(v);

    EXPECT_EQ(v, expected);
}

// Тестуємо суму елементів
TEST(ArrayMethodsTest, SumOfElWorks) {
    vector<int> v = { 10, 20, 30 };
    int expected_sum = 60;

    EXPECT_EQ(sumOfEl(v), expected_sum);
}

// Тестуємо видалення дублікатів
TEST(ArrayMethodsTest, RmDuplicatesWorks) {
    vector<int> v = { 1, 2, 2, 3, 1, 4 };
    vector<int> unique;
    vector<int> expected_unique = { 1, 2, 3, 4 };

    rmDuplicates(v, unique);

    EXPECT_EQ(unique, expected_unique);
}

// Тестуємо запис у JSON файл
TEST(ArrayMethodsTest, JsonOutWorks) {
    string filename = "test_output.json";
    ofstream jout(filename);

    vector<int> v1 = { 1, 2 };
    vector<int> v2 = { 1 };

    // Викликаємо функцію
    JsonOut(jout, 10, 20, 1, v1, v2);
    jout.close();

    // Відкриваємо файл і перевіряємо, чи він не порожній та чи містить правильні дані
    ifstream jin(filename);
    ASSERT_TRUE(jin.is_open()); // Перевіряємо, чи файл взагалі створився

    string content((istreambuf_iterator<char>(jin)), istreambuf_iterator<char>());

    // Шукаємо ключові слова у створеному тексті
    EXPECT_NE(content.find("\"S2\": 10"), string::npos); // Перевіряємо, чи є там "S2": 10
    EXPECT_NE(content.find("\"S3 - S2\": 10"), string::npos);
}

// Тестуємо вивід різниці масивів (перехоплюємо текст з консолі)
TEST(ArrayMethodsTest, PrintDiffsWorks) {
    vector<int> v1 = { 1, 2, 2, 3 };
    vector<int> v2 = { 1, 2 }; // Ваша функція насправді не використовує v2 в логіці, але ми передамо

    // GTest вміє перехоплювати те, що виводиться через cout
    testing::internal::CaptureStdout();

    printDiffs(v1, v2);

    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 2 \n"); // У вашій функції цифра 2 виведеться двічі, бо count > 1
}