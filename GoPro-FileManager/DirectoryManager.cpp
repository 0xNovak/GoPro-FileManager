#include "DirectoryManager.h"

void DirectoryManager::start( const std::string& cwd, const std::string& vwd) {
	makeDirectories(vwd);
	std::cout << "  Moving files...\n";
	try {
		for (const auto& entry : fs::directory_iterator(cwd)) {
			if (entry.is_regular_file()) {
				std::string fileName = entry.path().filename().string();
				
				if (moveFile(cwd, vwd, fileName)) {
					std::cout << "      File moved: " << fileName << "\n";
				}
			}
			
		}
	} catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "  Files moved successfully.\n";
}

bool DirectoryManager::moveFile(const std::string& cwd, const std::string& vwd, const std::string& fileName) {
	std::string fileExtention = fileName.substr(fileName.find_last_of('.'));
	
		if (fileExtention == ".MP4" || fileExtention == ".mp4") {
			fs::rename(cwd + "\\" + fileName, vwd + "\\mp4\\" + fileName); return true;
		} else if (fileExtention == ".THM" || fileExtention == ".thm") {
			fs::rename(cwd + "\\" + fileName, vwd + "\\thm\\" + fileName); return true;
		} else if (fileExtention == ".LRV" || fileExtention == ".lrv") {
			fs::rename(cwd + "\\" + fileName, vwd + "\\lrv\\" + fileName); return true;
		}
		return false; // File not moved - not a valid type
	
}

void DirectoryManager::makeDirectories(const std::string& vwd) {
	std::cout << "  Creating directories...\n";
	std::string path = vwd + "\\mp4";
	if (!fs::exists(path)) {
		fs::create_directory(path);
	}
	path = vwd + "\\thm";
	if (!fs::exists(path)) {
		fs::create_directory(path);
	}
	path = vwd + "\\lrv";
	if (!fs::exists(path)) {
		fs::create_directory(path);
	}
	std::cout << "  Directories created successfully.\n";
	return;
}