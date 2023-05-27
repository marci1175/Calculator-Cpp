#include <vector>
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include "calculations.h"


std::string calculationengine(std::vector <double> num, std::vector <std::string> exp, int whattoprint, std::string boolveg) {
	//set default adresses
	whattoprint = 1;
	double veg = 0;
	szamitas3 lv1;
	szamitas2 lv2;
	sciszamitas2 scilv2;
	szamitas4 lv4;

	//Calculation engine supports : <> = + * - :

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
		if (exp[i] == "=")
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
	std::string vegstoi = std::to_string(veg);

	//what to return
	if (whattoprint == 1)
	{
		std::cout << "Answer : " << veg << std::endl;
		return vegstoi;
	}
	else if (whattoprint == 2) {
		std::cout << "Answer : " << boolveg << std::endl;
		return vegstoi;
	}
}