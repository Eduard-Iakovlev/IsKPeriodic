#include "IsKPeriodic.h"
#include <iostream>

IsKPeriodic::IsKPeriodic(std::string sub, int lenght_sub, int lenght_periodic)
	: _sub(sub), _lenght_sub(lenght_sub), _lenght_periodic(lenght_periodic) {}

void IsKPeriodic::substr(std::string periodic) // ����������� ����� ���������
{
	_lenght_periodic = periodic.size();
	_sub.push_back(periodic[0]);
	for (int i = 1; i < _lenght_periodic; i++) {
		if (periodic[i] != periodic[0]) _sub.push_back(periodic[i]);
		else {
			_sub.push_back('\0');
			break;
		}
	}
	std::cout << " ���������: " << _sub << "\n";
}

void IsKPeriodic::IKP(std::string periodic, int multiplicity)
{
	substr(periodic);
	_lenght_sub = _sub.size();
	// ����������� ������������ �������� ��������� ����� ���������
	if (multiplicity != _lenght_sub-1) {
		std::cout << " ��������� �� ������������� ��������� ��������\n";
		return;
	}
	bool mult = true;

	// ����������� ������������� �� ������
	for (int i = 0; i < _lenght_periodic; i += (_lenght_sub-1)) {
		int count = 0;
		for (int j = i; j < (i + _lenght_sub - 1); j++) {
			if (_sub[count] != periodic[i + count]) {
				std::cout << " ������ �� ����� ���������� - �� ������� \n";
				mult = false;
				break;
			}
			count++;
		}
		if (mult == false) break;
	}
	if (mult == true) std::cout << " ��������� ������������� ��������� ��������.\n";
}
