/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x98]; unsigned int low:8; unsigned int f:4; unsigned int rest:20; };
extern "C" void func_00266640(Obj *self,int mask,int enabled) {
    if(enabled) self->f |= mask;
    else self->f &= ~mask;
}
