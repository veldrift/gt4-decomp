typedef int s32;
typedef float f32;

extern "C" void func_003B0230(void *a0);
extern "C" s32 func_00472680(void *a0);
extern "C" s32 func_005A5DC8(void *a0, s32 a1);
extern "C" void func_003A5268(void *a0, const char *a1, s32 a2);
extern "C" void RaceEventDisplay__addEvent(char *self, const char *text, f32 delta, f32 value, f32 a, f32 b);

extern char PDISTD__UNIT_MANAGER[];
extern char D_006A0470[];

extern "C" void func_003A12A0(void *arg0) {
    char buf[0x20];
    char *s0;

    func_003B0230(buf);
    s0 = (char *)arg0 + 0x17BC;
    func_005A5DC8(buf, func_00472680(PDISTD__UNIT_MANAGER));
    *(s32 *)(s0 + 0x20) = (s32)0x80C8C8C8;
    func_003A5268(s0, D_006A0470, 0);
    RaceEventDisplay__addEvent(s0, buf, 3.0f, 0.0f, 0.1499999910593033f, 0.1499999910593033f);
}
