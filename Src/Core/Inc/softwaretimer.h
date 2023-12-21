#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_
#define MAX_SLOT 3
extern int TimerFlag[MAX_SLOT];
void SetTimer(int duration, int timerflag);
void RunTimer();
void InitAllFlag();
void InitFlag(int i);
void UnInitAllFlag();
void UnInitFlag(int i);
#endif /* INC_SOFTWARETIMER_H_ */
