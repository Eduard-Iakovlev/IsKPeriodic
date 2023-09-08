#pragma once
#include <iostream>
#include <string>
#include <conio.h>

template<typename T>
class Universal_Input
{
public:
	Universal_Input() = default;
	Universal_Input(char first_simbol, char last_simbol)
		: _first_simbol(first_simbol), _last_simbol(last_simbol) {}

	T input() {

		while (true) {
			_str[_counter] = _getch();

			if (_str[_counter] >= _first_simbol && _str[_counter] <= _last_simbol) {
				std::cout << _str[_counter];
				_counter++;
			}
			else if (_str[_counter] == _back_space) {
				if (_counter == 0) continue;
				else {
					std::cout << "\b" << " " << "\b";
					_counter--;
				}
			}
			else if (_str[_counter] == _enter) {
				if (_str[0] == _enter) continue;
				else {
					if constexpr (std::is_same_v<T, int>) {
						if (atoi(_str) == 0) {
							std::cout << " Коэффициент должен быть больше нуля\n";
							continue;
						}
					}
					_str[_counter] = '\0';
					break;
				}
			}
			else {
				_str[_counter] = '\0';
				std::cout << " " << "\b";
			}
		}
		if constexpr (std::is_same_v<T, int>) {
			return atoi(_str);
		}
		else return std::string(_str);
	}
	~Universal_Input() = default;

private:
	char _first_simbol{};
	char _last_simbol{};
	const char _back_space{ 8 };
	const char _enter{ 13 };
	char _str[256]{};
	int _counter{ 0 };
};
