#ifndef TEST_STAND_H
#define TEST_STAND_H

#include <iostream>
#include <cmath>

#include "Engine.h"

#define EPS 1e-1

template <class T>
class TestStand {
public:
	TestStand(T *engine, double ambT) {
		this->engine = engine;
		this->ambT = ambT;
	}

	~TestStand() {
	}

	int startTest() {
		int time;
		double a;
		double prev = 0;
		double curV = (*engine->chart.begin()).first; // Current speed
		double curM = (*engine->chart.begin()).second; // Current torque

		for (time = 0; engine->tP - engine->t > EPS; time++) {
			double up = curM  * engine->hM + pow(curV, 2) * engine->hV;
			double down = engine->c * (engine->t - ambT);
			engine->t += up;
			engine->t -= down;

			a = curM / engine->i;
			curV += a;
			curM = interpolate(engine->chart, curV);
			prev = engine->t;
		}

		return time;
	}
private:
	T *engine;
	double ambT; // Ambient temperature

	/*
	  Using Linear Interpolation to calculate 
	  the current torque depending on speed
	*/
	double interpolate(std::map<double, double> mas, double val) {
		auto dot1 = mas.lower_bound(val);
		auto dot2 = prev(dot1);
		double x = (*dot1).first;
		double xPrev = (*dot2).first;
		double y = (*dot1).second;
		double yPrev = (*dot2).second;

		double a = (y - yPrev) / (x - xPrev);
		double b = yPrev - a * xPrev;

		return a * val + b;
	}
};

#endif
