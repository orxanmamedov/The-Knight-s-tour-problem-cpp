
#include <iostream> 
#include <iomanip>
#define N 8 
using namespace std;

static int cx[N] = { 1,1,2,2,-1,-1,-2,-2 };
static int cy[N] = { 2,-2,1,-1,2,-2,1,-1 };

bool limits(int x, int y)
{
	return ((x >= 0 && y >= 0) && (x < N && y < N));
}

bool isempty(int a[], int x, int y)
{
	return (limits(x, y)) && (a[y * N + x] < 0);
}


int getDegree(int a[], int x, int y)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
		if (isempty(a, (x + cx[i]), (y + cy[i])))
			count++;

	return count;
}


bool nextMove(int a[], int* x, int* y)
{
	int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

	for (int count = 1; count <= N; ++count)
	{
		int i = count % N;
		nx = *x + cx[i];
		ny = *y + cy[i];
		if ((isempty(a, nx, ny)) &&
			(c = getDegree(a, nx, ny)) < min_deg)
		{
			min_deg_idx = i;
			min_deg = c;
		}
	}

	if (min_deg_idx == -1)
		return false;

	nx = *x + cx[min_deg_idx];
	ny = *y + cy[min_deg_idx];

	a[ny * N + nx] = a[(*y) * N + (*x)] + 1;

	*x = nx;
	*y = ny;

	return true;
}
void print(int a[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) {
			cout << setw(4) << a[j * N + i] << " ";
		}
		cout << endl;
		cout << endl;
	}
}





bool findClosedTour(int x = 1, int y = 1)
{
	x--;
	y--;
	int a[N * N];
	for (int i = 0; i < N * N; ++i)
		a[i] = -1;


	a[y * N + x] = 1;
	for (int i = 0; i < N * N - 1; ++i)
		if (nextMove(a, &x, &y) == 0)
			return false;


	print(a);
	return true;
}


int main()
{


	if (!findClosedTour(2, 4)) cout << "No way";





	return 0;
}
