#include "StdAfx.h"
#include "StdTimeControl.h"
#include <time.h>
#include <sys/timeb.h>

// -------------------------- CTor --------------------------------------------
StdTimeControl::StdTimeControl()
{
	mStartTime = 0;
	mCPUTime   = 0;
}

// -------------------------- DTor --------------------------------------------
StdTimeControl::~StdTimeControl()
{
}

// -------------------------- GetCPUTime --------------------------------------
int64 StdTimeControl::GetCPUTime()
{
   return ((int64)(clock()) * 1000) / (int64)(CLOCKS_PER_SEC); 
}

// -------------------------- GetCurrentTime ----------------------------------
int64 StdTimeControl::GetCurrentTime()
{
	timeb aCurrentTime;
	ftime(&aCurrentTime); 
	return ((int64)(aCurrentTime.time) * 1000 + 
		(int64)(aCurrentTime.millitm));
}

// -------------------------- GetCurrentTimeDiff ------------------------------
int64 StdTimeControl::GetCurrentTimeDiff() const
{
	return GetCurrentTime() - mStartTime;
}

// -------------------------- StoreStartTime ----------------------------------
void StdTimeControl::StoreStartTime()
{
	mStartTime = GetCurrentTime();
}

// -------------------------- StoreCPUTime ------------------------------------
void StdTimeControl::StoreCPUTime() 
{
	mCPUTime = GetCPUTime();
}

// -------------------------- GetCPUTimeDiff ----------------------------------
int64 StdTimeControl::GetCPUTimeDiff() const
{
	return GetCPUTime() - mCPUTime;
}


