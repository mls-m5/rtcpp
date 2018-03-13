#include <iostream>
#include <stdlib.h> //system, NULL, EXIT_FAILURE
#include <dlfcn.h> //for dlopen dlsym
#include <string>
#include "api.h"

#include <chrono>
#include <thread>

using namespace std;

void checkError() {
    char *error;
    if ((error = dlerror()) != NULL)  {
        cerr << error << endl;
        exit(1);
    }
}


class ApplicationHandle: public IApplicationHandle {
	public:
	~ApplicationHandle() {}
	void print(string text) override {
		cout << text << endl;
	}
};

void callLib() {
	
	system("g++ -shared -o rt/test.so rt/test.cpp  -fPIC -I.  -std=c++11");

	void *lib = dlopen("rt/test.so", RTLD_NOW);
	
	checkError();

	typedef void (*functionType)(IApplicationHandle&);
	auto function = (functionType) dlsym(lib, "run");

	checkError();

	ApplicationHandle handle;

	function(handle);
	
	auto create = (decltype(&createPlugin)) dlsym(lib, "createPlugin");

	auto plugin = create();

	plugin->run(handle);
	

	dlclose(lib);
}

int main() {
	for (int i = 0; i < 10; ++i) {
		callLib();
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	
}
