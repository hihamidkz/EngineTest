#ifndef ENGINE_BUILDER_H
#define ENGINE_BUILDER_H

#include <map>

#include "Engine.h"

class EngineBuilder {
private:
	Engine *engine;

	const double i = 10;
	const std::map<double, double> chart =
		std::map<double, double>{ {0, 20},
								  {75, 75},
								  {150, 100},
								  {200, 105},
								  {250, 75},
								  {300, 0} };
	const double tP = 110;
	const double hM = 0.01;
	const double hV = 0.0001;
	const double c = 0.1;
public:
	void createEngine() {
		engine = new Engine();
	}

	void setMomentOfInertia() {
		engine->setI(i);
	}

	void setDependenceOfTorqueOnSpeed() {
		engine->setChart(chart);
	}

	void setOverheatTemperature() {
		engine->setTP(tP);
	}

	void setCoefficientHM() {
		engine->setHM(hM);
	}

	void setCoefficientHV() {
		engine->setHV(hV);
	}

	void setCoefficientC() {
		engine->setC(c);
	}

	Engine *getEngine() {
		return engine;
	}
};

#endif
