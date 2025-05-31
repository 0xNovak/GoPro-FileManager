#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <cstdlib>

namespace fs = std::filesystem;

class Renamer {
///variables
public:
private:
	std::vector<std::string> filesToRename;
	std::vector<std::string> TargetNames;
	

///functions
public:
	//Constructor and Destructor
	Renamer() = default;
	~Renamer() = default;

	void start(const std::string& cwd);

protected:
	void LaunchMP4(const std::string& cwd, const std::string& fileName);
private:
	void Rename(const std::string& oldName, const std::string& newName);
};

