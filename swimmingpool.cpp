#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// constraints
#define MAXN 100000


// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// between these two.
int getClosest(int val1, int val2,
			int target)
{
	if (target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}

int findClosest(int arr[], int n, int target)
{
	// Caso base
	if (target <= arr[0])
		return arr[0];
	if (target >= arr[n - 1])
		return arr[n - 1];

//binary search
	int i = 0, j = n, mid = 0;
	while (i < j) {
		mid = (i + j) / 2;

		if (arr[mid] == target)
			return arr[mid];

		if (target < arr[mid]) {


			if (mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1],
								arr[mid], target);

			j = mid;
		}

		else {
			if (mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid],
								arr[mid + 1], target);

			i = mid + 1;
		}
	}

	return arr[mid];
}


// input data
int N;
int P[MAXN];

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    in>>N;
    int sum=0;

    for(int i=0; i<N; i++) {
      in >> P[i];
      sum+=P[i];
    }

		vector<pair<int,int> > v;
		v.resize(N);

		for (int j=0; j<N; j++) {
			v[j].first=P[j]-P[0];
			v[j].second=P[N-1]-P[j];
		}

		int temp=P[N-1];
		int index=-1;

		for (int k=0; k<N; k++) {
			if (abs(v[k].second-v[k].first)<temp) {
				 temp=abs(v[k].second-v[k].first);
				 index=k;
			}
		}

		//cout<<"nuotatore P"<<index<<" ("<<P[index]<<") distante da P0 "<<v[index].first<<" e distante da P"<<N<<" "<<v[index].second<<endl;

    int temp2=sum/N;

    cout << P[N-1]-findClosest(P, N, temp2) <<endl;
		cout<<max(v[index].first,v[index].second)<<endl;
    return 0;
}
