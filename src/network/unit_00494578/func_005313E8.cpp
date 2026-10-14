struct VA { char pad[0x20]; int (*f20)(int, int *, int *, int *, int *); };
struct VB { char pad[0x3C]; int (*f3C)(int, int *, int *, int *, int *); };
struct O {
    char pad[0x158];
    int m158;
    char pad2[4];
    int m160;
    int m164;
};
extern "C" VA *D_0064B4B8;
extern "C" VB *D_0064B4A8;
extern "C" int func_00535780(int);

extern "C" int func_005313E8(O *o, int *p0, int *p1, int *p2, int *p3) {
    int s[4];
    if (o->m158 == 2) {
        if (D_0064B4B8->f20(o->m164, &s[0], &s[1], &s[2], &s[3]) != 0) {
            return 0x25;
        }
    } else {
        int r = func_00535780(D_0064B4A8->f3C(o->m160, &s[0], &s[1], &s[2], &s[3]));
        if (r != 0) {
            return r;
        }
    }
    if (p0 != 0) *p0 = s[0];
    if (p1 != 0) *p1 = s[1];
    if (p2 != 0) *p2 = s[2];
    if (p3 != 0) *p3 = s[3];
    return 0;
}
