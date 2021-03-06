#include<iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int mCols){
    if(nRows==0 || mCols==0){
        return;
    }
    int i, rowStart=0, colStart=0;
    int numElements=nRows*mCols, cnt=0;
    while(cnt<numElements){
        for(i=colStart; cnt<numElements && i<mCols; ++i){
            cout<<input[rowStart][i]<<" ";
            cnt++;
        }
        rowStart++;
        for(i=rowStart; cnt<numElements && i<nRows; ++i){
            cout<<input[i][mCols-1]<<" ";
            cnt++;
        }
        mCols--;
        for(i=mCols-1; cnt<numElements && i>=colStart; --i){
            cout<<input[nRows-1][i]<<" ";
            cnt++;
        }
        nRows--;
        for(i=nRows-1; cnt<numElements && i>=rowStart; --i){
            cout<<input[i][colStart]<<" ";
            cnt++;
        }
        colStart;
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
        int **matrix = new int *[row];
        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);
        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        cout << endl;
    }
}