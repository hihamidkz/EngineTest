#include "TestStand.h"
#include "Controller.h"


int main() {
	double ambT = readTemperature();

	Engine *engine = createEngine();
	engine->setT(ambT);

	TestStand<Engine> testStand(engine, ambT);
	int time = startTest(testStand);

	outputResults(time);

	delete engine;
	system("pause");
	return 0;
}