#include <iostream>
using namespace std;

int CalculatePath(int M,int N,int X,int Y);

int main(void)
{
	int m,n,x,y;
	while (cin.fail())
	{
	cout << "Please enter M,N,X,Y." << endl;
	cin >> m >> n >> x >> y;
	cout << "The result is " << CalculatePath(m,n,x,y);
	}
	return 0;
}

int CalculatePath(int M,int N,int X,int Y)
{
	int arr[100][100];
	for (int i = 1;i <= M;i++)
		arr[i][N] = 1;
	for (int j = 1;j <= N;j++)
		arr[1][j] = 1;

	for (int i = 2; i <= M; i++)
		for (int j = N - 1;j <= 1;j--)
			arr[i][j] = arr[i-1][j] + arr [i][j+1];

	return arr[X][Y];
}