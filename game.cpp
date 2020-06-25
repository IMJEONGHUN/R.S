#include "poker_header.h"

int survivor = 5;
card Deck[52];


//void endGame()
//{
//	checkCard(); //�ӽ� ���� �� �Լ�
//
//
//}
//
//void resetGame()
//{
//
//}

//void checkOutCom(player member[])
//{
//	for (int i = 0; i < survivor; i++)
//	{
//		if (member[i].getMoney == 0)
//		{
//
//		}
//	}
//}

void choiceBet(player member[], int& gambler, int leader, int& totalBet)
{
	int nowBet = leader - 1, betMoney = 0;


	for (int i = 0; i < gambler; i++) // ���� ���ľ���
	{
		nowBet = (nowBet + 1)%survivor;

		while (member[nowBet].nowPlay() == false) //���� �÷��̾ �̹��� ���̸� ���� ���.
		{
			nowBet = (nowBet + 1)%survivor;
		}
		cout << "���� ���� : " << nowBet << endl;
		if (i == 0) //ù �� leader�� ���� �ٸ�.
		{
			betMoney = member[nowBet].leaderBet(totalBet, gambler);
			while (betMoney == 0) //���� ������ ������ ���
			{
				if (gambler == 1) // �� ���� gambler�� ���� ���
					break;
				nowBet = (nowBet + 1)%survivor;
				while (member[nowBet].nowPlay() == false) //���� �÷��̾ �̹��� ���̸� ���� ���.
				{
					nowBet = (nowBet + 1) % survivor;
				}
				cout << "���� ���� : " << nowBet << endl;
				betMoney = member[nowBet].leaderBet(totalBet, gambler);
			}
			
		}
		else
		{
			if (member[nowBet].canBet(betMoney) == true) // �� �� �ɷ��� �ִ°� �Ǵ�
				choiceFollower(member[nowBet], betMoney, totalBet, gambler, i);
			else
				cant_Bet(member[nowBet], betMoney, gambler, totalBet);
		}
		cout << "��ü ���� �ݾ�: " << totalBet << endl << "���� ���� : " << betMoney << endl;
	}

	for (int j = 0; j < survivor; j++)
	{
		if (member[j].nowPlay() == true)
		{
			member[j].payBet(betMoney);
		}
	}

	betMoney = 0;
}

void choiceFollower(player & follower, int& betMoney, int& totalBet, int& gambler, int& bet)
{
	cout << "�ȷο� ���� : (1: ��, 2: ����, 3: ����, 4: ����) \n";
	int choice;
	cin >> choice; // �������̽������� ����

	switch (choice)
	{
	case 1: //��
		if (betMoney > follower.getMoney())
		{
			cout << "�ݾ��� ������� �ʽ��ϴ�.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else
			cout << "---------------------��---------------------\n";
		follower.payMoney(betMoney, totalBet);
		break;
	case 2: //����
		follower.playerDie(gambler);
		break;
	case 3: // ����, ���� �ݾ� ���� ��� ����
		
		if (betMoney * 2 <= follower.getMoney())
		{
			bet = 0; // ���� ���� ������� �ٽ� �ȷο�ó�� ���� ����
			cout << "---------------------����---------------------\n";
			follower.doubleBet(betMoney, totalBet);
		}
		else
		{
			cout << "�ݾ��� ������� �ʽ��ϴ�.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		break;
	case 4: // ����
		if (betMoney > totalBet / 2)
		{
			cout << "������ ���� �ݾ׺��� �����ϴ�.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else if (follower.getMoney() < totalBet / 2)
		{
			cout << "���� ���� ���� �ǵ��� ������ ���� �ʽ��ϴ�.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else
		{
			cout << "---------------------����---------------------\n";
			follower.halfBet(betMoney, totalBet);
			bet = 0;
		}
		break;
	case 5: //All in
		bet = 0; // ���� ���� ������� �ٽ� �ȷο�ó�� ���� ����
		cout << "---------------------�� ��---------------------\n";
		follower.allMoney(betMoney, totalBet);
	}
	
}

void cant_Bet(player & follwer, int& betMoney, int& gambler, int& totalBet)
{
	cout << "���� �Ұ��� ���� : (1. ����, 2. ����)\n";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: // ���� 
		cout << "---------------------�� ��---------------------\n";
		follwer.dieAllMoney(totalBet);
		break;
	case 2: // ����
		cout << "---------------------����---------------------\n";
		follwer.playerDie(gambler);
	}
}


card drawCard()
{
	int top = 52; // �ӽ� ����. �������� �� ��, �ּҸ� �ѱ��� ���.
	return Deck[top--];
}

void obliBet(player member[], int& totalBet) // �ǹ� ����
{
	int obli = 3;

	for (int i = 0; i < survivor; i++)
	{
		member[i].payMoney(obli, totalBet);
		member[i].showMoney();

	}
	cout << "��ü ���� �ݾ� : " << totalBet << endl;
}



int choiceLeader(player member[], const int gambler) // �պ�����
{
	int temp = member[0].getMoney(), leader = 0;

	for (int i = 1; i < gambler; i++)
	{
		if (member[i].getMoney() > temp)
		{
			temp = member[i].getMoney();
			leader = i;
		}
	}
	if (leader == survivor)
		leader = 0;

	return leader;
}


void playGame(player member[], player & dealer) // ���� ����
{
	int totalBet = 0, leader;
	int gambler = survivor;
	obliBet(member, totalBet);

	for (int i = 0; i < gambler; i++) // 2�徿 ����
	{
		cout << i << "�÷��̾� ī�� �й�\n";
		member[i].takeCard();
		member[i].takeCard();
	}

	cout << "���� ī�� �й�\n";

	for (int i = 0; i < 3; i++)
		dealer.takeCard();


	leader = choiceLeader(member, gambler); // ������ �� ���� ���ϸ� �������ʹ� ������ ����� ����

	for (int i = 0; i < 3; i++)
	{
		cout << i << "�� ����\n";
		choiceBet(member, gambler, leader, totalBet);
		if (gambler == 1)
			break;
		if (i != 2) {
			dealer.takeCard();
			do
			{
				leader = (leader + 1)%survivor;
				
			} while (member[leader].checkPlayer() == false);
		}
	}

}


//���� ��Ȳ - �ǹ� ���� ����, ī�� 2�� �ֱ� ����, ���� ī�� 3�� ����, ���� ���� ����, ���� ���� ����, �ȷο� ���� ����(���ܻ��� ������)
