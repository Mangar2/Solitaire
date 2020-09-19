#ifndef __STDTIMECONTROL
#define __STDTIMECONTROL

typedef unsigned long long int64;
class StdTimeControl
{
public:
	StdTimeControl();
	~StdTimeControl();

	// ---------------------- operators ---------------------------------------

	// Stores the current time
	void StoreStartTime();

	// Stores the CPU time
	void StoreCPUTime();

	// ---------------------- getter ------------------------------------------
	// Gets the current time in milliseconds
	static int64 GetCurrentTime();

	// Gets the difference of current time and start time
	int64 GetCurrentTimeDiff() const;

	// Gets the current CPU time (time the process used) in milliseconds
	static int64 GetCPUTime();

	// Gets the difference of current cpu time and start cpu time
	int64 GetCPUTimeDiff() const;

private:
	int64 mStartTime;
	int64 mCPUTime;
};

#endif // __STDTIMECONTROL

