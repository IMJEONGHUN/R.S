#pragma once
#include "main.h"

int Play_number[6] = { 0 }, Computer_number[6] = { 0 }, Play_pattern[6] = { 0 }, Computer_pattern[6] = { 0 };
int card_one = 0, reset_count = 0, temp[8] = { 0 }, results[5] = { 0 }, patterns[5] = { 0 };

int main()
{
	init(); //â ũ��� ���� ���� �Լ�
	while (1) {
		introGame(); // ����ȭ���� ǥ�úκ� �Լ�
		int menuNumber = menuChoice(); // �޴� ���� �Լ�
		if (menuNumber == 0) //���� ���� ��ư
		{
			gameImage();
			bettingNumber(); // ���� ������ �����ϴ� �Լ�
			picture(Play_number, Play_pattern, Computer_number, Computer_pattern);
		}
		else if (menuNumber == 1) // ���� ��Ģ ����
		{
			gameRule();
		}
		else if (menuNumber == 2) // ���� ���� ��ư
		{
			return 0;
		}
		system("cls");
	}
	return 0;
}







