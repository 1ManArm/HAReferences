#include <iostream>

void three_max(int &num1, int &num2, int &num3) {
	int max = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3) ? num2 : num3;
	num1 = num2 = num3 = max;
}

template <typename T>
auto& GetFirstNegative(T& array){
	for (auto& r : array)
		if (r < 0)
			return r;
	return array[0];
}

void null_arr(int first[], int nf, int second[], int ns){
	for (int* p1 = first; p1 != first + nf; ++p1)
		for (int* p2 = second; p2 != second + ns; ++p2)
			if (*p2 == *p1)
				*p2 = 0;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 1.
	std::cout << "Задание 1.\nЧисло 1: ";
	int n1;
	std::cin >> n1;
	std::cout << "Число 2: ";
	int n2;
	std::cin >> n2;
	std::cout << "Число 3: ";
	int n3;
	std::cin >> n3;
	three_max(n1, n2, n3);
	std::cout << n1 << ' ' << n2 << ' ' << n3;

	//Задача 2.
	std::cout << "\n\nЗадание 2.\n";
	int a[]{ 1, 2, -1, 3 };
	auto& result{ GetFirstNegative(a) };
	std::cout << result << std::endl;

	//Задача 3.
	std::cout << "\n\nЗадание 3.\nМассив 1:\n";
	const int size31 = 7;
	int arr31[size31] = { 3, 6, 4, 1, 4, 8, 2 };
	for (int i = 0; i < size31; i++)
		std::cout << arr31[i] << " ";
	std::cout << "\nМассив 2:\n";
	const int size32 = 6;
	int arr32[size32] = { 5, 3, 1, 5, 10, 8 };
	for (int i = 0; i < size32; i++)
		std::cout << arr32[i] << " ";
	null_arr(arr31, size31, arr32, size32);
	std::cout << "\nМассив 2 после работы функции:\n";
	for (int i = 0; i < size32; i++)
		std::cout << arr32[i] << " ";

	return 0;
}