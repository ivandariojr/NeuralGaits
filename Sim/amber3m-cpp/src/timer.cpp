#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include "../include/timer.hpp"

void Timer::start() {
  m_StartTime = std::chrono::steady_clock::now();
  m_bRunning = true;
}

void Timer::stop() {
  m_EndTime = std::chrono::steady_clock::now();
  m_bRunning = false;
}

double Timer::elapsedNanoseconds() {
  std::chrono::time_point<std::chrono::steady_clock> endTime;

  if(m_bRunning) {
    endTime = std::chrono::steady_clock::now();
  }
  else {
    endTime = m_EndTime;
  }

  return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - m_StartTime).count();
}

double Timer::elapsedMilliseconds() {
  return elapsedNanoseconds() * 1e-6;
}

double Timer::elapsedSeconds() {
  return elapsedMilliseconds() * 1e-3;
}
