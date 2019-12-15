#include <unistd.h>
#include <limits.h>
#include <iostream>
#include "Part1.hpp"
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <ncurses.h>

#include	"mlx.h"


void mlx(Part1 one);

void    initColor(void)
{
    start_color();

    init_pair(1,  COLOR_RED,     COLOR_BLACK);
    init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
    init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
    init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
    init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
    init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
    init_pair(8,  COLOR_WHITE,   COLOR_BLACK);
    init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
    init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
    init_pair(11, COLOR_WHITE,   COLOR_BLUE);
    init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
    init_pair(13, COLOR_BLACK,   COLOR_CYAN);
}

void    line(void)
{
    int h = COLS;
    while (--h >= 0)
    {
        int w = LINES;
        while (--w >= 0)
        {
            color_set(3, NULL);
            if (h == COLS - (COLS / 4))
                mvprintw(w, h, "|");
        }
    }
}

int
main(void) {
    Part1 one;
    struct utsname osInfo = one.osInfo;
    mlx(one);
    initscr();
    cbreak();
    nodelay(stdscr, true);
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    initColor();
    color_set(1, NULL);
    refresh();
    int ch = 1;
    while (ch)
    {
        line();
        one.updateAll();
        color_set(6, NULL);
        mvaddstr((LINES/3) - 1, COLS - (COLS / 4) + strlen("User info") - 4, "User info");
        color_set(3, NULL);
        mvaddstr((LINES/3) + 1, COLS - (COLS / 4) + strlen(one.username.c_str()), one.username.c_str());
        mvaddstr((LINES/3) + 2, COLS - (COLS / 4) + strlen(one.hostname.c_str()) - 9, one.hostname.c_str());

        color_set(1, NULL);
        mvaddstr((LINES/3) + 4, COLS - (COLS / 4) + strlen("OS INFO") - 2, "OS INFO");
        color_set(2, NULL);
        mvaddstr((LINES/3) + 6, COLS - (COLS / 4) + strlen(osInfo.sysname), osInfo.sysname);
        mvaddstr((LINES/3) + 7, COLS - (COLS / 4) + strlen(osInfo.release), osInfo.release);
        mvaddstr((LINES/3) + 8, COLS - (COLS / 4) + strlen(osInfo.machine), osInfo.machine);

        color_set(1, NULL);
        mvaddstr((LINES/3) + 10, COLS - (COLS / 4) + strlen("Memory info") - 6, "Memory info");

        color_set(3, NULL);
        mvaddstr((LINES/3) + 12, COLS - (COLS / 4) + strlen("USED:") + 1, "USED:");

        color_set(1, NULL);
        mvaddstr((LINES/3) + 13, COLS - (COLS / 4) + strlen(one.usedRamStr.c_str()) + 3, one.usedRamStr.c_str());

        color_set(3, NULL);
        mvaddstr((LINES/3) + 14, COLS - (COLS / 4) + strlen("FREE:") + 1, "FREE:");

        color_set(2, NULL);
        mvaddstr((LINES/3) + 15, COLS - (COLS / 4) + strlen(one.freeRamStr.c_str()) + 4, one.freeRamStr.c_str());

        color_set(5, NULL);
        mvaddstr((LINES/3) + 17, COLS - (COLS / 4) + strlen("CPU:") + 1, "CPU");

        color_set(5, NULL);
        mvprintw((LINES/3) + 19, COLS - (COLS / 4) + 7, "%s", one.cpuName.c_str());

        color_set(5, NULL);
        mvprintw((LINES/3) + 20, COLS - (COLS / 4) + 7, "%s", one.cpuCores.c_str());

        color_set(5, NULL);
        mvprintw((LINES/3) + 21, COLS - (COLS / 4) + 7, "%.1f%c", one.cpuUsage, '%');

        color_set(3, NULL);
        mvaddstr((LINES/3) + 23, COLS - (COLS / 4) + strlen("Time:") + 1, "Time");

        color_set(2, NULL);
        mvaddstr((LINES/3) + 24, COLS - (COLS / 4) + strlen(one.timeNow.c_str()) - 17, one.timeNow.c_str());

        refresh();
        ch = getch();
        if (ch == 'q')
            break;
        clear();
        usleep(500000);
    }

    endwin();


    std::cout << one.hostname + " " <<  one.username << std::endl;
    std::cout << osInfo.sysname << std::endl;
    std::cout << osInfo.nodename << std::endl;
    std::cout << osInfo.release << std::endl;
    std::cout << osInfo.version << std::endl;
    std::cout << osInfo.machine << std::endl;
	std::cout << one.usedRam << std::endl;
	std::cout << one.freeRam << std::endl;
    std::cout << one.cpuUsage << std::endl;

}
