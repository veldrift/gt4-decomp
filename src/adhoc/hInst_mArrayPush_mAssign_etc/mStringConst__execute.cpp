typedef int s32;

struct RefCounter {
    s32 ref;
};

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

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void mStringConst__execute(void *arg0, Owner *arg1) {
    s32 buf0[4];
    Lst *s2;
    s32 *s1;

    func_00314B20(buf0, (char *)arg0 + 8);
    s2 = arg1->lst;
    s1 = &s2->items[s2->count];
    if (s1 != buf0) {
        s32 newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        s32 oldVal = *s1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *s1 = newVal;
    }
    s2->count = s2->count + 1;
    func_00312318(buf0, 2);
}
