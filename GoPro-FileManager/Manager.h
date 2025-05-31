#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include "Renamer.h"
#include "DirectoryManager.h"
#include "LRV_converter.h"	


class Manager {

///variables
public:

private:
	Renamer renamer; // Create an instance of the Renamer class
	DirectoryManager dirManager; // Create an instance of the DirectoryManager class
	LRV_converter lrvConverter; // Create an instance of the LRV_converter class

	std::string mainFolder;
	std::string cwd, vwd; // current working directory && virtual working directory
	bool isRenamingOff = false;
	bool openFiles = true; 
	bool converLRV = true;


///functions
public:
	//Constructor and Destructor
	Manager() = default;
	~Manager() = default;

	//Main function
	void start();

	//Setters
	void setMainFolder(const std::string& folderName) {
		mainFolder = folderName;
	}
	void setCWD(const std::string& path) {
		cwd = path;
	}
	void updateVWD() {
		vwd = cwd + '\\' + mainFolder;;
	}
	void RenamingIsOff() {
		isRenamingOff = true;
	}
	void DontConvertLRV() {
		converLRV = false;
	}
	//Getters
	std::string getVWD() {
		return vwd;
	}
private:

};

