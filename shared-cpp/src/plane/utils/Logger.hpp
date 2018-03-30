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

#define LEVEL_ERROR 2
#define LEVEL_WARN 1
#define LEVEL_INFO 0
#define LEVEL_DEBUG -1
#define LEVEL_TRACE -2

namespace plane {

class Logger { // A lightweight logging abstraction
public:
	Logger(int level) { this->level = level; }

	void log(const char* msg, int msgLevel) const {
		if (level <= msgLevel) {
			std::time_t t = std::time(0);
			std::tm now = *std::localtime(&t);
			std::cout << std::put_time(&now, "%d.%m.%Y %H:%M:%S") << " - " << msg << std::endl;
		}
	}

	void error(const char* msg) const { log(msg, LEVEL_ERROR); }

	void warn(const char* msg) const { log(msg, LEVEL_WARN); }

	void info(const char* msg) const { log(msg, LEVEL_INFO); }

	void debug(const char* msg) const { log(msg, LEVEL_DEBUG); }

	void trace(const char* msg) const { log(msg, LEVEL_TRACE); }
private:
	int level;
};

const Logger LOG(LEVEL_DEBUG); // Global logger instance

}

#endif /* SRC_PLANE_UTILS_LOGGER_HPP_ */
