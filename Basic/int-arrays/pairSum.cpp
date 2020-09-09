/*
#include<iostream>
using namespace std;

void pairSum(int input[], int size, int x){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(input[i]+input[j]==x){
                if(input[i]<input[j]){
                    cout<<input[i]<<" "<<input[j]<<endl;
                }
                else{
                    cout<<input[j]<<" "<<input[i]<<endl;
                }
            }
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
		int x;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;
		cout<<pairSum(input, size, x) << endl;
		delete[] input;
	}
	return 0;
}
*/