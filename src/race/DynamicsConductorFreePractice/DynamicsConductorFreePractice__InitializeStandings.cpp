/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;

struct E { char pad[0x3444]; s32 slot; };
struct B { char pad[8]; E **arr; };
struct A { char pad[0x60]; B *b; };
struct Car { char pad[0x5B3]; s8 rank; };
struct O {
    A *p;
    char pad[0xF8A0 - 4];
    s32 n;
    s32 pos[6];
};
extern "C" Car *func_0034C190(void *, s32);

extern "C" void DynamicsConductorFreePractice__InitializeStandings(O *o) {
    s32 i;
    for (i = 5; i >= 0; i--) o->pos[i] = -1;
    for (i = 0; i < o->n; i++) {
        s32 s = o->p->b->arr[i]->slot;
        func_0034C190(o, i)->rank = s + 1;
        o->pos[s] = i;
    }
}
