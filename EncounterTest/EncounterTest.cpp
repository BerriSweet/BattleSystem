// EncounterTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include "Encounter.h"
using namespace std;

string halt;
int main()
{

	Enounter encount1;
	//set the enemy details
	encount1.setEnemyDetails("Crab", 10, 4);
	//set the player details
	encount1.setPlayerDetails("Danny", 50, 3);
	encount1.battle();
	cin >> halt;
    return 0;
}

