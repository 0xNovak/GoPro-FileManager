#include "Manager.h"



void Manager::start() {
	if (!isRenamingOff) {
		renamer.start(cwd);
	} else {
		std::cout
			<< "   Renaming is off\n"
			<< "    Skipping...\n";
	}
	dirManager.start(cwd, vwd);
	if(converLRV){
		lrvConverter.start(vwd+"\\lrv");
	}
	std::cout
		<< "Done!\n"
		;
}

	