#include <vector>
#include <iostream>
class szamitas4
{
public:
	std::string boolveg;
	std::string egyenl(double first, double second) {
		if (first == second) {
			boolveg = "True";
		}
		else {
			boolveg = "False";
		}
		return boolveg;
	}
	std::string rj(double first, double second) {
		if (first > second) {
			boolveg = "True";
		}
		else {
			boolveg = "False";
		}
		return boolveg;
	}
	std::string rb(double first, double second) {
		if (first < second) {
			boolveg = "True";
		}
		else {
			boolveg = "False";
		}
		return boolveg;
	}
};
//misc calculations



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
	//is true?
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