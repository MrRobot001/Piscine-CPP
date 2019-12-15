#ifndef PART1_HPP
# define PART1_HPP
# include <string>
# include <sys/utsname.h>
# define BUFFERLEN 128
# include <sys/sysctl.h>

# include "mlx.h"

class Part1
{
private:
public:
	float			cpuUsage;
	struct utsname	osInfo;
	std::string		hostname;
	std::string		username;
	std::string		timeNow;
	long long		usedRam;
	long long		freeRam;
	std::string		usedRamStr;
	std::string		freeRamStr;
	std::string		cpuName;
	std::string		cpuCores;
	std::string		networkIn;
	std::string		networkOut;
	std::string		networkInSize;
	std::string		networkOutSize;

	void			updateCpuUsage(void);
	void			updateTime(void);
	void			updateRamUsage(void);
	void			updateNetwork(void);
	void			updateAll();

	Part1(/* args */);
	~Part1();
};

#endif
