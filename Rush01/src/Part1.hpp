#ifndef PART1_HPP
# define PART1_HPP
# include <string>
# include <vector>
# include <unistd.h>
# include <limits.h>
# include <iostream>
# include "Part1.hpp"
# include <sys/utsname.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <ncurses.h>
# include <sys/utsname.h>
# define BUFFERLEN 128
# include <sys/sysctl.h>

typedef struct {
	uint_fast16_t x;
	uint_fast16_t y;
	uint_fast16_t height;
} vecPs;

typedef struct {
	vecPs offsetS;
	vecPs boundsS;

	uint_fast16_t top() { return offsetS.y; }
	uint_fast16_t bott() { return offsetS.y + boundsS.y; }
	uint_fast16_t left() { return offsetS.x; }
	uint_fast16_t right() { return offsetS.x + boundsS.x; }

	uint_fast16_t width() { return boundsS.x; }
	uint_fast16_t height() { return boundsS.y; }

} rect;

class Part1
{

public:
	float			cpuUsage;
	struct utsname	osInfo;
	std::string		hostname;
	std::string		username;
	std::string		timeNow;
	int				usedRam;
	int				freeRam;
	long			clockRate;
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