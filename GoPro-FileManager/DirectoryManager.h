#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class DirectoryManager {


///Functions
public:
//Constructor and Destructor
	DirectoryManager() = default;
	~DirectoryManager() = default;
	
	// Main function
	void start(const std::string& cwd, const std::string& vwd);
private:
	void makeDirectories(const std::string& vwd);
	bool moveFile(const std::string& cwd, const std::string& vwd, const std::string& fileName);
};

