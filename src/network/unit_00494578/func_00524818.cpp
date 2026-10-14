struct E {
    int m0;
    int m4;
    int m8;
    char pad[0x44 - 0xC];
};
struct O {
    int m0;
    int slot[0x20];
    char pad84[0x84 - 0x84];
};
struct P {
    int m0;
    int slot[1];
    char pad[0x84 - 8];
    E *m84;
    char pad88[0x9C - 0x88];
    unsigned short m9C;
};
extern "C" void func_005250B8(void);
extern "C" void func_00529650(int, int);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" void func_00524818(P *p) {
    if (p == 0) {
        return;
    }
    unsigned int i = 0;
    func_005250B8();
    E *e = p->m84;
    unsigned int cnt = p->m9C;
    if (cnt != 0) {
        do {
            if (e->m0 != 0) {
                if (e->m4 != 0) {
                    func_00529650(p->m0, e->m4);
                }
                if (e->m8 != 0) {
                    func_00529650(p->m0, e->m8);
                }
                func_005A48D8(e, 0, 0x44);
                e->m4 = 0;
                e->m8 = 0;
                cnt = p->m9C;
            }
            i = (i + 1) & 0xFFFF;
            e++;
        } while (i < cnt);
    }
    i = 0;
    int *base = (int *)((char *)p + 4);
    do {
        int *s = &base[i];
        if (*s == 0) {
            func_00529650(p->m0, 0);
            *s = 0;
        }
        i = (i + 1) & 0xFFFF;
    } while (i < 0x20);
}
