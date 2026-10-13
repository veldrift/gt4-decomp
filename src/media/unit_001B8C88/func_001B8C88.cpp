typedef int s32;

extern "C" int func_001B9BB8(void *arg0, s32 *arg1);
extern "C" void func_001B9BE8(void *arg0, s32 arg1);
extern "C" void func_001B9C40(void *arg0, s32 *arg1);
extern "C" void func_003285A8(s32 obj);
extern "C" void func_003285F8(s32 obj);

extern "C" void func_001B8C88(void *arg0, s32 *arg1)
{
    s32 buf[4];
    s32 tmp;
    s32 *ret = (s32 *)((char *)arg0 + 0xA0);

    if (*arg1 == 0) {
        tmp = 0;
        func_001B9BB8(buf, &tmp);
    } else {
        func_001B9C40(buf, arg1);
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
    func_001B9BE8(buf, 2);
}
