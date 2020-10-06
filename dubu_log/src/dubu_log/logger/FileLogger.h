#pragma once

#include "ILogger.h"

namespace dubu::log {

class FileLogger : public ILogger {
public:
	FileLogger(std::string_view file);

protected:
	virtual void InternalLog(LogLevel           level,
	                         const std::string& file,
	                         uint32_t           line,
	                         const std::string& function,
	                         const std::string& text) override;

private:
	std::ofstream mStream;
};

}  // namespace dubu::log