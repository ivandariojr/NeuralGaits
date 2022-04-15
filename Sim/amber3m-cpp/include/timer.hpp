#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
  void start();
  void stop();

  double elapsedNanoseconds();
  double elapsedMilliseconds();
  double elapsedSeconds();

private:
    std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
    std::chrono::time_point<std::chrono::steady_clock> m_EndTime;
    bool                                               m_bRunning = false;
};

#endif