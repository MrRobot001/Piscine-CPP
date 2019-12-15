#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class IMonitorDisplay
{
public:
	IMonitorDisplay();
	IMonitorDisplay(IMonitorDisplay const &x);
	IMonitorDisplay &operator=(IMonitorDisplay const &x);
	virtual ~IMonitorDisplay();
};


#endif