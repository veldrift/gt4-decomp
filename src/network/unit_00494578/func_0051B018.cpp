typedef unsigned int u32;
typedef unsigned short u16;
struct Node {
    char pad[0x1C];
    u32 f1C;
};
struct Ent {
    char pad[8];
    int f8;
    char padC[4];
    int f10;
};
struct Obj {
    char pad[0x104];
    u32 id;
};
struct Cfg {
    char pad[0x5C];
    int w5C;
};
struct Pk {
    int w;
    u16 a;
    u16 b;
};
extern Cfg *D_0064B47C;
extern "C" int func_00515F98(u32 *, Obj *) throw();
extern "C" int func_0051A4E8(u32) throw();
extern "C" int func_0051AF08(int) throw();
extern "C" int func_0051B8A8(Obj *, u32);
extern "C" Ent *func_0051B968(Obj *, u32);
extern "C" int func_00532588(Obj *, u32, int, int, void *);
extern "C" void func_00534B90(u32);
extern "C" Node *func_00535C88(Obj *, u32);

extern "C" void func_0051B018(Obj *arg0, u32 arg1, int arg2, int arg3) {
    Pk pk;
    u32 id;
    u32 val;
    if (arg0 != 0 && arg1 < 0x40) {
        func_00515F98(&id, arg0);
        if (id != 0x100 && (id < 0x40 && func_00535C88(arg0, arg1) != 0 && arg0->id == id &&
            func_0051B8A8(arg0, arg1) == 0)) {
            Ent *e = func_0051B968(arg0, arg1);
            if (e != 0) {
                if (arg2 != 0) e->f8 = func_0051AF08(arg2) & 0xFFFF;
                if (arg3 != 0) e->f10 = func_0051A4E8(arg3) & 0xFFFF;
                u32 mx = 0;
                u32 i = 0;
                Node *n;
                pk.w = D_0064B47C->w5C;
                pk.a = e->f8;
                pk.b = e->f10;
                func_00532588(arg0, arg1, 9, 8, &pk);
                do {
                    n = func_00535C88(arg0, i);
                    i++;
                    if (n != 0) {
                        u32 v = n->f1C;
                        mx = mx < v ? v : mx;
                    }
                } while (i < 0x40);
                mx = mx + 1;
                mx = mx > 0x0FFFFFFE ? 1 : mx;
                val = mx;
                n = func_00535C88(arg0, arg1);
                if (n != 0) n->f1C = val;
                func_00532588(arg0, arg1, 0x17, 4, &val);
                func_00534B90(arg1);
                func_00534B90(arg1);
                func_00534B90(arg1);
            }
        }
    }
}
