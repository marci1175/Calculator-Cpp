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

int main() {
	int whattoprint = 1;
	std::string boolveg;
	while (true) {
		double veg = 0;
		szamitas3 lv1;
		szamitas2 lv2;
		sciszamitas2 scilv2;
		szamitas4 lv4;

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


		//filter / handle bullshit inputs
		if (exp.size() >= num.size()) {
			std::cout << "\nSyntax error!\n";
			system("pause");
			system("CLS");
			std::cout << "[Correct usage : 4 + 4 (Always separate with a space!)]\n\n";
			continue;
		}
		if (num.size() == 1 and exp.size() == 0) {
			veg = num[0];
		}

		std::string vegreturn = calculationengine(num, exp, whattoprint, boolveg);

		historycomp(user_inputTEMP, vegreturn);
		//veg or sveg
		system("pause");
		system("cls");
	}
}