#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (current < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = current;
    }
}
int main()
{
    int input[] = {2, 5, 1, 9, 3, 8};
    InsertionSort(input, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}