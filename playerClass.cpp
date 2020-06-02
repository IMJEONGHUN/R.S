#include "poker_header.h"


void player::showMoney() // ���� �÷��̾� �� Ȯ��
{
	cout << gameMoney << endl;
}

void player::payMoney(int pay, int& totalBet) //ù �ǹ��� ����
{
	if (pay >= gameMoney)
	{
		gameMoney = 0;
		totalBet = totalBet + gameMoney;
		// �������� ��ŵ�ϴ� �Լ�.
	}

	else
	{
		gameMoney = gameMoney - pay;
		totalBet = totalBet + pay;
	}
}

void player::playerDie() // �÷��̾� ��ǻ�� ����;
{
	play = false;
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

int player::getMyNumber()
{
	return myNumber;
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
	} while (betMoney>gameMoney || betMoney < 0);

	totalBet = totalBet + betMoney;
	gameMoney = gameMoney - betMoney;

	return betMoney;
}
