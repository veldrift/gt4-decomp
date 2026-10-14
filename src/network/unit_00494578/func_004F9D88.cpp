/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Obj { char p0[0xCD8]; char tab[0x208]; s32 fEE0; s32 arr[0x21]; u32 fF68; };
extern "C" s32 func_004F68C8(char *);
extern "C" s32 func_004F8B28(void *, s32 *);
extern "C" void func_00576100(Obj *);
extern "C" void func_00576140(Obj *);
extern "C" void func_004F9D88(Obj *o) {
    if (func_004F68C8((char *)o)) {
        func_00576100(o);
        s32 n = func_004F8B28(o->tab, o->arr);
        o->fF68 = 0x80000000;
        o->fEE0 = n;
        for (s32 i = 0; i < n; i++) o->fF68 |= 1 << o->arr[i];
        func_00576140(o);
    }
}
