#include <string>

class IApplicationHandle {
	public:
	~IApplicationHandle() {};
	virtual void print(std::string) = 0;
};

class IPlugin {
	public:
	virtual void run(IApplicationHandle&) {};
	virtual ~IPlugin() {};
};


extern "C" { 
int run(IApplicationHandle &); 

IPlugin *createPlugin();
}
