struct Obj { char data[0x63]; unsigned char flag; int x, y, z; unsigned short a, b, c, d, e; };
extern Obj D_0064A178;
extern "C" int func_00506540(Obj *p) {
    __builtin_memcpy(&D_0064A178, p, 100);
    D_0064A178.flag = 0;
    int x = p->x, y = p->y, z = p->z;
    D_0064A178.a = p->a;
    D_0064A178.b = p->b;
    D_0064A178.x = x;
    D_0064A178.y = y;
    D_0064A178.c = p->c;
    D_0064A178.z = z;
    D_0064A178.d = p->d;
    D_0064A178.e = p->e;
    return 0;
}
