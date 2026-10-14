struct Obj { char pad[0x104]; int id; char pad108[0x48]; int count; };
struct Node { unsigned char f0; unsigned char type; };
struct Out { char flags[8]; int count; int index; };
typedef int (*Callback)(int, unsigned int);
struct Global { char pad[0x118]; Obj *cur; char pad11c[0xdc]; Callback cb[1]; };
extern Global D_00854038;
extern "C" Node *func_00515DD8(unsigned int) throw();
extern "C" int func_0051B8A8(Obj *, unsigned int);
extern "C" void func_00531E60(Out *, int);
extern "C" void func_005173E8(Out *out, unsigned int arg1) {
    Global *g = &D_00854038;
    Obj *o = g->cur;
    if (o) {
        Node *n = func_00515DD8(arg1);
        if (n) {
            Callback cb = g->cb[n->type];
            out->count = o->count;
            out->index = -1;
            for (int i = 0; i < 8; i++) out->flags[i] = 0;
            for (int i = 0; i < o->count; i++) {
                if (func_0051B8A8(o, i) && i != o->id && cb(i, arg1))
                    func_00531E60(out, i);
            }
        }
    }
}
