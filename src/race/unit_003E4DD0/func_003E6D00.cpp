typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad0[8];
    u16 count;
    char pad1[6];
    s32 f10;
    s32 ptr14;
    s32 f18;
    s32 f1C;
};

extern "C" void func_003E6CE0(int *arg0, int arg1);

extern "C" void func_003E6D00(Obj *arg0, s32 arg1)
{
    s32 s2 = arg1;

    {
        s32 *h = (s32 *)((char *)arg0 + 0x14);
        if (*h != 0) {
            *h = *h + s2;
        }
    }

    {
        s32 *h = (s32 *)((char *)arg0 + 0x18);
        if (*h != 0) {
            *h = *h + s2;
        }
    }

    {
        s32 *h = (s32 *)((char *)arg0 + 0x1C);
        if (*h != 0) {
            *h = *h + s2;
        }
    }

    {
        s32 *h = (s32 *)((char *)arg0 + 0x10);
        if (*h != 0) {
            *h = *h + s2;
        }
    }

    s32 s1 = 0;

    if (arg0->count != 0) {
        do {
            s1 += 1;
            func_003E6CE0((int *)arg0->ptr14, s2);
        } while (s1 < (s32)arg0->count);
    }
}
