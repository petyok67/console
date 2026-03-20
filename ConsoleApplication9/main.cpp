#include "fucn.h"

int main()
{
    srand(time(0));

    ofstream out("data.txt");
    ofstream jout("data.json");

    int size;
    int n;

    cout << "Enter size of array: ";
    cin >> size;

	// Створення масиву V1 та заповнення його випадковими числами
    vector<int> v1(size);
    vector<int> v2;

    for (int i = 0; i < size; i++)
    {
		v1[i] = rand() % 99 + 1;
    }

	// Вивід масиву на екран
	cout << "Array V1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

	cout << "Enter n: ";
    cin >> n;

	// Вивід сум для кожної групи по n елементів
    out << "Summed numbers:" << endl;
    for (int i = 0; i < v1.size(); i += n)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i + j < v1.size()) {
                sum += v1[i + j];
            }
        }
        out << sum << endl;
    }
    cout << endl;
	// Сортування масиву за зростанням та вивід на екран
	sortAsc(v1);
    cout << "Sorted array V1(ASC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl << "Sum of elements (ASC): " << sumOfElements(v1);
	int sum2 = sumOfElements(v1);
    cout << endl;
    cout << endl;

	// Сортування масиву за спаданням та вивід на екран
    sortDesc(v1);
    cout << "Sorted array V1(DESC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
	cout << endl << "Sum of elements (DESC): " << sumOfElements(v1);
    cout << endl;
    cout << endl;

	// Видалення повторюваних елементів та створення нового масиву V2, та створення копії масиву V1 для подальшого виводу різниці масивів
	vector<int> copyV1 = v1;
	rmDuplicates(v1, v2);
	// Сума елементів нового масиву V2
	int sum3 = sumOfElements(v2);
    cout << endl;

	// Різниця сум S3 - S2
	cout << "Difference of sums S3 - S2: " << sum3 - sum2 << endl;

	// Підрахунок кількості повторюваних елементів
	int sizeV2 = v2.size();
	int duplicatesCount = size - sizeV2;

	// Вивід різниці масивів |V1 - V2| (елементи, які були видалені)
    cout << "Difference of arrays |V1 - V2|: ";
	printDifference(copyV1, v2);
    cout << endl;

    // Запис результатів у JSON файл
    JsonOut(jout, sum2, sum3, duplicatesCount, v1, v2);

	// Закриття файлу
    out.close();
	jout.close();
}