#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include "Historycomp.h"

//calculation set
#include "calculations.h"
//calculation set

//calculation engine
#include "calculationengine.h"
//calculation engine
void synerr() {
	std::cout << "Syntax error!\n";
	system("pause");
	system("CLS");
}

//dont touch me--------------------------------------------------------
bool usererr(std::vector <double> num, std::vector <std::string> exp) {
//if (exp[0] == "!")
	bool hasfelk = false;
	for (size_t i = 0; i < exp.size(); i++)
	{
		if (exp[i] == "!") {
			hasfelk = true;
			break;
		}
	}
	for (size_t i = 0; i < exp.size(); i++)
	{
		if (exp[i] == "!") {
			if (exp.size() < num.size()) {
				return true;
			}
			else if (num.size() < exp.size())
			{
				return true;
			}

		}
		else if (hasfelk == true) {
			break;
		}
		else
		{
			if (num.size() == 2 and exp.size() == 1) {
				return false;
			}
			else if (num.size() <= exp.size() - 1 * 2) {
				return true;
			}
			else if (num.size() == exp.size()) {
				if (hasfelk == true) {
					break;
				}
				else { return true; }
			}
		}
			return false;
	}
}
//dont touch me--------------------------------------------------------

int main() {
	int whattoprint = 1;
	std::string boolveg;
	std::string vegreturn;
	while (true) {
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
				double numT = stod(user_input[i]);
				num.push_back(numT);
			}
			catch (const std::exception&)
			{
				exp.push_back(user_input[i]);
			}
		}
		//filter / handle bullshit inputs

		if (usererr(num, exp) == true) {
			synerr();
			continue;
		};
		
		vegreturn = calculationengine(num, exp, whattoprint, boolveg);
		if (num.size() == 1 and exp.size() == 0) {
			vegreturn = std::to_string(num[0]);
		}
		std::cout << "Answer : " << vegreturn << std::endl;
		historycomp(user_inputTEMP, vegreturn);
		//veg or sveg
		system("pause");
		system("cls");
	}
}