typedef int s32;

extern "C" void func_00255088(void *arg0, s32 *arg1);
extern "C" void func_002550B8(void *arg0, s32 arg1);
extern "C" void func_00255110(void *arg0, s32 *arg1);
extern "C" void func_003285A8(s32 obj);
extern "C" void func_003285F8(s32 obj);

extern "C" void func_001C3058(void *arg0, s32 *arg1)
{
    s32 buf[4];
    s32 tmp;
    s32 *ret = (s32 *)((char *)arg0 + 0x2DC);

    if (*arg1 == 0) {
        tmp = 0;
        func_00255088(buf, &tmp);
    } else {
        func_00255110(buf, arg1);
    }
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_003285A8(obj);
        s32 old = *ret;
        if (old != 0)
            func_003285F8(old);
        *ret = obj;
    }
    func_002550B8(buf, 2);
}
