#include <iostream>
#include <vector>

#include <queue>
#include "Queue.h"

using namespace std;

inline int poisonousPlantsQueue(vector<int> p)
{
    queue<int> pesticideLevelsOfAlivePlants;

    for (size_t i = 0; i < p.size(); i++)
    {
        pesticideLevelsOfAlivePlants.push(p[i]);
    }

    bool hasCasualtiesThisRound = true;
    int currentDay = 0;

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

    return currentDay - 1;
}


inline int poisonousPlantsOwnQueue(vector<int> p)
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

inline int poisonousPlants(vector<int> p)
{
    return poisonousPlantsQueue(p);
    //return poisonousPlantsOwnQueue(p);
}