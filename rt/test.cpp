

#include <iostream>
#include "api.h"

using namespace std;


int run(IApplicationHandle &handle) {
	handle.print("hej från rt with handle");
	cout << "hej från rt" << endl;
}


class MyPlugin: public IPlugin {
	public:
	
	
	virtual void run(IApplicationHandle& handle) override {
		cout << "hej från klassen" << endl;
		
		handle.print("Hej då");
	}
};



IPlugin *createPlugin() {
	return new MyPlugin;
}




