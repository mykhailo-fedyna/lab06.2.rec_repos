//lab6.2(rec).cpp
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i)
{
	if (i < size) {
		r[i] = Low + rand() % (High - Low + 1);
		Create(r, size, Low, High, i + 1);
	}
}

void Print(int* r, const int size, int i)
{
	if (i < size) {
		cout << setw(4) << r[i];
		Print(r, size, i + 1);
	}
	else {
		cout << endl;
	}
}

int Max(int* r, const int size, int i, int max)
{
	if (r[i] > max && r[i] % 2 == 0)
		max = r[i];
	if (i < size - 1)
		return Max(r, size, i + 1, max);
	else
		return max;
}

int MaxIndex(int* r, const int size, int max, int i)
{
	if (i >= size)
		return -1;

	if (r[i] == max)
		return i;

	return MaxIndex(r, size, max, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 30;
	int r[n];
	int Low = 1;
	int High = 200;

	Create(r, n, Low, High, 0);
	Print(r, n, 0);

	int max = Max(r, n, 1, r[0]);
	cout << "Max = " << max << endl;
	cout << "Index of Max = " << MaxIndex(r, n, max, 0) << endl;

	return 0;
}
