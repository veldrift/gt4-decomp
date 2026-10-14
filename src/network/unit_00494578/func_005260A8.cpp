/* compiler: ee-gcc2.96-as2004 */
typedef int s32;
typedef unsigned short u16;
struct E { s32 f0; char p[0x40]; };
struct Obj { char p[0x84]; E *f84; char p88[0x14]; u16 f9C; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" s32 func_005260A8(Obj *o) {
    if (o == 0) return 0xFFFE;
    u16 i = 0;
    E *e = o->f84;
    if (o->f9C != 0) {
        do {
            if (e->f0 == 0) {
                func_005A48D8(e, 0, 0x44);
                return i;
            }
            i++;
            e++;
        } while (i < o->f9C);
    }
    return 0xFFFE;
}
