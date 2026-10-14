typedef int s32;

struct RefCounter;

extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001DC5F8(void *arg0, s32 arg1);
extern "C" void func_00227110(void *arg0, s32 arg1);
extern "C" void func_00227128(void *arg0, s32 arg1);
extern "C" void func_003285A8(struct RefCounter *p);
extern "C" void func_003285F8(struct RefCounter *p);

extern "C" void MNetwork__imOpen(s32 *arg0, s32 arg1) {
    s32 buf[4];
    s32 sp10;
    s32 *p10;
    s32 newVal;
    s32 oldVal;
    func_001DC650(buf, (void *)arg1);
    *(s32 *)((char *)buf[0] + 0x1C8) = 1;
    func_001DC5F8(buf, 2);
    p10 = &sp10;
    func_001DC650(p10, (void *)arg1);
    func_00227110(buf, *p10 + 0x1C4);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((struct RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((struct RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_00227128(buf, 2);
    func_001DC5F8(p10, 2);
}
