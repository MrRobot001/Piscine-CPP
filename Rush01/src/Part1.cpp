#include "Part1.hpp"
#include <limits.h>
#include <unistd.h>
#include <ctime>

void Part1::updateRamUsage(void)
{
	char	getBuffer[60];
	FILE	*pc;
	pc = popen("top -l 1 -n 1 | awk '/PhysMem/ {print $2 $6}'", "r");
	fgets(getBuffer, 60, pc);
	pclose(pc);
	std::string s = getBuffer;
	size_t pos = s.find("M");
    this->usedRamStr = s.substr(0, pos + 1);
	s.erase(0, pos + 1);
	pos = s.find("M");
    this->freeRamStr = s.substr(0, pos + 1);
    this->usedRam = std::atoi(this->usedRamStr.c_str());
    this->freeRam = std::atoi(this->freeRamStr.c_str());
}

void Part1::updateTime(void)
{
	time_t timer = time(0);

	this->timeNow = ctime(&timer);
}

Part1::Part1(/* args */)
{
	char username[_POSIX_LOGIN_NAME_MAX];

	getlogin_r(username, _POSIX_LOGIN_NAME_MAX);

	char		cpuName[BUFFERLEN];
	size_t		bufferlen = BUFFERLEN;
	int			cpuCores;

	sysctlbyname("machdep.cpu.brand_string", &cpuName, &bufferlen, NULL, 0);
	sysctlbyname("hw.ncpu", &cpuCores, &bufferlen, NULL, 0);
	this->cpuName = cpuName;
	this->username = username;
	this->cpuCores = std::to_string(cpuCores);
	uname(&this->osInfo);
	this->hostname = osInfo.nodename;
	this->updateAll();
}

void Part1::updateNetwork(void)
{
	char	getBuffer[60];
	FILE	*pc;

	pc = popen("top -l 1 -n 1 | awk '/Network/ {print $3 $5}'", "r");
	fgets(getBuffer, 60, pc);
	pclose(pc);
	std::string s = getBuffer;
	size_t pos = s.find("/");
	this->networkIn = s.substr(0, pos);
	s.erase(0, pos + 1);
	pos = s.find("M");
	this->networkInSize = s.substr(0, pos);
	s.erase(0, pos + 1);
	pos = s.find("/");
	this->networkOut = s.substr(0, pos);
	s.erase(0, pos + 1);
	pos = s.find("M");
	this->networkOutSize = s.substr(0, pos);
}

void Part1::updateAll(void)
{
	this->updateTime();
	this->updateCpuUsage();
	this->updateRamUsage();
	this->updateNetwork();
}

void Part1::updateCpuUsage(void)
{
	char	getBuffer[8];
	FILE	*pc;

	pc = popen("top -l 1 -n 1 | awk \'/user/ {print $3}\'", "r");
	fgets(getBuffer, 8, pc);
	this->cpuUsage = std::atof(getBuffer);
	pclose(pc);
}

Part1::~Part1()
{
}
