/*
#include<iostream>
#include<algorithm>
using namespace std;

void SortZeroesAndOne(int arr[], int n){
    int j=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            int temp =arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            j++;
        }
    }

}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}
		sortZeroesAndOne(input, size);
		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		cout << endl;
		delete[] input;
	}
	return 0;
}
*/