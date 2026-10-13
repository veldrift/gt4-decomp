typedef int s32;

extern "C" s32 func_003A1E10(const char *name);

extern "C" char D_006244D8[];
extern "C" char D_006A1650[];
extern "C" char D_006A1668[];
extern "C" char D_006A1680[];
extern "C" char D_006A1690[];

struct RacePriusPanel_arg0 {
    char pad0[0x10];
    s32 m10;
    char pad14[0x238];
    s32 m24C;
    s32 m250;
};

extern "C" void func_003A9E80(struct RacePriusPanel_arg0 *o) {
    char *name;

    if (o->m10 == 0) {
        if (*(s32 *)D_006244D8 == 1) {
            name = D_006A1650;
        } else {
            name = D_006A1668;
        }
        o->m10 = func_003A1E10(name);
        o->m24C = func_003A1E10(D_006A1680);
        o->m250 = func_003A1E10(D_006A1690);
    }
}
