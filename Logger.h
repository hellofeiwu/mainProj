#pragma once
#include <iostream>
//#include <fstream>
using namespace std;

enum class LogLevel
{
	FATAL_ERROR,
	ERROR,
	WARNING,
	INFO
};

class Logger
{
public:
	static Logger& getInstance() {
		static Logger instance;
		return instance;
	}
	void openFile(string fileName) {
		closeFile();
		_logFile.open(fileName, ios::out | ios::app);
	}

	void closeFile() {
		if (_logFile.is_open()) {
			_logFile.close();
		}
	}

	void log(string message, LogLevel level, const char* file, int line) {
		time_t now = time(nullptr);
		struct tm timeInfo;
		localtime_s(&timeInfo, &now);
		char timeBuffer[100];
		strftime(timeBuffer, sizeof(timeBuffer),"%Y-%m-%d %H:%M:%S", &timeInfo);

		string levelStr;
		switch (level)
		{
		case LogLevel::FATAL_ERROR:
			levelStr = "FATAL_ERROR";
			break;
		case LogLevel::ERROR:
			levelStr = "ERROR";
			break;
		case LogLevel::WARNING:
			levelStr = "WARNING";
			break;
		case LogLevel::INFO:
			levelStr = "INFO";
			break;
		}
		cout << timeBuffer<<" "<<file<<" "<<line
			<< " ["<<levelStr<<":] "<< message << endl;

		// write into a file
		if (_logFile.is_open()) {
			_logFile << timeBuffer << " " << file << " " << line
				<< " [" << levelStr << ":] " << message << endl;
		}
	}
private:
	Logger() {}
	~Logger() { closeFile(); }
	ofstream _logFile;
};

