


// GoPro File Manager
#include <filesystem>
#include <iostream>
#include <string>
#include "Manager.h"


void sendHelp();
void sendVerison();

int main(int argc, char* argv[]) {


	Manager manager; // Create an instance of the Manager class



	///	<summary>
	///	Main function that handles command line arguments and initializes the program.
	/// </summary>

	/* 
	* RETURN CODES
	*	0 - Success 
	*   	1 - 
	*   	2 - Unknown argument provided
	*	3 - folder with the same name already exists
	*   
	*/


	
	if (argc == 1) { // Check if the user provided the main folder name
		std::string TempInput;
		std::cout << " No Main folder name provided\n"
				  << " Please provide a name for the main folder: ";
		
		std::cin >> TempInput;
		std::cout << "\n";
		if (TempInput == "" || TempInput == " " || TempInput == "\n" || TempInput == "\t") {
			std::cout << " No name provided\n"
					  << " Main folder will be named /GoPro-FileManager\n"
					  << " Plese rename it before next use\n";
			TempInput = "GoPro-FileManager";
		}
		else if (TempInput == "-h" || TempInput == "--help") {
			sendHelp();
			return 0;
		} else if (TempInput == "-v" || TempInput == "--version") {
			sendVerison();
			return 0;
		}
		else {
			manager.setMainFolder(TempInput);
		}
		
	} else {
		manager.setMainFolder(argv[1]);
	}



	manager.setCWD(std::filesystem::current_path().string());
	manager.updateVWD();

	if (std::filesystem::exists(manager.getVWD())) {
		std::cout << "Folder with the same name already exists\n" << "Abording the program\n";

		return 3;
	} else {
		std::filesystem::create_directory(manager.getVWD());
		std::cout << "  Created folder: " << manager.getVWD() << "\n";
	}

	// Check for additional command line arguments
	for (int i = 2; i <= argc-1; ++i) {
		std::string arg = argv[i];

		if (arg == "-help" || arg == "-h") {
			sendHelp();
			return 0;
		} else if (arg == "-r" || arg == "--dont-rename") {
			manager.RenamingIsOff();
			std::cout << "  Renaming is off\n";
		} else if (arg == "-c" || arg == "--dont-convert") {
			manager.DontConvertLRV();
			std::cout << "  Converting is off\n";
		}

		else if (arg == "-v" || arg == "--version") {
			sendVerison();
			return 0;
		}

		

		else {
			std::cout
				<< "Unknown option: " << arg << "\n"
				<< "Use -h or --help for help\n";
			return 2;
		}

	}
	manager.start();
	

	return 0;
}



// Function to display help information

void sendHelp() {
	std::cout
		<< "Usage: GoPro-FileManager [MainFolderName] [options]\n"
		<< "GoPro File manager is cli tool used to help you manage your videos into diverent folders based on type and mass renaming files\n"
		<< "Options:\n"
		<< "  -h  --help        Show this help message\n"
		<< "  -r  --dont-rename    Disables Renaming files\n"
		<< "  -v  --version     Show version information\n"
		<< "  -c  --dont-convert  Disables converting LRV files to MP4\n"
		;
}
void sendVerison() {
	std::cout
		<< "GoPro File manager version 1.0\n";
}
