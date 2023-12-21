#include "softwaretimer.h"

int TimerFlag[MAX_SLOT];
int TimerCounter[MAX_SLOT];
void SetTimer(int duration, int timerflag)
{
	TimerFlag[timerflag] = 0;
	TimerCounter[timerflag] = duration;
}

void RunTimer()
{
	for (int i = 0; i < MAX_SLOT; ++i) {
        if (TimerCounter[i] > 0) {
            TimerCounter[i]--;
            if (TimerCounter[i] <= 0) {
                TimerFlag[i] = 1;
            }
        }
    }
}

void InitAllFlag()
{
	for (int i = 0; i < MAX_SLOT; ++i) {
        TimerFlag[i] = 1;
    }
}

void InitFlag(int i)
{
    TimerFlag[i] = 1;
}

void UnInitAllFlag()
{
	for (int i = 0; i < MAX_SLOT; ++i) {
        TimerFlag[i] = 0;
    }
}

void UnInitFlag(int i)
{
    TimerFlag[i] = 0;
}
