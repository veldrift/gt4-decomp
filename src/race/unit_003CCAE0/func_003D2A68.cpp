/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x92A8]; int values[4]; };
extern "C" unsigned char func_003C9F90(void *) throw();
extern "C" int func_003CF820(void *) throw();
extern "C" int func_003D2998(Obj *) throw();
extern "C" int func_003D3030(Obj *);
extern "C" int func_003D2A68(Obj *self,void *obj) {
    int index=func_003C9F90(obj);
    if(self->values[index]) return 1;
    if(func_003D3030(self)) return 1;
    if(func_003D2998(self)) return func_003CF820(obj);
    return 1;
}
