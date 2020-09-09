#include<iostream>
#include<climits>
using namespace std;

void findLargest(int **arr, int row, int col){
    int x1=INT_MIN, y1;
    int x2=INT_MIN, y2;
    for(int i=0; i<row; i++){
        int sum=0;
        for(int j=0; j<col; j++){
            sum=sum+arr[i][j];
        }
        if(sum>x1){
            x1=sum;
            y1=i;
        }
    }
    for(int j=0; j<col; j++){
        int sum=0;
        for(int i=0; i<row; i++){
            sum=sum+arr[i][j];
        }
        if(sum>x2){
            x2=sum;
            y2=j;
        }
    }
    if(x1>=x2){
        cout<<"row"<<" "<<y1<<" "<<x1;
    }
    else{
        cout<<"column"<<" "<<y2<<" "<<x2;
    }

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}

