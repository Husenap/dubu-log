#include <gtest/gtest.h>

#include "dubu_log/dubu_log.h"

TEST(dubu_log, console_logger) {
	dubu::log::Register<dubu::log::ConsoleLogger>();

	DUBU_LOG_DEBUG("Console Test: {}", "DEBUG");
	DUBU_LOG_INFO("Console Test: {}", "INFO");
	DUBU_LOG_WARNING("Console Test: {}", "WARNING");
	DUBU_LOG_ERROR("Console Test: {}", "ERROR");
	EXPECT_THROW(DUBU_LOG_FATAL("Console Test: {}", "FATAL"),
	             dubu::log::LogError);
}

TEST(dubu_log, file_logger) {
	dubu::log::Register<dubu::log::FileLogger>("log.txt");

	DUBU_LOG_DEBUG("File Test: {}", "DEBUG");
	DUBU_LOG_INFO("File Test: {}", "INFO");
	DUBU_LOG_WARNING("File Test: {}", "WARNING");
	DUBU_LOG_ERROR("File Test: {}", "ERROR");
	EXPECT_THROW(DUBU_LOG_FATAL("File Test: {}", "FATAL"),
	             dubu::log::LogError);
}

