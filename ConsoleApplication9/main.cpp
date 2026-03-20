#include "func.h"

int main()
{
    srand(time(0));

    ofstream out("data.txt");
    ofstream jout("data.json");

    int size;
    int n;

    cout << "enter size of array: ";
    cin >> size;

	// Створення масиву V1 та заповнення його випадковими числами
    vector<int> v1(size);
    vector<int> v2;

    for (int i = 0; i < size; i++)
    {
		v1[i] = rand() % 99 + 1;
    }

	cout << "array 1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

	cout << "enter n: ";
    cin >> n;

	// Вивід сум для кожної групи по n елементів
    out << "summed numbers:" << endl;
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
	sortAscend(v1);
    cout << "sorted array 1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl << "sum of elements: " << sumOfEl(v1);
	int sum2 = sumOfEl(v1);
    cout << endl;
    cout << endl;

    sortDescend(v1);
    cout << "sorted array 1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
	cout << endl << "sum of elements: " << sumOfEl(v1);
    cout << endl;
    cout << endl;
	vector<int> copyV1 = v1;
	rmDuplicates(v1, v2);

	// Сума елементів нового масиву V2
	int sum3 = sumOfEl(v2);
    cout << endl;

	cout << "difference of sums S3 - S2: " << sum3 - sum2 << endl;

	// Підрахунок кількості повторюваних елементів
	int sizeV2 = v2.size();
	int duplicatesCount = size - sizeV2;

    cout << "difference of arrays: ";
	printDiffs(copyV1, v2);
    cout << endl;

    JsonOut(jout, sum2, sum3, duplicatesCount, v1, v2);

    out.close();
	jout.close();
}