#include<iostream>
using namespace std;
int N;
int orders[1024];
int stations[1024];
int indexStations = 0;
int indexOrders = 0;

void simulate()
{
	indexStations = -1;
	indexOrders = 0;
	for(int i = 1; i< N+1; i++)
	{
		stations[++indexStations] = i;
		while(indexStations != -1 && indexOrders< N && stations[indexStations] == orders[indexOrders])
		{
			indexStations--;
			indexOrders++;
		}			
	}
	if(indexStations == -1)
	{
		cout <<"Yes"<<endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
}

int main()
{
	while(true)
	{
		cin >> N;
		if(N == 0)
		{
			break;
		}
		while(true)
		{
			cin >> orders[0];
			if(orders[0] != 0)
			{
				for(int i = 1; i < N; i++)
				{
					cin >> orders[i];
				}
				simulate();
			}
			else
			{
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
