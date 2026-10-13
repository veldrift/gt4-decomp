typedef int s32;

extern "C" void func_00228450(s32 *buf, s32 *val);
extern "C" void func_002284D8(s32 *buf, s32 *src);
extern "C" void func_00228480(s32 *buf, s32 flags);
extern "C" void func_003285A8(s32 obj);
extern "C" void func_003285F8(s32 obj);

extern "C" void func_001BC038(void *arg0, s32 *arg1)
{
    s32 buf[4];
    s32 val;
    s32 *slot = (s32 *)((char *)arg0 + 0xA8);

    if (*arg1 == 0) {
        val = 0;
        func_00228450(buf, &val);
    } else {
        func_002284D8(buf, arg1);
    }
    if (slot != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_003285A8(obj);
        s32 old = *slot;
        if (old != 0)
            func_003285F8(old);
        *slot = obj;
    }
    func_00228480(buf, 2);
}
