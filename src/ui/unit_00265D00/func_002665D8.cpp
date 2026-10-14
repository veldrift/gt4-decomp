/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x98]; unsigned int low:4; unsigned int f:4; unsigned int rest:24; };
extern "C" void func_002665D8(Obj *self,int mask,int enabled) {
    if(enabled) self->f |= mask;
    else self->f &= ~mask;
}
