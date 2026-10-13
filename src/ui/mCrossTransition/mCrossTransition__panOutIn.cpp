struct CTA {
    char pad0[0x20];
    int unk20;
    union { float f; int i; } unk24;
    union { float f; int i; } unk28;
    char pad2C[0x10];
    int unk3C;
};

struct CTB {
    char pad0[4];
    char *vtbl;
    char pad8[0x6D8];
    int unk6E0;
};

struct CTVEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

extern "C" void func_0024D1E8(void *arg0);
extern "C" void func_00215298(int arg0);

extern "C" void func_0028A528(void *arg0, void *arg1) {
    struct CTA *a = (struct CTA *)arg0;
    struct CTB *b = (struct CTB *)arg1;

    func_0024D1E8(arg0);

    int flag = a->unk20;
    a->unk24.f = 1.0f;
    a->unk28.f = 0x1.999998p-4f;
    a->unk3C = 0;

    if (flag == 0) {
        int old = b->unk6E0;
        b->unk6E0 = 1;
        func_00215298(2);
        CTVEntry *e = (CTVEntry *)(b->vtbl + 0x228);
        e->fn((char *)b + e->delta);
        func_00215298(1);
        b->unk6E0 = old;
    }
}
