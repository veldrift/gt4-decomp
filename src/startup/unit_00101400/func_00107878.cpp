typedef int s32;
struct E { char b[0x3C]; };
struct G { E e[2]; s32 cur; };
struct T { char pad[0x28]; s32 f28; char pad2[0x3C - 0x2C]; G g1; G g2; };
extern T D_006184D0;
extern G D_0061850C;
extern s32 D_006186E0, D_006186DC, D_006186E4;
extern "C" void func_00105510(void *, s32);
extern "C" void func_00105608(char *);
extern "C" void func_00107368(void *);
extern "C" void func_00107AD8(int);
extern "C" void func_004A11F8(s32);
extern "C" void func_004A1C98(void);
extern "C" void func_004A20C8(void);
extern "C" s32 func_004A22C0(s32);
extern "C" void func_004AA4A0(void);
extern "C" s32 func_005ADB30(s32, s32);
extern "C" s32 func_005ADB90(void);

extern "C" s32 func_00107878(s32 arg0) {
    s32 r = 0;
    func_004AA4A0();
    func_004A1C98();
    func_00105510(D_0061850C.e + D_0061850C.cur, D_006186E0 ^ 1);
    s32 s2 = func_005ADB90();
    s32 s3 = func_005ADB30(s2, 1);
    func_004A20C8();
    if (D_006186DC != 0) {
        func_004A22C0(-1);
    } else {
        r = func_004A22C0(-D_006186E4) != 0;
    }
    char *b = (char *)&D_006184D0;
    func_00107368(b);
    func_00107AD8(*(s32 *)(b + 0x28) > 0);
    char *v1 = b + 0x3C;
    s32 t = 1 - *(s32 *)(v1 + 0x78);
    *(s32 *)(v1 + 0x78) = t;
    b = b + 0xB8;
    func_00105608(v1 + t * 0x3C);
    *(s32 *)(b + 0x78) = 1 - *(s32 *)(b + 0x78);
    if (arg0 == 0) func_004A11F8(0);
    func_005ADB30(s2, s3);
    return r;
}
