/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot {
    int m0;
    int m4;
};
struct Rec {
    char c0;
    char pad1[3];
    short s4;
    short s6;
};
struct O {
    char pad[0x20];
    Slot slot[1];
};
extern "C" void func_004B4CC0(O *, Rec *, char *, int) throw();
extern "C" void func_004B4F28(O *) throw();
extern "C" Rec *func_004B5CC0(O *) throw();
extern "C" void func_004B5E00(O *, Rec *, char *, int) throw();

extern "C" int func_004B7C20(O *o) {
    if (*(int *)((char *)o + 0x860) != 0) {
        return 1;
    }
    Slot *s = (Slot *)((char *)o + (1 - *(int *)((char *)o + 0x858)) * 0x41C + 0x20);
    char buf[0x200];
    switch (s->m0) {
    case 0:
        return 0;
    case 1:
        s->m4 = 1;
        func_004B4F28(o);
        s->m0 = 2;
        return 1;
    case 2: {
        Rec *p = func_004B5CC0(o);
        func_004B4CC0(o, p, buf, 0x100);
        func_004B5E00(o, p, buf, p->s6 - p->s4);
        p->c0 = 4;
        return 1;
    }
    default:
        return 1;
    }
}
