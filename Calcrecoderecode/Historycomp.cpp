
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>
#pragma warning(disable : 4996)
class fileT
{
public:
	fileT() = default;
	fileT(std::string _ido, std::string _calculacioo ,std::string _veg) {
		ido = _ido;
		calculacioo = _calculacioo;
		veg = _veg;
	}
	std::string ido;
	std::string calculacioo;
	std::string veg;
};

int historycomp(std::string calculacio, std::string veg) {
	fileT file;
	std::vector <fileT> filev = {};
	std::fstream mf;
	mf.open("calculations.history", std::ios::app);
	if (!mf.is_open()) {
		std::cout << "Failed to create file!";
		system("pause");
		exit(0);
	}
	else {
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
		std::string timeString = std::ctime(&currentTime);
		filev.push_back(fileT(timeString, calculacio, veg));
		for (const auto& file : filev)
		{
			mf << std::endl << std::endl <<timeString << calculacio << " = " << veg;
		}
		mf.flush();
		mf.close();
	}
	mf.flush();
	mf.close();





	return 0;
}