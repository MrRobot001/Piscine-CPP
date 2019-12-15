#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <vector>
#include <string>

class IMonitorModule
{
public:
	IMonitorModule();
	IMonitorModule(IMonitorModule const &x);
	IMonitorModule &operator=(IMonitorModule const &x);
	virtual ~IMonitorModule();
};


#endif