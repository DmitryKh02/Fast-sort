#include <iostream>

void fastSort(int* mas, int first, int last);

int main() {
	int size;
	std::cin >> size;

	int* mas;
	mas = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		mas[i] = rand() % 100;
		std::cout << " " << mas[i];
	}
	std::cout << "\n";
	fastSort(mas,0, size-1);
	std::cout << "\n";

	for (size_t i = 0; i < size; i++)
	{
		std::cout << " " << mas[i];
	}


	std::cin.ignore().get();
	return 0;
}

void fastSort(int* mas,int first, int last) {
	int i = first;
	int j = last;

	int mid = mas[(first+last)/2];//опорный элемент
	do
	{
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}

		if (i <= j) {
			if (mas[i] > mas[j]) {
				int tmp = mas[j];
				mas[j] = mas[i];
				mas[i] = tmp;
			}

			i++;
			j--;
		}
		
	} while (i <= j);

	if (i < last) {
		fastSort(mas, i , last);
	}

	if (first < j) {
		fastSort(mas, first, j);
	}
}