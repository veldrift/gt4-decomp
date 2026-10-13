extern "C" {
typedef int s32;

s32 func_0052FA88(void);
s32 func_0053A860(void *);
s32 func_0053A890(void *, s32 *);
void func_00578B10(s32);
}

extern "C" void func_004F09A8(s32 arg0, s32 arg1) {
    s32 buf[4];
    s32 sp10;

    sp10 = 0;
    func_0053A860(buf);
    if (sp10 < arg1) {
        do {
            func_0052FA88();
            func_00578B10(0x2710);
            func_0053A890(buf, &sp10);
        } while (sp10 < arg1);
    }
}
