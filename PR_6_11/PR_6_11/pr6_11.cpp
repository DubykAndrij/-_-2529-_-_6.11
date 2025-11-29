#include <iostream>
#include <iomanip> // Äëÿ setw
#include <cstdlib> // Äëÿ rand, srand
#include <ctime>   // Äëÿ time

using namespace std;

const int SIZE = 20;
const int MIN_VAL = -20;
const int MAX_VAL = 50;

void fillArray(int arr[], int size);
void printArray(const int arr[], int size);
int countSatisfyingElement(const int arr[], int size);
int sumSatisfyingElements(const int arr[], int size);
void replaceSatisfyingElements(int arr[], int size);

int main() {
    srand(static_cast<unsigned>(time(0)));

    int a[SIZE];

    fillArray(a, SIZE);

    cout << "Original array:" << endl;
    printArray(a, SIZE);
    cout << "--------------------------------" << endl;

    int count = countSatisfyingElement(a, SIZE);
    int sum = sumSatisfyingElements(a, SIZE);

    cout << "Count of satisfying elements: " << count << endl;
    cout << "Sum of satisfying elements:   " << sum << endl;
    cout << "--------------------------------" << endl;

    replaceSatisfyingElements(a, SIZE);

    cout << "Modified array:" << endl;
    printArray(a, SIZE);

    return 0;
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

int countSatisfyingElement(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && i % 5 != 0) {
            count++;
        }
    }
    return count;
}

int sumSatisfyingElements(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && i % 5 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void replaceSatisfyingElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && i % 5 != 0) {
            arr[i] = 0;
        }
    }
}