struct G { char pad[0x104]; unsigned int id; };
struct R { char pad[3]; unsigned char type; };
struct T { char pad[0xa5f8]; int flags[256]; };
extern G *D_00854150;
extern T *D_0064B4B4;
extern "C" R *func_00515EC8(unsigned int) throw();
extern "C" int func_00515F98(unsigned int *, G *) throw();
extern "C" int func_00532588(G *, unsigned int, int, int, unsigned char *);
extern "C" void func_00518540(unsigned int arg0, unsigned int arg1) {
    struct { unsigned int id; unsigned char data; } sp;
    unsigned int v = arg0;
    if (arg1 < 0x1000) {
        G *g = D_00854150;
        if (g) {
            R *r = func_00515EC8(arg1);
            if (r && func_00515F98(&sp.id, g) == 0 && sp.id < 0x40) {
                if (D_0064B4B4->flags[r->type] && g->id != sp.id) {
                    v = (~v == 0) ? sp.id : v;
                }
                sp.data = arg1;
                func_00532588(g, v, 5, 1, &sp.data);
            }
        }
    }
}
