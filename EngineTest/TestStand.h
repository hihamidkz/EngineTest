#ifndef TEST_STAND_H
#define TEST_STAND_H

#include <iostream>
#include <cmath>

#include "Engine.h"

#define EPS 1e-5

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
		double curT = ambT; // Engine's current temperature
		double prev = 0;

		engine->start();

		for (time = 0; engine->getTP() - engine->getT() > EPS; time++) {
			if (curT == prev) {
				return -1;
			}

			curT = engine->getT();
			engine->warming();
			engine->cooling(curT, ambT);

			engine->timestamp();
			prev = engine->getT();
		}

		return time;
	}
private:
	T *engine;
	double ambT; // Ambient temperature
};

#endif
