#include "poker_header.h"


//card givePlayer(player member[])
//{
//	card temp1, temp2;
//	for (int i = 0; i < survivor; i++)
//	{
//		temp1 = drawCard();
//		temp2 = drawCard();
//		member[i].getCard(temp1, temp2);
//	}
//}

void choiceBet(player member[], const int gambler, int leader, int &totalBet)
{
	int nowBet = leader, betMoney;
	for (int i = 0; i < gambler; i++, nowBet++)
	{
		if (nowBet == gambler)
			nowBet == 0;
		nowBet = gambler % nowBet;

		if (i == 0) //ù �� leader�� ���� �ٸ�.
		{
			betMoney = member[nowBet].inputBet(totalBet);
		}
		else
		{
			choiceBet(member[nowBet],betMoney,totalBet);
		}
	}
}

void choiceBet(player& follwer,int& betMoney,int& totalBet)
{
	int choice;
	cin >> choice; // �������̽������� ����

	switch (choice)
	{
	case 1: //��
		follwer.payMoney(betMoney,totalBet);
		break;
	case 2: //
		break;
	case 3:
		break;
	case 4:

	}
}


void giveCard(int survive,int leader)
{
	leader += 1;
	for (int i = 0; i < survive; i++)
	{

	}
}

card drawCard()
{
	int top = 52; // �ӽ� ����. �������� �� ��, �ּҸ� �ѱ��� ���.
	return Deck[top--];
}

void obliBet(player member[],int &totalBet) // �ǹ� ����
{
	int obli = 100000000;

	for (int i = 0; i < survivor; i++)
	{
		member[i].payMoney(obli, totalBet);
		member[i].showMoney();
		
	}
	cout << totalBet << endl;
}

void openCard(player open) // �������̽� ��� ������
{
	cout << open.myCard[0]; 
	cout << open.myCard[1];
}

int choiceLeader(player member[],const int gambler) // �պ�����
{
	int temp = member[0].getMoney(), leader=0;

	for (int i = 1; i < gambler; i++)
	{
		if (member[i].getMoney() > temp)
		{
			temp = member[i].getMoney();
			leader = i;
		}
	}

	return leader;
}



void playGame(player member[],player& dealer) // ���� ����
{
	int totalBet = 0, leader;
	int gambler=survivor;
	obliBet(member,totalBet);
	//givePlayer(member);
	for (int i = 0; i < gambler; i++) // 2�徿 ����
	{
		member[i].takeCard;
		member[i].takeCard;
	}

	openCard(member[0]); // ���� ���

	leader = choiceLeader(member,gambler);

	for (int i = 0; i < 5; i++)
	{

	}
}

//���� ��Ȳ - �ǹ� ���� ����, ī�� �ֱ� ����.