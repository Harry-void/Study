#include<iostream>

using namespace std;

class Mysort
{
public:
	void mergeSort(int left, int right);//πÈ≤¢≈≈–Ú
	void quickSort(int left, int right);//øÏÀŸ≈≈–Ú
	//void partitionOfQuickSort(int left, int right);
	void test();

	Mysort();
private:
	int a[10];
	int temp[10];
};