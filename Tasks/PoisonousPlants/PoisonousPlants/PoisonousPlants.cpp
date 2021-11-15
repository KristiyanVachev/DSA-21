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

inline int poisonousPlantsNLogN(vector<int> pesticideLevels)
{
    //v1

    //kepp track of all alive

    //list of dead from the last day
    //list of dead from today

    //fill list of dead on the first day

    //while the newly dead is not empty
        //for lenght of newly dead
            //check element on the right of newly dead with the last alive on the left
                //if not_dying -> do nothing
                //if will die -> add to the dead on next day
        //update newly dead and start new day of murder


    //v2
    //kepp track of all alive

    //list of indexes of the dead from the last day
    //list of indexes of the of dead from today

    //fill list of dead on the first day

    //while the newly dead is not empty
        //for lenght of newly dead
            //get next [newly dead]
            //get [element right of [newly dead]]
            //get [element last alive element left of right of newly dead]
            //compare [element right of newly dead] with [element last alive element left of right of newly dead]
                //if [right of newly dead] will die -> add to the dead_today list
                //if not dying -> do nothing
                
        //kill all from dead_today
        //replace newly_dead with dead_today 
        //clear dead_today
        //and start new day of murder


    //v3 - WHICH DATA STRUCTURES TO USE

    //kepp track of all alive -> vector
    //list of indexes of the dead from the last day -> queue
    queue<int> yesterdayDead;
    //list of indexes of the of dead from today -> queue
    queue<int> todayDead;

    //fill list of dead on the first day
    int day = 1;
    for (size_t i = 1; i < p.size(); i++)
    {
        if (pesticideLevels[i-1] < pesticideLevels[i])
        {
            yesterdayDead.push(i);
        }
    }

    //while the newly dead is not empty
    while (!yesterdayDead.empty())
    {
        day++;
        int yesterdayDeathsCount = yesterdayDead.size();

        for (size_t i = 0; i < yesterdayDeathsCount; i++)
        {
            //get next [newly dead]
            int newlyDeadIndex = yesterdayDead.front();
            yesterdayDead.pop();
            //get [element right of [newly dead]]
            //TODO: Check if out of array
            int rightOfNewlyDeadIndex = pesticideLevels[newlyDeadIndex + 1];

            //get [element last alive element left of right of newly dead]
            int leftOfNewlyDeadIndex = -1;
            for (size_t i = newlyDeadIndex - 1; i >= 0; i--)
            {
                if (pesticideLevels[i] != -1) //Hack to keep using a queue
                {
                    leftOfNewlyDeadIndex = i;
                    break;
                }
            }

            //compare [element right of newly dead] with [element last alive element left of right of newly dead]
            if (leftOfNewlyDeadIndex > 0 && pesticideLevels[leftOfNewlyDeadIndex] < pesticideLevels[rightOfNewlyDeadIndex])
            {
                //if [right of newly dead] will die -> add to the dead_today list
                //if not dying -> do nothing
                todayDead.push(rightOfNewlyDeadIndex);
                pesticideLevels[newlyDeadIndex] = -1;
            }
        }

        //TODO make sure yesterday_dead are all gone

        //kill all from yesterday_dead from list_of_alive
        //add new indexes to newly_dead
        //clear dead_today for the next day of murder 
        int shiftLeftBecauseOfDeadCount = 0;

        int i = 0;
        while (true)
        {
            int nextTodayDeathIndex = todayDead.front();

            if (pesticideLevels[i] == -1)
            {
                shiftLeftBecauseOfDeadCount++;
                pesticideLevels.erase(i); //WTF?
            }

            if (nextTodayDeathIndex - shiftLeftBecauseOfDeadCount == i)
            {
                yesterdayDead.push(nextTodayDeathIndex - shiftLeftBecauseOfDeadCount);
                todayDead.pop();
            }
        }

        //for (size_t i = 0; i < pesticideLevels.size(); i++) //TODO chance to while
        //{
        //    int nextTodayDeathIndex = todayDead.front();

        //    if (pesticideLevels[i] == -1)
        //    {
        //        shiftLeftBecauseOfDeadCount++;
        //        pesticideLevels.erase(i); //WTF?
        //    }

        //    if (nextTodayDeathIndex - shiftLeftBecauseOfDeadCount == i)
        //    {
        //        yesterdayDead.push(nextTodayDeathIndex - shiftLeftBecauseOfDeadCount);
        //        todayDead.pop();
        //    }
        //}

        //TODO make sure todayDead is empty.
    }

    return day - 1;
}

inline int poisonousPlants(vector<int> p)
{
    return poisonousPlantsQueue(p);
    //return poisonousPlantsOwnQueue(p);
}