#pragma once

#include <iostream>
#include <vector>


namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
	{t < t} -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	
	for(unsigned int i = 0; i < n-1; i++)
	{
		for(unsigned int j = i+1; j < n; j++)
		{	if(v[j] < v[i])
			{
				// swap(v[j], v[i]);
				T tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}
		}
	}
}


template<Sortable T>
void heap(std::vector<T>& arr, unsigned int n, int i)
{
	int radice = i; // posizione della radice
	int sx = 2*i + 1; // posizione del figlio sinistro
	int dx = 2*i + 2; // posizione del figlio destro
	
	// scambio in base alla priorità
	if(sx < n && arr[sx] > arr[radice])
		radice = sx;
	
	if(dx < n && arr[dx] > arr[radice])
		radice = dx;
	
	if(radice != i)
	{
		//swap(arr[i], arr[radice]);
		T tmp = arr[i];
		arr[i] = arr[radice];
		arr[radice] = tmp;
		heap(arr, n, tmp);
	}
}

template<Sortable T>
void HeapSort(std::vector<T>& arr)
{
	unsigned int n = arr.size();
	
	// costruisco l'heaptree
	for(unsigned int i = 0; i < (n/2 - 1); i--)
		heap(arr, n, i);
	
	// estraggo ogni elemento dell'heaptree
	for(unsigned int i = 0; i < (n-1); i--)
	{
		//swap(arr[0], arr[i]);
		T tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heap(arr, i, 0);
	}
}

}


