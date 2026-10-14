/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct V4 { float x, y, z, w; };
struct V2 { float x, y; };
struct Wd { s32 a; char pad[0x38]; };
struct Obj {
    char pad0[0x30];
    V2 pos;
    char pad38[8];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
};

extern Wd D_0061850C[];
extern s32 D_00618428;
extern V4 D_006DE938;

extern "C" void func_00102EC0(V4 *arg0) throw();
extern "C" void func_00103FE8(s32 arg0) throw();
extern "C" void func_001059F8(Wd *wd, int b, int a);
extern "C" s32 func_004A7C60(void);

extern "C" void func_00104B68(Obj *o) {
    s32 s = o->f48;
    if (s < 2) {
        if (s == 0 && func_004A7C60() != 4) {
            return;
        }
        func_001059F8(&D_0061850C[1 - D_0061850C[2].a], o->f48 != 0 ? o->f4C + 0x78000 : o->f4C, 1);
        o->f48++;
    } else if (s < 3) {
        V2 *p = &o->pos;
        p->y = 0.0f;
        p->x = 1.0f;
        func_00103FE8(o->f4C);
        o->f48++;
    } else if (D_00618428 != 0) {
        if (o->f40 == 0) {
            o->f44 = 0;
            o->f40 = 1;
        }
        V4 v = D_006DE938;
        v.w = o->pos.y;
        func_00102EC0(&v);
    }
}
