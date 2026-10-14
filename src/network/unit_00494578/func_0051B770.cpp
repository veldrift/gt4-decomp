struct Table { char pad[0x130]; int a[16]; int b[16]; int c[16]; };
struct Obj { char pad[8]; Table table; };
extern Obj *D_0064B4B4;
extern "C" int func_0051B770(unsigned int i, int a, int b, int c) {
    if (i >= 16) return 23;
    D_0064B4B4->table.a[i] = a;
    D_0064B4B4->table.b[i] = b;
    D_0064B4B4->table.c[i] = c;
    return 0;
}
