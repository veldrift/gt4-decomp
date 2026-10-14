typedef unsigned char u8;
typedef unsigned int u32;
struct Time { int ms, sec, min, hour, day, month, year, pad, tick; };
extern Time D_0086B418;
extern "C" int func_005492C8(void *);
extern "C" void func_0058D480(void *);
extern "C" int func_0053A7D0(void *) throw();
extern "C" int func_0053AE58() {
    u8 clock[8];
    func_005492C8(clock);
    func_0058D480(clock);
    int sec = (clock[1] >> 4) * 10 + (clock[1] & 15);
    int min = (clock[2] >> 4) * 10 + (clock[2] & 15);
    int hour = (clock[3] >> 4) * 10 + (clock[3] & 15);
    int day = (clock[5] >> 4) * 10 + (clock[5] & 15);
    int month = (clock[6] >> 4) * 10 + (clock[6] & 15);
    int year = (clock[7] >> 4) * 10 + (clock[7] & 15);
    Time *p = &D_0086B418;
    p->sec = sec;
    p->min = min;
    p->hour = hour;
    p->day = day;
    p->month = month;
    p->year = year;
    p->ms = 0;
    return func_0053A7D0(&p->tick) == 0 ? 0 : 0x640;
}
