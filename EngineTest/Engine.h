#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <map>

class Engine {
private:
	double i;
	std::map<double, double> chart;
	double curV; // Current speed
	double curM; // Current torque
	double tP;
	double t;
	double hM;
	double hV;
	double c;

	/*
	  Using Linear Interpolation to calculate
	  the current torque depending on speed
	*/
	double interpolate() {
		auto dot1 = chart.lower_bound(curV);
		auto dot2 = prev(dot1);
		double x = (*dot1).first;
		double xPrev = (*dot2).first;
		double y = (*dot1).second;
		double yPrev = (*dot2).second;

		double a = (y - yPrev) / (x - xPrev);
		double b = yPrev - a * xPrev;

		return a * curV + b;
	}
public:
	void setI(double i) { this->i = i; }

	void setChart(std::map<double, double> chart) { this->chart = chart; }

	void setTP(double tP) { this->tP = tP; }

	void setT(double t) { this->t = t; }

	void setHM(double hM) { this->hM = hM; }

	void setHV(double hV) { this->hV = hV; }

	void setC(double c) { this->c = c; }

	double getTP() { return tP;	}

	double getT() { return t; }

	void start() {
		curV = (*chart.begin()).first;
		curM = (*chart.begin()).second;
	}

	void timestamp() {
		double a = curM / i;
		curV += a;
		curM = interpolate();
	}

	void warming() {
		t += (curM * hM + pow(curV, 2) * hV);
	}

	void cooling(double curT, double ambT) {
		t += c * (ambT - curT);
	}
};

#endif