#pragma once
#include "main.h"


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







