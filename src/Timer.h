#ifndef _TIMER_H_
#define _TIMER_H_

//-----------------------------------------------------------------------------
#if 0
class Timer{
private:
	cv::TickMeter meter;
	std::string msg;
public:
	Timer(std::string _msg){ msg = _msg;  meter.start(); }
	~Timer(void){ meter.stop(); std::cout << msg << meter.getTimeMilli() << "[ms]" << std::endl; }
};
#else
#include <time.h>
class Timer {
private:
	clock_t start, end;
	std::string msg;
	void Start(void) { start = clock(); }
	void Stop(void) { end = clock(); }
	double GetTimeMilli(void) { return 1000 * (end - start) / CLOCKS_PER_SEC; }
public:
	Timer(std::string _msg) { msg = _msg; Start(); }
	~Timer(void) { Stop(); std::cout << msg << GetTimeMilli() << "[ms]" << std::endl; }
};
#endif

#endif