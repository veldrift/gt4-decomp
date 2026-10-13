typedef int s32;

struct Lst {
    char pad0[0x14];
    s32 *items;
    char pad1[0x8];
    s32 count;
};

struct Owner {
    char pad0[0x2C];
    Lst *lst;
};

extern "C" void func_0030BB18(void *a0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_0031E188(void *arg0, Owner *arg1) {
    s32 buf[4];
    Lst *s2;
    s32 *s1;

    func_0030BB18(buf);
    s2 = arg1->lst;
    s1 = &s2->items[s2->count];
    if (s1 != buf) {
        s32 v = buf[0];
        if (v != 0) {
            func_003285A8(v);
        }
        s32 old = *s1;
        if (old != 0) {
            func_003285F8(old);
        }
        *s1 = v;
    }
    s2->count = s2->count + 1;
    func_00309378(buf, 2);
}
