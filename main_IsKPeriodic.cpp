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
		Universal_Input<std::string>* str = new Universal_Input<std::string>('a', 'z'); // ввод строки
		std::cout << " Введите последовательность символов:\n";
		str_periodic = str->input();
		delete[] str;

		std::cout << "\n Введите кратность:\n";
		Universal_Input<int>* K = new Universal_Input<int>('0', '9'); // ввод коэффициента кратности
		k = K->input();
		delete[] K;
		std::cout << "\n";

		IsKPeriodic accordance; // определение соответствия кратности
		accordance.IKP(str_periodic, k);

		std::cout << " Продолжить работу - 1\n";
		std::cout << " Завершить работу - 2\n";
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
	std::cout << "\n\n\n\n       Всего хорошего!";
	Sleep(1500);
	system("cls");

}