#include"MySort.h"

Mysort::Mysort()
{
	a[0] = 9;
	a[1] = 4;
	a[2] = 2;
	a[3] = 8;
	a[4] = 0;
	a[5] = 5;
	a[6] = 3;
	a[7] = 7;
	a[8] = 6;
	a[9] = 1;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
};

void Mysort::test()
{
	//mergeSort(0, 9);
	quickSort(0, 9);
	for (unsigned int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
};

void Mysort::mergeSort(int left, int right)
{
	if (left == right)
		return;

	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);

	int lindex = left, rindex = mid + 1, tindex = 0;

	while (lindex <= mid && rindex <= right)
	{
		if (a[lindex] < a[rindex])
		{
			temp[tindex] = a[lindex];
			lindex++;
		}
		else
		{
			temp[tindex] = a[rindex];
			rindex++;
		}
		tindex++;
	}

	while (lindex <= mid)
	{
		temp[tindex] = a[lindex];
		lindex++;
		tindex++;
	}

	while (rindex <= right)
	{
		temp[tindex] = a[rindex];
		rindex++;
		tindex++;
	}

	for (int i = left; i <= right; i++)
	{
		//cout << temp[i] << " ";
		a[i] = temp[i - left];
	}
	//cout << endl;
}
void Mysort::quickSort(int left, int right)
{
	if (left >= right)
		return;

	int pivot = a[right];
	int i = left;

	for (int j = left; j <= (right - 1); j++)
	{
		if (a[j] < pivot)
		{
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
		}
	}

	int temp2 = a[i];
	a[i] = a[right];
	a[right] = temp2;

	quickSort(left, i - 1);
	quickSort(i + 1, right);
};