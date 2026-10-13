typedef void (*FnPtr)(void);

struct Obj {
    char pad[0x38];
    FnPtr unk38;
};

extern "C" struct Obj *D_0064B4BC;

extern "C" void func_00536C10(void) {
    struct Obj *p = D_0064B4BC;
    if (p != 0) {
        p->unk38();
    }
}
