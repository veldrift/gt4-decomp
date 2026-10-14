typedef int s32;
extern "C" void func_00577F80(void);
extern "C" s32 func_0058C518(s32);

#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))

extern "C" void func_001C5370(void *self) {
    s32 k = (s32)0xFFFF6FC4;
    s32 r;
    for (;;) {
        r = func_0058C518(FIELD(s32, self, 0x10));
        if (r == 0) {
            break;
        }
        if (r == k) {
            break;
        }
        func_00577F80();
    }
}
