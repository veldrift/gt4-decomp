typedef int s32;
extern char D_0068CD10[];
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" s32 func_004B3E50(const char *);
extern "C" void func_004B3E90(void);

extern "C" const char *func_00108D80(s32 arg0) {
    const char *r = 0;
    if (func_0057F238("us", "jp") != 0) {
        if (func_0057F238("us", "kr") == 0) {
            if (arg0 != 0) r = "kr_menu.kf"; else r = "kr_race.kf";
        } else if (func_0057F238("us", "tw") == 0) {
            if (arg0 != 0) r = "tw_menu.kf"; else r = "tw_race.kf";
        } else if (func_0057F238("us", "uk") == 0 || func_0057F238("us", D_0068CD10) == 0) {
            if (arg0 != 0) r = "jp_menu.kf"; else r = "jp_race.kf";
        }
    } else {
        if (arg0 != 0) r = "jp_menu.kf"; else r = "jp_race.kf";
    }
    return r;
}

extern "C" void func_00108E88(void) {
    if (func_0057F238("us", "jp") == 0) func_004B3E50("/fep");
}

extern "C" void func_00108EC8(void) {
    func_004B3E90();
}
