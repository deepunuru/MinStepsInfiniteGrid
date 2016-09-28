// MinStepsInfiniteGrid.cpp : Program to calculate minimum possible steps in a 2D infinite Grid.
//

#include "stdafx.h"
#include <vector>
using namespace std;

int coverPoints(vector<int> &X, vector<int> &Y) {
	int xStep, yStep, totStep = 0;

	if (X.size() == 1)
		return 0;
	else
	{
		for (int i = 0; i<X.size() - 1; i++)
		{
			if ((X[i + 1]>0 && X[i]<0) || (X[i + 1]<0 || X[i]>0))
				xStep = abs(X[i + 1]) + abs(X[i]);
			else if ((X[i + 1]>0 && X[i]>0) || (X[i + 1]<0 || X[i]<0))
				xStep = abs(X[i + 1]) - abs(X[i]);

			if ((Y[i + 1]>0 && Y[0]<0) || (Y[i + 1]<0 || Y[0]>0))
				yStep = abs(Y[i + 1]) + abs(Y[i]);
			else if ((Y[i + 1]>0 && Y[i]>0) || (Y[i + 1]<0 || Y[i]<0))
				yStep = abs(Y[i + 1]) - abs(Y[i]);
			if (xStep>yStep)
				totStep = totStep + xStep;
			else
				totStep = totStep + yStep;
			return totStep;
		}
	}
}

void main()
{
	printf("\nProgram to calculate minimum possible steps in a 2D infinite Grid\n");
	vector<int> X, Y;
	X = {-7,13};
	printf("Vector X is {-7,13}\n");
	printf("%d\t%d\n", X[0], X[1]);
	Y = {1,-5};
	printf("Vector Y is {1,-5}\n");
	printf("%d\t%d\n", Y[0], Y[1]);
	int steps = coverPoints(X,Y);
	printf("Minimum possible steps it takes to traverse these points is : %d\n",steps);
	getchar();
}

