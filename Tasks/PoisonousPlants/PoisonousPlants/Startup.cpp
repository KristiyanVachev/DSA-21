#include <iostream>
#include <queue>
#include <vector>
#include <ctime>

#include "../PoisonousPlants/PoisonousPlants.cpp"

using namespace std;

vector<int> GenerateSamplePlants() 
{
    vector<int> plants;

    plants.push_back(1);
    plants.push_back(2);
    plants.push_back(3);
    plants.push_back(4);
    plants.push_back(5);

    return plants;
}

vector<int> GeneratePlants(int sequenceLenght)
{
	vector<int> plants;
	int upperBound = 10;
	int lowerBound = 1;

	for (size_t i = 0; i < sequenceLenght; i++)
	{
		int n = ((rand() % (upperBound + 1 - lowerBound)) + lowerBound);
		plants.push_back(n);
	}

	return plants;
}

int main()
{
	cout << "generate sequence..." << endl;
	vector<int> plants = GeneratePlants(2000000);

	cout << "start algo..." << endl;
	time_t startTime = time(NULL);
	//15 sec, day 21
	//int noFuneralDay = poisonousPlantsQueue(plants);

	//4 sec, day 21
	int noFuneralDay = poisonousPlantsOwnQueue(plants);
	time_t endTime = time(NULL);

	cout << endTime - startTime << " seconds" << endl;
	cout << noFuneralDay << endl;
}

