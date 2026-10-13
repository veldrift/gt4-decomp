typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct func_0046B248_obj {
    char pad0[4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    s32 unk18;
};

struct func_0046B248_elem {
    s32 count;
    f32 a;
    f32 b;
    char pad0C[0x18];
    f32 c;
    char pad28[0x18];
};

extern "C" void func_0046B248(struct func_0046B248_obj *arg0, s32 arg1) {
    u32 k;
    s32 *p;
    s32 base;

    if (arg0->unk4 == 0) {
        k = 0;
        base = arg1 + arg0->unk18;
        arg0->unk4 = arg1;
        arg0->unk18 = base;
        if (arg0->unk14 != 0) {
            p = (s32 *)base;
            do {
                s32 v1 = *p;
                if (v1 != 0) {
                    s32 q = arg0->unk4 + v1;
                    struct func_0046B248_elem *e;
                    *p = q;
                    e = (struct func_0046B248_elem *)q;
                    if (e->count == 0) {
                        *p = 0;
                    } else {
                        struct func_0046B248_elem *f = e + 1;
                        s32 c = e->count;
                        if (c > 0) {
                            do {
                                c--;
                                f->a = -f->a;
                                f->b = -f->b;
                                f->c = f->c + 0x1.921FB4p1f;
                                f++;
                            } while (c != 0);
                        }
                    }
                }
                k++;
                p++;
            } while (k < (u32)arg0->unk14);
        }
    }
}
