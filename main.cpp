#include<iostream>
#include<ctime>
#include<algorithm>
#include<chrono>

using namespace std;

void bubble_sort(int array[], int array_size) 
{
    for(int i = 0; i < array_size - 1; i++) 
    {
        for(int j = 0; j < array_size - i - 1; j++) 
        {
            if(array[j] > array[j + 1]) swap(array[j], array[j + 1]);
        }
    }
}

void selection_sort(int array[], int array_size)
{
    for(int i = 0; i < array_size - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < array_size; j++)
        {
            if(array[j] < array[min_index]) min_index = j;
        }
        if(i != min_index) swap(array[i], array[min_index]);
    }
}

void quick_sort(int array[], int array_size)
{
    qsort(array, array_size, sizeof(int), [](const void* a, const void* b) -> int {
        return *(int*)a - *(int*)b;
    });
}

int main()
{
    srand(time(0));
    int array_size;
    cout << "Enter array size: ";
    cin >> array_size;
    int* unsorted_array = new int[array_size];
    int* array = new int[array_size];

    for(int i = 0; i < array_size; i++) unsorted_array[i] = rand();    

    const int functions_count = 3;
    void (*functions_array[functions_count])(int[], int) = {
        bubble_sort,  
        selection_sort,  
        quick_sort   
    };
    string names_array[functions_count] = { "bubble sort", "selection sort", "quick sort" };

    for(int i = 0; i < functions_count; i++)
    {
        copy(unsorted_array, unsorted_array + array_size, array);
        auto start = chrono::high_resolution_clock::now();
        functions_array[i](array, array_size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << duration.count() << " seconds - " << names_array[i] << endl;
    }

    delete[] unsorted_array;
    delete[] array;

    return 0;
}
