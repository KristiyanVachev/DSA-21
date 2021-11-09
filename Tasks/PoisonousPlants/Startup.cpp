#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int poisonousPlants(vector<int> p) {
    //TODO - use your own queue implementation
    queue<int> pesticideLevelsOfAlivePlants;

    for (size_t i = 0; i < p.size(); i++)
    {
        pesticideLevelsOfAlivePlants.push(p[i]);
    }

    bool hasCasualtiesThisRound = true;
    int currentDay = -1;

    while (hasCasualtiesThisRound && pesticideLevelsOfAlivePlants.size() >= 1)
    {
        currentDay++;
        hasCasualtiesThisRound = false;
        int alivePlantsTodayCount = pesticideLevelsOfAlivePlants.size();

        int leftPesticideLevel = pesticideLevelsOfAlivePlants.front();
        pesticideLevelsOfAlivePlants.pop();
        pesticideLevelsOfAlivePlants.push(leftPesticideLevel);

        for (size_t i = 1; i < alivePlantsTodayCount; i++)
        {
            int currentPesticideLevel = pesticideLevelsOfAlivePlants.front();
            pesticideLevelsOfAlivePlants.pop();

            if (leftPesticideLevel < currentPesticideLevel)
            {
                hasCasualtiesThisRound = true;
            }
            else 
            {
                pesticideLevelsOfAlivePlants.push(currentPesticideLevel);
            }

            leftPesticideLevel = currentPesticideLevel;
        }
    }

    return currentDay;
}

int main()
{
    vector<int> plants;

    //plants.push_back(3);
    //plants.push_back(6);
    //plants.push_back(2);
    //plants.push_back(7);
    //plants.push_back(5);

    //plants.push_back(4);
    //plants.push_back(3);
    //plants.push_back(7);
    //plants.push_back(5);
    //plants.push_back(6);
    //plants.push_back(4);
    //plants.push_back(2);

    //plants.push_back(3);
    //plants.push_back(2);
    //plants.push_back(5);
    //plants.push_back(4);

    //Expected -> 1
    plants.push_back(1);
    plants.push_back(2);
    plants.push_back(3);
    plants.push_back(4);
    plants.push_back(5);

    int noFuneralDay = poisonousPlants(plants);

    cout << noFuneralDay << endl;
}
