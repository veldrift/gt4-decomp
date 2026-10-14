typedef long s64;
struct F0 { unsigned a : 1; };
struct F1 { long pad : 1; long x : 32; };
struct F2 { long pad : 2; long y : 32; };
struct Ent { s64 f0; s64 w; int f10; int f14; int pad[2]; };
extern "C" void func_003434A8(void *, int);
extern "C" void func_00440EC8(void *, s64);
extern "C" void func_00440F78(void *);
extern "C" int func_00441298(void *, int);

extern "C" int func_00435568(char *o, int idx, char *b) {
    Ent *e = (Ent *)(o + (idx << 5) + 8);
    if (*(int *)&e->w & 1) {
        int fx = ((F1 *)&e->w)->x;
        if ((fx & 1) == 0) {
            func_00440EC8(b, e->f0);
            func_00441298(b, ((F2 *)&e->w)->y & 0x7F);
            func_003434A8(b + 0x4A0, e->f14);
            func_00440F78(b);
            *(int *)(o - 0x7E0C + 0x10000) = 1;
            return 1;
        }
    }
    *(int *)(o - 0x7E0C + 0x10000) = 0;
    return 0;
}
