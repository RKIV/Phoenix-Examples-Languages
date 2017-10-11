#pragma once

#include "ctre/phoenix/Tasking/ILoopable.h"
#include "ctre/phoenix/signals/MovingAverage.h"

class TaskHSV : public CTRE::Tasking::ILoopable{
public:
	float Hue;
	float Saturation;
	float Value;

	virtual ~TaskHSV();
	/* ILoopable */
	void OnStart();
	void OnStop();
	bool IsDone();
	void OnLoop();
private:
	float _r, _g, _b;
	//Will need to write moving average class....
	CTRE::Signals::MovingAverage* _averageR = new CTRE::Signals::MovingAverage(10);
	CTRE::Signals::MovingAverage* _averageG = new CTRE::Signals::MovingAverage(10);
	CTRE::Signals::MovingAverage* _averageB = new CTRE::Signals::MovingAverage(10);
};