#include <iostream>

#include "Engine.h"
#include "TestStand.h"

using namespace std;

int main() {
	double ambT;
	cout << "Input ambient temperature" << endl;
	cin >> ambT;

	Engine *engine = new Engine;
	engine->i = 10;
	engine->chart = map<double, double>{ {0, 20},
									     {75, 75},
									     {150, 100},
									     {200, 105},
									     {250, 75},
									     {300, 0} };
	engine->tP = 110;
	engine->t = ambT;
	engine->hM = 0.01;
	engine->hV = 0.0001;
	engine->c = 0.1;

	TestStand<Engine> testStand(engine, ambT);

	system("pause");
	return 0;
}