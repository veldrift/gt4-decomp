/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x20]; int mode; char name[16]; int value; };
extern short D_0064A164;
extern int D_008A015C, D_008A0124, D_0064A150;
extern char D_006C1138[], D_0064A148[];
extern "C" void func_00504AD8(int) throw();
extern "C" void func_00504AF8(int) throw();
extern "C" int func_00506278(void *, int);
extern "C" int func_0052EAF8(signed char,int,int,int,int,int,void *);
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" void func_005A6AB0(void *,void *,int) throw();
extern "C" int func_005051A8(Obj *o, int a, int b) {
    int result = -12;
    if (D_0064A164 == 1) {
        int mode = o->mode;
        D_008A015C = a;
        D_008A0124 = b;
        func_00504AD8(mode);
        if (o->mode == 0 || o->mode == 4) func_00504AF8(o->value);
        else o->value = 0;
        if (func_0057F238(o->name,D_006C1138) == 0 || o == (Obj *)-0x24)
            func_005A6AB0(o->name,D_0064A148,16);
        func_00506278(o,21);
        func_00506278(o->name,16);
        result = func_0052EAF8(64,D_0064A150,65535,3,3,56,o) != 0 ? -5 : 0;
    }
    return result;
}
