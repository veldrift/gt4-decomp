extern "C" int func_00535780(int);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);
struct Callbacks { char pad[0x6C]; int (*call)(int,int,int,int,int,int); };
extern Callbacks *D_0064B4B4;
extern "C" int func_005156B0(int a, int b, int c, int d, int e, int f) {
    int r = func_00535780(func_00536CF8());
    if (r == 0) {
        int value = D_0064B4B4->call(a,b,c,d,e,f);
        int status = func_00535780(func_00536D38());
        r = status == 0 ? value : status;
    }
    return r;
}
