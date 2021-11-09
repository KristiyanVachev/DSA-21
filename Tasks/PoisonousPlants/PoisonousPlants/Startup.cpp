#include <iostream>
#include <queue>
#include <vector>

#include "../PoisonousPlants/PoisonousPlants.cpp"

using namespace std;

int main()
{
    vector<int> plants;

    plants.push_back(1);
    plants.push_back(2);
    plants.push_back(3);
    plants.push_back(4);
    plants.push_back(5);

    int noFuneralDay = poisonousPlants(plants);

    cout << noFuneralDay << endl;
}
