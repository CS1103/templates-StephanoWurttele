#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
// Función para dividir el array y hacer los intercambios
template <typename T>
int divide(T *array, int start, int end) {
    int left;
    int right;
    T pivot;
    T temp;

    pivot = array[start];
    left = start;
    right = end;
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    // La nueva posición del pivot
    return right;
}
template <typename T>
int divide(vector<T> &arr, int start, int end) {
    int left;
    int right;
    T pivot;
    T temp;

    pivot = arr[start];
    left = start;
    right = end;
    // Mientras no se cruzen los índices
    while (left < right) {
        while (arr[right] > pivot) {
            right--;
        }
        while ((left < right) && (arr[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }

    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = arr[right];
    arr[right] = arr[start];
    arr[start] = temp;

    // La nueva posición del pivot
    return right;
}



// Función recursiva para hacer el ordenamiento
template<typename T>
void quicksort(T *array, int start, int end)
{
    T pivot;
    if (start < end) {
        pivot = divide(array, start, end);

        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

template<typename T>
void quicksort(vector<T> &array, int start, int end)
{
    T pivot;
    if (start < end) {
        pivot = divide(array, start, end);

        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}


int main() {
    int arraySize;
    int const MAX=100;

    cout << "Ingresa tamanyo: " << endl;
    cin >> arraySize;
    int* a=new int[arraySize];
    vector<int> b;

    // Para que el rand no genere siempre los mismos números, utilizando la hora del sistema
    srand(time(0));

    // Para generar enteros aleatorios usamos rand()
    for (int i = 0; i < arraySize; i++) {
        a[i] = rand() % MAX;
        b.push_back(rand()% MAX);
    }

    cout << "Array antes de ordenarse: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout<<a[i];
        cout<<" ";
    }
    cout<<endl<<endl;

    cout << "Vector antes de ordenarse: " << endl;
    for (int i = 0; i < b.size(); i++) {
        cout<<b[i];
        cout<<" ";
    }


    cout << endl << endl;

    quicksort(a, 0, arraySize - 1);
    quicksort(b, 0, b.size()-1);


    cout << "Array ordenado " << endl;
    for (int i = 0; i < arraySize; i++ ){
        cout << a[i] << " ";
    }
    cout<<endl;
    cout << "Vector ordenado " << endl;
    for (int i = 0; i < arraySize; i++ ){
        cout << b[i] << " ";
    }
    cout << endl << endl;

    return 0;
}
