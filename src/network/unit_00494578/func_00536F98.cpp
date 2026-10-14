/* compiler: ee-gcc2.96-as2004 */
typedef int s32;
typedef unsigned long long T __attribute__((aligned(4)));
struct Dst { char slots[0x100]; s32 f100; s32 f104; };
struct Src { T t[16]; s32 f80; s32 f84; };
struct Vt { char pad0[0x7C]; void (*f7C)(void *, T); };
extern Vt *D_0064B4B0;
extern Dst D_00868590;
extern void (*D_0064B500)(void *);
extern "C" s32 func_00535780(s32) throw();
extern "C" void func_00536F98(Src *arg0) {
    s32 i;
    char *d = D_00868590.slots;
    for (i = 0xF; i >= 0; i--) {
        D_0064B4B0->f7C(d, arg0->t[0xF - i]);
        d += 0x10;
    }
    s32 t = arg0->f80;
    s32 u = arg0->f84;
    D_00868590.f100 = t;
    D_00868590.f104 = func_00535780(u);
    D_0064B500(&D_00868590);
    D_0064B500 = 0;
}
