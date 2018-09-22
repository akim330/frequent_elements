#include <map>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 42

int main()
{
	float theta = 0.15;

	map<int,int> mappa;
	map<int,int>::iterator it1, it2;
	
	// Just a sample array
	int array[N] = {1, 2, 3, 2, 6, 7, 8, 2, 2, 1, 3, 3, 1, 1, 3,
					5, 7, 3, 5, 1, 0, 45, 1, 54, 3, 2, 2, 8, 1,
					0, 4, 34, 45, 2, 10, 5, 4, 7, 8, 9, 12, 56};

	//printf("theta: %f\n", theta);
	
	for (int i=0; i<N; i++)
	{
		it1 = mappa.find(array[i]);
		if (it1 == mappa.end())
		{
			mappa[array[i]] = 1;
			
			if (mappa.size() > 1/theta)
			{
			
				for (it2 = mappa.begin(); it2 != mappa.end(); ++it2)
					it2->second -= 1;

				for (it2 = mappa.begin(); it2 != mappa.end(); ++it2)
					if (it2->second == 0)
						mappa.erase(it2);
			}
		}
		else
		{
			// Increment the counter
			it1->second += 1;
		}
	}

	for (it2 = mappa.begin(); it2 != mappa.end(); ++it2)
	{
		it2->second = 0;
	}

	for (int i=0; i<N; i++)
	{
		it1 = mappa.find(array[i]);
		if (it1 != mappa.end())
			it1->second += 1;
	}


	sort(array, array+N);

	for (int i=0; i<N; i++)
	{
		printf("%i ", array[i]);
	}

	printf("\n");


	for (auto element : mappa)
	{
		if (element.second >= round(theta*N))
			printf("element %i: counter = %i\n", element.first, element.second);
		
	}


}
