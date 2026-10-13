typedef int s32;
typedef short s16;
typedef unsigned short u16;

struct S {
    char pad[0xB0];
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(S *, char *);
};

extern s32 D_00617D7C;
extern s32 D_00617D4C;
extern s32 D_00617D50;
extern u16 D_00617D58[];
extern s32 D_00617CB0;
extern s32 D_00621320;
extern char D_0064C7D0[];

extern "C" void *func_0055F1E0(S *arg0);
extern "C" int func_0055F048(void *dev, int reg);

extern "C" void func_001015B8(void) {
    S buf;
    VEntry *e = (VEntry *)(*(char **)D_0064C7D0 + 0x10);
    e->fn(&buf, D_0064C7D0 + e->delta);

    s32 v = func_0055F048(func_0055F1E0(&buf), 0);
    s32 prev = D_00617D7C;
    s32 a1 = (prev ^ v) & v;

    if (D_00617D4C == 0) {
        s32 a2 = D_00617D50;
        if (D_00617D58[a2] == 0) {
            D_00617D50 = 0;
            D_00617D4C = 1;
        } else if (a1 != 0) {
            if (a1 == D_00617D58[a2]) {
                D_00617D50 = a2 + 1;
            } else {
                D_00617D50 = 0;
            }
        }
    } else {
        D_00617CB0 = 0;
        if (v == 0x1000) {
            D_00617CB0 = 1;
        }
        switch (a1) {
        default:
            break;
        case 1:
            D_00617D4C = 0;
            D_00617CB0 = 0;
            break;
        case 0x400:
            D_00621320 ^= 1;
            break;
        }
    }
    D_00617D7C = v;
}
