#include "Part1.hpp"
#include "grafic.hpp"

void    initColor(void)
{
    start_color();

    init_pair(1,  COLOR_RED,     COLOR_BLACK);
    init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
    init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
    init_pair(14,  COLOR_YELLOW,  COLOR_YELLOW);
    init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
    init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6,  COLOR_CYAN,    COLOR_CYAN);
    init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
    init_pair(8,  COLOR_WHITE,   COLOR_BLACK);
    init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
    init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
    init_pair(11, COLOR_BLUE,   COLOR_BLUE);
    init_pair(12, COLOR_MAGENTA,   COLOR_MAGENTA);
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
    Grafic test;
    Grafic rams;
    Grafic netIn;
    Grafic netOut;
    int    oldx = std::atoi(one.networkInSize.c_str());
    int    oldy = std::atoi(one.networkOutSize.c_str());
    struct utsname osInfo = one.osInfo;

    uint_fast16_t maxx, maxy;
    getmaxyx(stdscr, maxy, maxx);
    rect xr = { {0, 0, 0}, {maxx , maxy, 1} };
    rect ramsxr = { {0, 0, 0}, {maxx , maxy, 1} };
    rect netInsxr = { {0, 0, 0}, {maxx , maxy, 1} };
    rect netOutsxr = { {0, 0, 0}, {maxx , maxy, 1} };
    std::vector<SpaceObject> dataSOBJ;
    test.setBounds(xr);
    netIn.setBounds(netInsxr);
    netOut.setBounds(netOutsxr);
    rams.setBounds(ramsxr);

    initscr();
    cbreak();
    nodelay(stdscr, true);
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    initColor();
    color_set(1, NULL);
    refresh();
    getmaxyx(stdscr, maxy, maxx);
    maxx -= COLS / 4;
    test.setBoundsUpdate(maxx, maxy);
    rams.setBoundsUpdate(maxx, maxy);
    netIn.setBoundsUpdate(maxx, maxy);
    netOut.setBoundsUpdate(maxx, maxy);
    int ch = 1;
    while (ch)
    {
        line();
        mvaddstr((LINES/3) + 15, COLS - (COLS / 4) + 8, "       ");
        dataSOBJ = test.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, ' ');
            }
        }
        dataSOBJ = rams.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, ' ');
            }
        }
        dataSOBJ = netIn.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, ' ');
            }
        }
        dataSOBJ = netOut.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, ' ');
            }
        }
        one.updateAll();
        test.update(LINES / 4, static_cast<int>(one.cpuUsage * 0.1));
        // mvprintw(7, 5, "%s", one.networkInSize.c_str());
        // mvprintw(8, 5, "%s", one.networkOutSize.c_str());
        rams.update((LINES / 4) * 2, static_cast<int>(one.usedRam / (float)8024 * 10));
        int height = 1;
        int diff = std::atoi(one.networkInSize.c_str());
        if (diff - oldx >= 10)
            height = 10;
        else if (diff != oldx)
            height = diff - oldx;
        else
            height = 1;
        netIn.update((LINES / 4) * 3, height);
        height = 1;
        diff = std::atoi(one.networkOutSize.c_str());
        if (diff - oldy >= 10)
            height = 10;
        else if (diff != oldy)
            height = diff - oldy;
        else
            height = 1;
        netOut.update((LINES / 4) * 4, height);
        color_set(14, NULL);
        dataSOBJ = test.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, '*');
            }
        }
        color_set(12, NULL);
        dataSOBJ = rams.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, '*');
            }
        }

        // NETWORK

        color_set(11, NULL);
        dataSOBJ = netIn.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, '*');
            }
        }

        color_set(6, NULL);
        dataSOBJ = netOut.getData();
        for (int i = 0; i < test.getSize(); ++i)
        {
            int height = dataSOBJ[i].getPos().height;
            while(height-- >= 0)
            {
                mvaddch(dataSOBJ[i].getPos().y - height, dataSOBJ[i].getPos().x, '*');
            }
        }
        oldx = std::atoi(one.networkInSize.c_str());
        oldy = std::atoi(one.networkOutSize.c_str());

        color_set(14, NULL);
        mvaddstr((LINES/3) - 8, COLS - (COLS / 4) + 4, "*");
        color_set(8, NULL);
        mvaddstr((LINES/3) - 8, COLS - (COLS / 4) + 6, " - Cpu usage");
        color_set(12, NULL);
        mvaddstr((LINES/3) - 7, COLS - (COLS / 4) + 4, "*");
        color_set(8, NULL);
        mvaddstr((LINES/3) - 7, COLS - (COLS / 4) + 6, " - Ram usage");
        color_set(11, NULL);
        mvaddstr((LINES/3) - 6, COLS - (COLS / 4) + 4, "*");
        color_set(8, NULL);
        mvaddstr((LINES/3) - 6, COLS - (COLS / 4) + 6, " - Network in");
        color_set(6, NULL);
        mvaddstr((LINES/3) - 5, COLS - (COLS / 4) + 4, "*");
        color_set(8, NULL);
        mvaddstr((LINES/3) - 5, COLS - (COLS / 4) + 6, " - Network out");

        color_set(1, NULL);
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
        mvprintw((LINES/3) + 20, COLS - (COLS / 4) + 7, "%s %s", "NCore:", one.cpuCores.c_str());

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
        refresh();
        usleep(100000);
        clear();
    }

    endwin();

}
