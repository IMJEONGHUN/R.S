#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define CHOICE 4

enum {Half, Quater, Double, Call, All_in, Die} betting;

class card { //(�ӽ�) ī�� Ŭ����
public:
	friend ostream& operator<< (ostream& a, const card& thiscard);
private:
	bool status=false; // �޸� false �ո� true
	string pat;
	int cardNumber;
	int num;

};

class player {
public:
	void payMoney(int pay,int &totalBet); 
	void showMoney();
	void getCard(card newCard1, card newCard2);
	bool checkPlayer(); //����ִ� �÷��̾� üũ
	friend void openCard(player open);
	int getMyNumber();
	void takeCard();
	int getMoney();
	int inputBet(int& totalBet); // ������ ���� �ݾ� �Է�.
	void playerDie(); // play�� false�� �ٲ�.
private:
	int used = 0; // ���� ī�� ����
	int gameMoney=0;
	card myCard[5]; // ���� ������ ũ�� 5�� ����
	int myNumber;
	bool play = true; //�̹� �� ���̸� ģ ��� false�� ����
};

ostream& operator<< (ostream& a, const card& thiscard ) // ���� ���
{
	a << thiscard.pat << thiscard.cardNumber;

	return a;
}

card Deck[52];
int survivor=5; //���� ��ü ������

int getKeyBoard();
void gotoTest();
void printGoto(const int& x, const int& y);
void gotoxy(int x, int y);
void init();
void drawTitle();
void selectMenu();
void setColor(int forground, int background);


//-------------------------- ��� ������Ʈ
//card givePlayer(player member[]);
card drawCard(); // (�ӽ�)ī�� �̱�
void giveCard(int survive, int leader);
void obliBet(player member[], int& totalBet);
void openCard(player open);
void playGame(player member[],player &gambler);
int checkCard() {
	return 0;
};
void choiceBet(player member[], const int gambler, int leader,int& totalBet);
int choiceLeader(player member[], const int gambler); // ���� �ݾ� ���� ����� ù ���� ����
void choiceBet(player& follwer, int &betMoney, int& totalBet);