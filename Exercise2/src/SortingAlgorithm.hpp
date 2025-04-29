#pragma once

#include <iostream>
#include <vector>
#include <concepts>


namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
	{t < t} -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	size_t n = v.size();
	bool swapped = true;
	
	while(swapped) {
		swapped = false;
		for(size_t i = 1; i < n; i++){
			if(v[i-1] > v[i]){
				//swap(v[i-1], v[i]);
				T tmp = v[i-1];
				v[i-1] = v[i];
				v[i] = tmp;
				swapped = true;
			}
		}
		n = n - 1;
	}
}


template<Sortable T>
void heap(std::vector<T>& v, unsigned int n, unsigned int i)
{
	unsigned int radice = i; // posizione della radice
	unsigned int sx = 2*i + 1; // posizione del figlio sinistro
	unsigned int dx = 2*i + 2; // posizione del figlio destro
	
	// scambio in base alla priorità
	if(sx < n && v[sx] > v[radice])
		radice = sx;
	
	if(dx < n && v[dx] > v[radice])
		radice = dx;
	
	if(radice != i)
	{
		//swap(v[i], v[radice]);
		T tmp = v[i];
		v[i] = v[radice];
		v[radice] = tmp;
		heap(v, n, radice);
	}
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	
	// costruisco l'heaptree
	for(int i = (n/2 - 1); i >= 0; i--)
		heap(v, n, i);
	
	// estraggo ogni elemento dell'heaptree
	for(int i = n-1; i > 0; i--)
	{
		//swap(v[0], v[i]);
		T tmp = v[0];
		v[0] = v[i];
		v[i] = tmp;
		heap(v, i, 0);
	}
}

}
