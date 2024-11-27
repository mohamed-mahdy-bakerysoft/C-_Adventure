#ifndef DAYCOUNTER_H
#define DAYCOUNTER_H

class Tree_3;  // Forward declaration to avoid circular dependency

class DayCounter {
private:
    int currentDay = 0;
    int maxDays = 30;

public:
    void increment();
};

#endif // DAYCOUNTER_H
