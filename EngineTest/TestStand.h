#ifndef TEST_STAND_H
#define TEST_STAND_H

#include <cmath>

template <class T>
class TestStand {
public:
	TestStand(T *engine, double ambT) {
		this->engine = engine;
		this->ambT = ambT;
	}

	~TestStand() {
	}

	void startTest() {
	}
private:
	T *engine;
	double ambT; // Ambient temperature
};

#endif
