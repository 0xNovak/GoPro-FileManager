#include "LRV_converter.h"


void LRV_converter::start(const std::string lrvDir) {
	makeDir(lrvDir);
	std::cout << "  Converting LRV files...\n";
	try {
		for (const auto& entry : std::filesystem::directory_iterator(lrvDir)) {
			if (entry.path().extension() == ".lrv" || entry.path().extension() == ".LRV") {
				Clone_and_Convert_File(lrvDir, entry.path().filename().string(), lrvDir + "\\mp4");
			}
		}
	} catch (const std::filesystem::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << "  Conversion complete.\n";
}

void LRV_converter::Clone_and_Convert_File(const std::string& lrvDir, const std::string& filename, const std::string& dest) {

	fs::copy_file(lrvDir + "\\" + filename, dest + "\\" + filename, fs::copy_options::overwrite_existing);
	std::cout << "    File cloned: " << filename << '\n';
	std::string targetName = filename;
	targetName.erase(targetName.end() - 4, targetName.end());
	targetName += ".mp4";

	fs::rename(dest + "\\" + filename, dest + "\\" + targetName);
	std::cout << "    File converted to: " << targetName << '\n';
}

void LRV_converter::makeDir(const std::string & dir) {
	std::cout << "  Creating directory for converted files\n";
	
	if (!fs::exists(dir + "\\mp4")) {
		fs::create_directories(dir + "\\mp4");
		std::cout << "    Directory created: " << dir + "\\mp4" << '\n';
	} else {
		std::cout << "    Directory already exists: " << dir + "\\mp4" << '\n';

	}
}
