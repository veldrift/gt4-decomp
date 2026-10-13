typedef int s32;

struct Elem {
    char pad0[0xC];
    s32 unkC;
    s32 pad10;
    s32 pad14;
};

extern "C" void func_005595C8(char *arg0, s32 arg1) {
    s32 d;
    s32 v;
    s32 k;
    char *b12 = arg0 + 0xC;

    d = (s32)arg0 - *(s32 *)(arg0 + 0x4);
    v = *(s32 *)(arg0 + 0x14) + d;
    *(s32 *)(arg0 + 0x4) = (s32)arg0;
    *(s32 *)(arg0 + 0x14) = v;

    {
        s32 *a2 = (s32 *)(arg0 + 0x1C);
        s32 *v1 = a2;
        for (k = 0; k < 2; k++) {
            s32 w = *v1;
            v1 += 2;
            if (w != 0) {
                *a2 += d;
            }
            a2 += 2;
        }
    }

    if (arg1 != 0) {
        s32 old = *(s32 *)(arg0 + 0xC);
        s32 dd;
        s32 off = 0x10;
        *(s32 *)(arg0 + 0xC) = arg1;
        arg0 += 8;
        dd = arg1 - old;
        for (k = 0; k < 2; k++) {
            s32 cnt = *(s32 *)(arg0 + off);
            Elem *e = *(Elem **)(b12 + off);
            if (cnt > 0) {
                s32 c = cnt;
                do {
                    c--;
                    e->unkC += dd;
                    e = (Elem *)((char *)e + 0x10);
                } while (c != 0);
            }
            off += 8;
        }
    }
}
