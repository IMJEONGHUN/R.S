#pragma once
#include "main.h"

int Play_number[6] = { 0, }, Play_pattern[6] = { 0 };

int main()
{
	init(); //â ũ��� ���� ���� �Լ�
	while (1) {
		introGame(); // ����ȭ���� ǥ�úκ� �Լ�
		int menuNumber = menuChoice(); // �޴� ���� �Լ�
		if (menuNumber == 0) //���� ���� ��ư
		{
			gameImage();
			picture(Play_number, Play_pattern);
			
			choice_betting();
			choice_betting2();
			
			printAll(Play_number, Play_pattern); // �÷��̾�� ī�� ���� �Լ�.
			Print_result(1, 1);
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





