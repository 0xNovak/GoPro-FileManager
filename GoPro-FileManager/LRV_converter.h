#pragma once

#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class LRV_converter {

///functions
public:
	//constructor && destructor
	LRV_converter() = default;
	~LRV_converter() = default;
	//main function
	void start(const std::string lrvDir);
private:
	void makeDir(const std::string& dir);
	void Clone_and_Convert_File(const std::string& lrvDir, const std::string& filename, const std::string& dest);
};

