/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

struct B { char pad[8]; s32 *arr; };
struct A { char pad[0x60]; B *b; };
struct E { char pad[0x1198]; u32 v; };
extern "C" s32 func_0034C190(void *, s32);
extern "C" void DynamicsConductorBattle2P__virtual_26(void);
extern "C" s32 func_0035E3C8(char *, u32);

extern "C" void DynamicsConductorFreePractice__virtual_26(char *arg0) {
    s32 i = 0;
    DynamicsConductorBattle2P__virtual_26();
    A *a = *(A **)arg0;
    if (*(s32 *)(arg0 + 0xF8A0) > 0) {
        do {
            s32 r = func_0034C190(arg0, i);
            s32 *arr = a->b->arr;
            E *e = (E *)arr[i];
            i++;
            func_0035E3C8((char *)r, e->v);
        } while (i < *(s32 *)(arg0 + 0xF8A0));
    }
    *(s8 *)(arg0 + 0xCBE5) = 1;
}
