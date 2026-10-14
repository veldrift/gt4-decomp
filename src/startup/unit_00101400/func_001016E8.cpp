/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VObj;
struct VEntry { short delta; short index; void (*fn)(void *); };
struct VObj {
    char pad[0x5C];
    s32 f5C;
    char pad60[4];
    char *vt;
};
extern "C" void func_00101400(void) throw();
extern "C" void func_00101430(void);
extern "C" void func_001015B8(void) throw();
extern "C" void func_00107730(void);
extern "C" void func_00107768(void);
extern "C" void func_00107788(void);
extern "C" void func_001077F8(void);
extern "C" void func_00107840(void);
extern "C" s32 func_00107878(s32);
extern "C" void func_004A0690(void);
extern "C" void func_004A06F0(void);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00578B10(s32);
extern char D_006D67B0[];
extern VObj *D_00617D40;
extern VObj *D_00617D44;
extern s32 D_00617D48;
extern volatile s32 D_00617D84;

extern "C" void func_001016E8(void) {
    s32 v = 0;
    func_00107730();
    func_00107788();
    if (D_00617D84 == 0) {
        do {
            func_004A0690();
            func_001077F8();
            if (v != 0) func_00578B10(1000);
            func_00101400();
            func_00107840();
            func_004A06F0();
            func_00101430();
            func_001015B8();
            func_00576788(D_006D67B0);
            if (D_00617D48 != 0) {
                VObj *a = D_00617D40;
                if (a != 0 && a->f5C == 0) {
                    VEntry *e = (VEntry *)(a->vt + 0x48);
                    e->fn((char *)a + e->delta);
                }
                VObj *b = D_00617D44;
                if (b != 0) {
                    VEntry *e = (VEntry *)(b->vt + 0x10);
                    e->fn((char *)b + e->delta);
                }
                D_00617D40 = D_00617D44;
                D_00617D44 = 0;
                D_00617D48 = 0;
            }
            func_005767C0(D_006D67B0);
            v = func_00107878(D_00617D84);
        } while (D_00617D84 == 0);
    }
    func_00107768();
}
