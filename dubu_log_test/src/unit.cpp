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
	EXPECT_THROW(DUBU_LOG_FATAL("File Test: {}", "FATAL"), dubu::log::LogError);
}

struct Vector {
	float x;
	float y;
	float z;

	friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
		return os << "(x: " << v.x << ", y: " << v.y << ", z: " << v.z << ")";
	}
};
TEST(dubu_log, custom_type) {
	dubu::log::Register<dubu::log::FileLogger>("custom_type.txt");

	Vector v{1, 2, 3};

	DUBU_LOG_DEBUG("Vector: {}", v);
}
