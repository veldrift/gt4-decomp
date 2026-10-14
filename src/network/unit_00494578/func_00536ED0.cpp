struct Obj { char pad[0x24]; int (*f24)(int, int, int *, int *, int *, int *); };
struct A { char pad[0x158]; int f158; char pad2[8]; int f164; };
extern Obj *D_0064B4B8;
extern "C" int func_00536ED0(A *a, int h, int *o0, int *o1, int *o2, int *o3) {
    int sp[4];
    int r;
    if (a->f158 == 2) {
        r = D_0064B4B8->f24(a->f164, h & 0xFFFF, &sp[0], &sp[1], &sp[2], &sp[3]);
        if (r == 0) goto success;
        return 0x25;
    }
    return 0xF;
success:
        if (o0 != 0) *o0 = sp[0];
        if (o2 != 0) *o2 = sp[2];
        if (o1 != 0) *o1 = sp[1];
        if (o3 != 0) *o3 = sp[3];
    return r;
}
