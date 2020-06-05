#include "poker_header.h"


card drawCard()
{
	card temp;
	temp = drawCard();

	return drawCard();
}


void choiceBet(player member[], int& gambler, int leader, int &totalBet)
{
	int nowBet = leader-1, betMoney=0;

	int cantChoice;

	for (int i = 0; i < gambler; i++)
	{	
		nowBet = gambler % (nowBet + 1);
		
		while (member[nowBet].nowPlay() == false) //���� �÷��̾ �̹��� ���̸� ���� ���.
		{
			nowBet = gambler % (nowBet + 1);
		}

		if (i == 0) //ù �� leader�� ���� �ٸ�.
		{
			betMoney = member[nowBet].leaderBet(totalBet,gambler);
			while (betMoney == 0) //���� ������ ������ ���
			{
				if (gambler==1) // �� ���� gambler�� ���� ���
				{
					break;
				}
				nowBet = gambler % (nowBet + 1);
				betMoney = member[nowBet].leaderBet(totalBet,gambler);
			}
		}
		else
		{
			if (member[nowBet].canBet == true) // �� �� �ɷ��� �ִ°� �Ǵ�
				choiceFollower(member[nowBet], betMoney, totalBet, gambler, i);
			else
				cant_Bet(member[nowBet], betMoney, gambler,totalBet);
		}
	}
}

void choiceFollower(player& follower,int& betMoney,int& totalBet,int& gambler, int &bet)
{
	int choice;
	cin >> choice; // �������̽������� ����

	switch (choice)
	{
	case 1: //��
		follower.payMoney(betMoney,totalBet);
		break;
	case 2: //����
		follower.playerDie(gambler);
		break;
	case 3: // ����, ���� �ݾ� ���� ��� ����
		bet = 0; // ���� ���� ������� �ٽ� �ȷο�ó�� ���� ����
		follower.doubleBet(betMoney,totalBet);
		break;
	case 4: // ����
		if (betMoney > totalBet / 2)
		{
			cout << "������ ���� �ݾ׺��� �����ϴ�.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else if (follower.getMoney < totalBet/2)
		{
			cout << "���� ���� ���� �ǵ��� ������ ���� �ʽ��ϴ�.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else
		{
			follower.halfBet(betMoney, totalBet);
			bet = 0;
		}
		break;
	case 5: //All in
		bet = 0; // ���� ���� ������� �ٽ� �ȷο�ó�� ���� ����
		follower.allMoney(betMoney,totalBet);
	}
}

void cant_Bet(player& follwer, int& betMoney,int &gambler,int & totalBet)
{
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: // ���� 
		follwer.dieAllMoney(totalBet);
		break;
	case 2: // ����
		follwer.playerDie(gambler);
	}
}


card drawCard()
{
	int top = 52; // �ӽ� ����. �������� �� ��, �ּҸ� �ѱ��� ���.
	return Deck[top--];
}

void obliBet(player member[],int &totalBet) // �ǹ� ����
{
	int obli = 3;

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

	for(int i =0; i<3; i++)
		dealer.takeCard;
	
	leader = choiceLeader(member, gambler); // ������ �� ���� ���ϸ� �������ʹ� ������ ����� ����

	for (int i = 0; i < 2; i++)
	{
		
	}


}

//���� ��Ȳ - �ǹ� ���� ����, ī�� 2�� �ֱ� ����, ���� ī�� 3�� ����, ���� ���� ����, ���� ���� ����, �ȷο� ���� ����(���ܻ��� ������)

