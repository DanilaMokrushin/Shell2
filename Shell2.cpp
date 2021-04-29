// Shell2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include <random>
#include <algorithm>
#include <ctime>


using namespace std;
template <typename T>
void ShellSort(vector<T>& Vector) {
	int n = Vector.size();
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int v = Vector[i];
			int j = i;
			while (j >= gap && Vector[j - gap] > v) {
				Vector[j] = Vector[j - gap];
				j -= gap;
			}
			Vector[j] = v;
		}
	}
}


int main() {
	vector<int> vector(500000);
	generate(vector.begin(), vector.end(),rand);
	clock_t start = clock();
	ShellSort(vector);
	clock_t end = clock();
	double seconds = (double)(end - start);
	printf("Time: %f seconds\n", seconds/1000);
	return 0;
}