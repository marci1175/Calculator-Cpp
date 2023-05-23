#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

class szamitas3
{
public:
	double veg;
	double ossz(double first, double second) {
		return veg = first + second;
	}
	double kivo(double first, double second) {
		return veg = first - second;
	}
};
class szamitas2
{
public:
	double veg;
	double szor(double first, double second) {
		return veg = first * second;
	}
	double oszt(double first, double second) {
		return veg = first / second;
	}

};
class sciszamitas2
{
public:
	std::vector <double> powv;
	std::vector <double> factv;
	double veg;
	double pow(double first, double second) {
		veg = privpow(first, second);
		return veg;
	};
	double fact(double first) {
		veg = privfact(first);
		return veg;
	};

private:
	//pow
	double privpow(double first, double second) {
		double bgfirst = first;
		powv.push_back(1);
		for (size_t i = 0; i < second; i++)
		{
			std::cout << "in";
			veg = powv[i] * bgfirst;
			powv.push_back(veg);
		}
		powv.erase(powv.begin(), powv.begin() + powv.size());

		return veg;
	}
	//factorial
	double privfact(double first) {
		factv.push_back(1);
		for (size_t i = 1; i < first + 1; i++)
		{
			veg = factv[i - 1] * i;
			factv.push_back(veg);
		}
		return veg;
	}

};

int main() {
	while(true){
		double veg = 0;
		szamitas3 lv1;
		szamitas2 lv2;
		sciszamitas2 scilv2;

		std::vector <std::string> user_input;
		std::vector <double> num;
		std::vector <std::string> exp;

		std::cout << "|: ";
		//ss

		std::string user_inputTEMP, name;
		std::getline(std::cin, user_inputTEMP);
		std::stringstream ss(user_inputTEMP);
		while (ss >> name) {
			user_input.push_back(name);
		}
		//separating + and 30
		for (size_t i = 0; i < user_input.size(); i++)
		{
			try
			{
				double numT = stof(user_input[i]);
				num.push_back(numT);
			}
			catch (const std::exception&)
			{
				exp.push_back(user_input[i]);
			}
		}
		//calculator engine
		// ! pow
		//re-backup exp. size
		int expelozmeny = exp.size();
		for (size_t i = 0; i < exp.size() + 1; i++)
		{
			if (expelozmeny == i or exp.size() < i + 1)
			{
				break;
			}
			if (exp[0] == "!" or exp[0] == "pow") {
				i = 0;
			}
			//ha 1 akk fail , 0-nal van a +
			if (exp[i] == "!")
			{
				veg = scilv2.fact(num[i]);
				exp.erase(exp.begin() + i);
				num.erase(num.begin() + i);
				num.insert(num.begin() + i, veg);
			}
			else if (exp[i] == "pow")
			{
				veg = scilv2.pow(num[i], num[i + 1]);
				exp.erase(exp.begin() + i);
				num.erase(num.begin() + i, num.begin() + (i + 2));
				num.insert(num.begin() + i, veg);
			}
		}
		// : *
		//re-backup exp. size
		expelozmeny = exp.size();
		for (size_t i = 0; i < exp.size() + 1; i++)
		{
			if (expelozmeny == i)
			{
				break;
			}
			if (exp[0] == ":" or exp[0] == "/" or exp[0] == "*") {
				i = 0;
			}
			if (exp[i] == ":" or exp[i] == "/")
			{
				veg = lv2.oszt(num[i], num[i + 1]);
				exp.erase(exp.begin() + i);
				num.erase(num.begin() + i, num.begin() + (i + 2));
				num.insert(num.begin() + i, veg);
			}
			else if (exp[i] == "*")
			{
				veg = lv2.szor(num[i], num[i + 1]);
				exp.erase(exp.begin() + i);
				num.erase(num.begin() + i, num.begin() + (i + 2));
				num.insert(num.begin() + i, veg);
			}
		}
		//+ -
		//re-backup exp. size
		expelozmeny = exp.size();
		for (size_t i = 0; i < exp.size() + 1; i++)
		{
			if (expelozmeny == i)
			{
				break;
			}
			if (exp[0] == "+" or exp[0] == "-") {
				i = 0;
			}
			if (exp[i] == "-")
			{
				veg = lv1.kivo(num[i], num[i + 1]);
				exp.erase(exp.begin() + i);
				num.erase(num.begin() + i, num.begin() + (i + 2));
				num.insert(num.begin() + i, veg);
			}
			else if (exp[i] == "+")
			{
				veg = lv1.ossz(num[i], num[i + 1]);
				exp.erase(exp.begin() + i);
				num.erase(num.begin() + i, num.begin() + (i + 2));
				num.insert(num.begin() + i, veg);
			}

		}



		//print out veg
		std::cout << "Answer : " << veg << std::endl;
		system("pause");
		system("cls");
	}
}