#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "EngineBuilder.h"

class Director {
public:
	Engine *createEngine(EngineBuilder &builder) {
		builder.createEngine();
		builder.setMomentOfInertia();
		builder.setDependenceOfTorqueOnSpeed();
		builder.setOverheatTemperature();
		builder.setCoefficientHM();
		builder.setCoefficientHV();
		builder.setCoefficientC();

		return builder.getEngine();
	}
};

#endif