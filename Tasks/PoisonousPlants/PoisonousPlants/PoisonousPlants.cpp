#include <iostream>
#include <vector>

#include "Queue.h"

using namespace std;

inline int poisonousPlants(vector<int> p)
{
    Queue<int> pesticideLevelsOfAlivePlants;

    for (size_t i = 0; i < p.size(); i++)
    {
        pesticideLevelsOfAlivePlants.Enqueue(p[i]);
    }

    bool hasCasualtiesThisRound = true;
    int currentDay = -1;

    while (hasCasualtiesThisRound && pesticideLevelsOfAlivePlants.Size() >= 1)
    {
        currentDay++;
        hasCasualtiesThisRound = false;
        int alivePlantsTodayCount = pesticideLevelsOfAlivePlants.Size();

        int leftPesticideLevel = pesticideLevelsOfAlivePlants.Dequeue();

        pesticideLevelsOfAlivePlants.Enqueue(leftPesticideLevel);

        for (size_t i = 1; i < alivePlantsTodayCount; i++)
        {
            int currentPesticideLevel = pesticideLevelsOfAlivePlants.Dequeue();

            if (leftPesticideLevel < currentPesticideLevel)
            {
                hasCasualtiesThisRound = true;
            }
            else
            {
                pesticideLevelsOfAlivePlants.Enqueue(currentPesticideLevel);
            }

            leftPesticideLevel = currentPesticideLevel;
        }
    }

    return currentDay;
}