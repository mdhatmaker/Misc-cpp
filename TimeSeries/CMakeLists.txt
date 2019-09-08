cmake_minimum_required(VERSION 3.7)
project(TimeSeries)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BarData.cpp BarData.h tools.cpp tools.h HistoricalData.cpp HistoricalData.h Contract.cpp Contract.h SimpleTime.cpp SimpleTime.h TimeTm.cpp TimeTm.h)
add_executable(TimeSeries ${SOURCE_FILES})