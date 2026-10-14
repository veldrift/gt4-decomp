struct Obj { int a,b; int handle; int status; char pad[0xc]; int value; };
extern "C" int func_005220F8(Obj *);
extern "C" int func_005232D0(int, int *);
extern "C" int func_005216D8(Obj *self, int *out) {
    if (func_005220F8(self) == 0) return 2;
    if (self->status != 0) return 0xc355;
    int cached = self->value;
    if (cached == 0) {
        int *value = &self->value;
        int result = func_005232D0(self->handle, value);
        if (result != 0) return result;
        cached = *value;
    }
    *out = cached;
    return 0;
}
