struct Obj { char pad[0x4c]; int value; };
extern "C" int func_005110C0(Obj *p, int value) {
    if (p == 0 || value == 0) return 1;
    p->value = value;
    return 0;
}
