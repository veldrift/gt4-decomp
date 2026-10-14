typedef int s32;
typedef void (*Fn)(s32, s32);
struct G { char pad[0x1C]; s32 *p1c; };
extern G *D_00618304;
extern "C" {
void func_00103950(s32, s32);
void func_001039C8(s32, s32);
void func_005ADF20(s32);
}
extern "C" void func_00103A40(char *self) {
    s32 pass = 0;
    s32 base = *D_00618304->p1c;
    do {
        s32 q = *(s32 *)(self + 0x68);
        Fn fn = func_00103950;
        if (pass != 0) {
            q += 0x78000;
            fn = func_001039C8;
        }
        s32 p = base;
        s32 y = 0;
        do {
            s32 qq = q;
            s32 j;
            for (j = 0x200; j >= 0; j -= 0x80) {
                s32 pp = p;
                p += 0x2000;
                s32 q2 = qq;
                qq += 0x180;
                fn(pp, q2);
            }
            y += 0x40;
            q += 0xF000;
        } while (y < 0x200);
        pass++;
    } while (pass < 2);
    func_005ADF20(0);
}
