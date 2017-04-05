#include "stdafx.h"
#include "Encounter.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include "windows.media.h"
#pragma comment (lib, "winmm.lib")
using namespace std;


void Enounter::setPlayerDetails(string pName, int pHP, int potCount)
{
	playerName = pName;
	playerHP = pHP;
	potionCount = potCount;
}

void Enounter::setEnemyDetails(string eName, int eHP, int eAtt)
{
	enemyName = eName;
	enemyHP = eHP;
	enemyAttack = eAtt;
}

void Enounter::battle()
{
	int playerInput;
	int damage;
	int hit;
	int tempHP;
	//music will start here
	PlaySoundA(LPCSTR("yourLoveIsADrug.wav"), NULL, SND_LOOP | SND_ASYNC);
	cout << "A battle has broken out!\n";

	do
	{
		cout << "What will " + playerName + " do?\n\n";
		cout << "1 = Attack, 2 = Use Potion\n";
		cin >> playerInput;
		
		if (playerInput == 1)
		{
			//place holder numbers
			//player attack phase
			cout << playerName + " readies his weapon!\n";
			hit = rand() % 4 + 1;
			if (hit > 1)
			{
				
				damage = rand() % 10 + 1;
				cout << playerName + " deals " + to_string(damage) + " damage to " + enemyName + "\n";
				enemyHP = enemyHP - damage;
			}
			else
			{
				cout << playerName + " misses\n";
			}
		}

		//enemy attack phase might add a do nothing option and random number check
		else if (playerHP != 0)
		{
			hit = rand() % 4 + 1;
			if (hit > 1 && enemyHP > 0)
			{
				cout << enemyName + " starts to attack!\n";
				damage = rand() % enemyAttack + 1;
				cout << enemyName + " deals " + to_string(damage) + " damage to " + playerName + "\n";
				playerHP = playerHP - damage;
			}
			else if (hit == 1)
			{
				cout << enemyName + " misses!\n";

			}
			else
			{
				cout << enemyName + " has been slain!!\n\n";
				PlaySound(NULL, 0, 0); //when you want it to stop
			}
		}
		else
		{
			
		}
	} while (enemyHP > 0 && playerHP > 0);

}
