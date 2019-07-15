#ifndef ENGINE_H
#define ENGINE_H

#include <map>

struct Engine {
	double i;
	std::map<double, double> chart;
	double tP;
	double t;
	double hM;
	double hV;
	double c;
};

#endif