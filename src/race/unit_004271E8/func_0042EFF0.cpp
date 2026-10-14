/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result {
    short a;
    union { short word; unsigned char byte[2]; } u;
};
struct Obj { char pad[0xB6C0]; int value; };
extern "C" Result func_00579898(int);
extern "C" void func_0042EFF0(Obj *self, int *a, int *b, int *c) {
    Result v = func_00579898(self->value);
    *a = v.a;
    *b = v.u.byte[0];
    *c = v.u.byte[1];
}
