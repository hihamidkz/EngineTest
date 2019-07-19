#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "Director.h"
#include "TestStand.h"

double readTemperature() {
	std::cout << "Input ambient temperature: ";
	double ambT = 0;
	std::cin >> ambT;

	return ambT;
}

Engine *createEngine() {
	EngineBuilder engineBuilder;
	Director dir;
	Engine *engine = dir.createEngine(engineBuilder);

	return engine;
}

template <class T>
int startTest(T &testStand) {
	return testStand.startTest();
}

void outputResults(int time) {
	if (time > 0) {
		std::cout << "Time to overheat: " << time << " seconds" << std::endl;
	} else {
		std::cout << "The engine will not overheat" << std::endl;
	}
}

#endif