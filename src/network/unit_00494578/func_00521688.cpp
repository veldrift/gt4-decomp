struct Obj { char pad[0x18]; int value; };
extern "C" int func_005220F8(Obj *);
extern "C" int func_00521688(Obj *self, int *out) {
    *out = 0;
    if (func_005220F8(self) == 0) return 2;
    *out = self->value;
    return 0;
}
