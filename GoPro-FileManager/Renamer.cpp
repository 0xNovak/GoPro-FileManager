#include "Renamer.h"



void Renamer::start(const std::string& cwd) {
	

	//Getting files
	try {
		for (const auto& entry : fs::directory_iterator(cwd)) {
			if (entry.is_regular_file()) {
				if (entry.path().filename().string().ends_with(".THM")) {
					std::string foundfile, newName;
					foundfile = entry.path().filename().string();

					// Removing .THM from the filename
					foundfile.erase(foundfile.end() - 3, foundfile.end());
					
					// Leave only serial number (with dot on end) of video
					///<example> 
					/// GX010001. -> 10001.
					///</example>
					foundfile.erase(0, 2);
					

					filesToRename.push_back(foundfile);
					std::cout << foundfile << " -> ";
					do {
						std::cin >> newName;
					} while (newName == "" || newName == " " || newName == "\n" || newName == "\t");
					TargetNames.push_back(newName);
				}
			}
		}
	} catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	// Renaming files
	std::cout << "  Remaming..." << std::endl;
	for (int i = 0; i < filesToRename.size(); i++) {
		std::string oldSerialNumb = filesToRename[i];
		std::string newName = TargetNames[i];
		
		std::cout << "    Renaming serie " << oldSerialNumb << " to " << newName << std::endl;

		
		
		std::cout << "      Renaming MP4 file..." << std::endl;
		
		std::string oldMP4 = "GX" + oldSerialNumb + "MP4";
		Rename(cwd + "\\" + oldMP4, cwd + "\\" + newName + ".mp4");
		

		std::cout << "      Renaming THM file..." << std::endl;
		std::string oldTHM = "GX" + oldSerialNumb + "THM";
		Rename(cwd + "\\" + oldTHM, cwd + "\\" + newName + ".THM");


		std::cout << "    Renaming LRV file..." << std::endl;
		std::string oldLRV = "GL" + oldSerialNumb + "LRV";
		Rename(cwd + "\\" + oldLRV, cwd + "\\" + newName + ".LRV");


		
	}
	std::cout << "  Renaming Complete" << std::endl;
	filesToRename.clear();
	TargetNames.clear();
}


void Renamer::LaunchMP4(const std::string & cwd, const std::string & fileName) {
		std::string command = "start " + cwd + "\\" + fileName;
		system(command.c_str());
}
void Renamer::Rename(const std::string& oldNamePath, const std::string& newNamePath) {
	try {
		fs::rename(oldNamePath, newNamePath);
	} catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
}