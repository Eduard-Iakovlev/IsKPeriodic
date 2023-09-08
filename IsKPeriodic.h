#pragma once
#include <string>


class IsKPeriodic
{
public:
	IsKPeriodic() = default;
	IsKPeriodic(std::string sub, int lenght_sub, int lenght_periodic);
	void substr(std::string perijdic);
	void IKP(std::string periodic, int multiplicity);
private:
	std::string _sub{};
	int _lenght_sub{ 0 };
	int _lenght_periodic{ 0 };
};