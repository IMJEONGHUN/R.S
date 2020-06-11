#include "poker_header.h"


void player::showMoney() // ���� �÷��̾� �� Ȯ��
{
	cout << gameMoney << endl;
}

void player::payMoney(int pay, int& totalBet) //ù �ǹ��� ����, ��
{
	if (pay >= gameMoney)
	{
		gameMoney = 0;
		totalBet = totalBet + gameMoney;
		play = false;
	}

	else
	{
		gameMoney = gameMoney - pay;
		totalBet = totalBet + pay;
	}
}

void player::playerDie(int& gambler) 
{
	play = false;
	die = true;
	gambler--;
}

void player::getCard(card newCard1, card newCard2)
{
	myCard[0] = newCard1;
	myCard[1] = newCard2;
}

bool player::checkPlayer()
{
	if (play == true)
		return true;
	else
		return false;
}

void player::takeCard()
{
	myCard[used++] = drawCard();
}

int player::getMoney()
{
	return gameMoney;
}

int player::inputBet(int &totalBet) // ���� ���� ���ؾ� ��.
{
	int betMoney;
	do 
	{
		cin >> betMoney;
	} while (betMoney>gameMoney || betMoney <= 0);

	totalBet = totalBet + betMoney;
	gameMoney = gameMoney - betMoney;

	return betMoney;
}

int player::leaderBet(int &totalMoney,int& gambler)
{
	int choice, betMoney;
	cin >> choice;

	switch (choice)
	{
	case 1:
		betMoney = inputBet(totalMoney);
		return betMoney;
	case 2:
		playerDie(gambler);
		return 0;
	}
}

void player::doubleBet(int& betMoney,int& totalBet)
{
	betMoney = betMoney * 2;
	gameMoney = gameMoney - betMoney;
	totalBet = totalBet + betMoney;
}

void player::allMoney(int& betMoney, int& totalBet)
{
	betMoney = gameMoney;
	gameMoney = 0;
	totalBet = totalBet + betMoney;
	play = false;
}

bool player::canBet(int betMoney) //������ �ɷ��� �ִ��� �Ǵ�
{
	if (betMoney > gameMoney)
		return false;
	else
		return true;
}

void player::halfBet(int& betMoney, int& totalBet)
{
	betMoney = totalBet / 2;
	gameMoney = gameMoney - betMoney;
	totalBet = betMoney;
}

void player::dieAllMoney(int& totalBet)
{
	totalBet = totalBet + gameMoney;
	gameMoney = 0;
	play = false;
}

bool player::nowPlay()
{
	return play;
}

void player::checkSurvivor()
{
	if (die == true)
		true;
	else
		false;
}
