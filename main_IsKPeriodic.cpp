#include <iostream>
#include "Windows.h"
#include "Inpu_data.h"
#include "IsKPeriodic.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string str_periodic;
	int k{ 1 };

	while (true) {
		Universal_Input<std::string>* str = new Universal_Input<std::string>('a', 'z'); // ���� ������
		std::cout << " ������� ������������������ ��������:\n";
		str_periodic = str->input();
		delete[] str;

		std::cout << "\n ������� ���������:\n";
		Universal_Input<int>* K = new Universal_Input<int>('0', '9'); // ���� ������������ ���������
		k = K->input();
		delete[] K;
		std::cout << "\n";

		IsKPeriodic accordance; // ����������� ������������ ���������
		accordance.IKP(str_periodic, k);

		std::cout << " ���������� ������ - 1\n";
		std::cout << " ��������� ������ - 2\n";
		Universal_Input<int>* Menu = new Universal_Input<int>('1', '2');
		if (Menu->input() == 2) {
			delete[] Menu;
			break;
		}
		else {
			delete[] Menu;
			system("cls");
			continue;
		}


	}
	std::cout << "\n\n\n\n       ����� ��������!";
	Sleep(1500);
	system("cls");

}