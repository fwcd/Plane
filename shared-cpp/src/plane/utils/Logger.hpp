/*
 * Logger.hpp
 *
 *  Created on: 30.03.2018
 */

#ifndef SRC_PLANE_UTILS_LOGGER_HPP_
#define SRC_PLANE_UTILS_LOGGER_HPP_

#include <sys/types.h>
#include <iomanip>
#include <ctime>
#include <iostream>

#define LEVEL_NONE 1000
#define LEVEL_ERROR 2
#define LEVEL_WARN 1
#define LEVEL_INFO 0
#define LEVEL_DEBUG -1
#define LEVEL_TRACE -2
#define LEVEL_DEEP_TRACE -3

#define CURRENT_LOG_LEVEL LEVEL_DEEP_TRACE

namespace plane {

class Logger { // A lightweight logging abstraction
public:
	Logger() {}

	void error(const char* msg) const {
#if CURRENT_LOG_LEVEL <= LEVEL_ERROR
		log(msg, LEVEL_ERROR);
#endif
	}

	void warn(const char* msg) const {
#if CURRENT_LOG_LEVEL <= LEVEL_WARN
		log(msg, LEVEL_WARN);
#endif
	}

	void info(const char* msg) const {
#if CURRENT_LOG_LEVEL <= LEVEL_INFO
		log(msg, LEVEL_INFO);
#endif
	}

	void debug(const char* msg) const {
#if CURRENT_LOG_LEVEL <= LEVEL_DEBUG
		log(msg, LEVEL_DEBUG);
#endif
	}

	void trace(const char* msg) const {
#if CURRENT_LOG_LEVEL <= LEVEL_TRACE
		log(msg, LEVEL_TRACE);
#endif
	}

	void deepTrace(const char* msg) const {
#if CURRENT_LOG_LEVEL <= LEVEL_DEEP_TRACE
		log(msg, LEVEL_DEEP_TRACE);
#endif
	}
private:
	void log(const char* msg, int msgLevel) const {
		std::time_t t = std::time(0);
		std::tm now = *std::localtime(&t);
		std::cout << std::put_time(&now, "%d.%m.%Y %H:%M:%S") << " - " << msg << std::endl;
	}
};

const Logger LOG; // Global logger instance

}

#endif /* SRC_PLANE_UTILS_LOGGER_HPP_ */
