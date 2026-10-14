/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U __attribute__((aligned(4)));
typedef unsigned char u8;
struct Src { int a; U b; int c; };
struct Obj { char pad[0x7C]; int (*f7C)(void *, U); };
extern Src D_00868698[2];
extern Obj *D_0064B4B0;
extern "C" void func_00530EB8(char *d) {
    Src *s = D_00868698;
    int *pc = (int *)(d + 0x14);
    unsigned i = 0;
    int off = 0;
    do {
        char *e = d + off;
        int a = s->a;
        int c = s->c;
        *(int *)e = a;
        *pc = c;
        off += 0x18;
        pc = (int *)((char *)pc + 0x18);
        if (D_0064B4B0 != 0) {
            D_0064B4B0->f7C(e + 4, s->b);
        } else {
            e[4] = 0;
        }
        i++;
        s++;
    } while (i < 2);
}
