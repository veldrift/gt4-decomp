/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
struct In { char pad0[1]; u8 f1; char pad2[0x14 - 2]; u8 tab[1]; };
struct Base { char pad[0x90]; s8 f90[1]; };
struct O { Base *f0; u8 f4; };
extern "C" In *func_00359510(void *) throw();
extern "C" s8 func_00364FE0(O *o, int idx, s8 *a, s8 *b) {
    s8 r = 0;
    if (o->f4 != 0) return r;
    In *p = func_00359510((char *)o->f0 + 0x600);
    u8 k = 0;
    if (idx < p->f1) k = p->tab[idx];
    *a = -100;
    *b = 100;
    return o->f0->f90[k];
}
