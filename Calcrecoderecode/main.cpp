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



		//calculator engine
		// ! pow
		//re-backup exp. size
		int expelozmeny = exp.size();
		for (size_t i = 0; i < exp.size() + 1; i++)
		{
			if (expelozmeny == i or exp.size() < i + 1 or exp[0] == "=")
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
			if (expelozmeny == i or exp[0] == "=" or exp[0] == "<" or exp[0] == ">")
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
			if (expelozmeny == i or exp[0] == "=")
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
		expelozmeny = exp.size();
		for (size_t i = 0; i < exp.size() + 1; i++)
		{
			if (expelozmeny == i)
			{
				break;
			}
			if (exp[0] == "=" or exp[0] == ">" or exp[0] == "<") {
				i = 0;
				whattoprint = 2;
			}
			if(exp[i] == "=")
			{
				boolveg = lv4.egyenl(num[i], num[i + 1]);
				break;
			}
			else if (exp[i] == ">") {
				boolveg = lv4.rj(num[i], num[i + 1]);
				break;
			}
			else if (exp[i] == "<") {
				boolveg = lv4.rb(num[i], num[i + 1]);
				break;
			}
		}
		//insert <> handling here ::
		std::string sveg = std::to_string(veg);
		
		//print out veg
		if(whattoprint == 1)
		{
			std::cout << "Answer : " << veg << std::endl;
			historycomp(user_inputTEMP, sveg);
		}
		else if (whattoprint == 2) {
			std::cout << "Answer : " << boolveg << std::endl;
			historycomp(user_inputTEMP, boolveg);
		}
		
		system("pause");
		system("cls");
	}
}