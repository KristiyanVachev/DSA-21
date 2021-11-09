#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline int poisonousPlants(vector<int> p)
{
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