/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct V2 { f32 x, y; };
struct V3 { f32 x, y, z; };
extern V2 D_00622AA0;
extern V2 D_00622AB0;
extern V2 D_00622AC0;
extern V2 D_00622AD0;
extern V2 D_00622AE0;
extern V3 D_00622AF0;
extern V3 D_00622B00;
extern V3 D_00622B10;
extern V3 D_00622B20;
extern V3 D_00622B30;
extern V3 D_00622B40;
extern V3 D_00622B50;
static inline void set2(V2 *const p, float x, float y) { p->x=x; p->y=y; }
static inline void set3(V3 *const p, float x, float y, float z) { p->x=x; p->y=y; p->z=z; }
extern "C" void func_004218E0(int a, int b) {
    if (b == 0xFFFF && a == 1) set2(&D_00622AA0, 0,0);
    if (b == 0xFFFF && a == 1) set2(&D_00622AB0, 1,0);
    if (b == 0xFFFF && a == 1) set2(&D_00622AC0, 0,1);
    if (b == 0xFFFF && a == 1) set2(&D_00622AD0, -1,0);
    if (b == 0xFFFF && a == 1) set2(&D_00622AE0, 0,-1);
    if (b == 0xFFFF && a == 1) set3(&D_00622AF0, 0,0,0);
    if (b == 0xFFFF && a == 1) set3(&D_00622B00, 1,0,0);
    if (b == 0xFFFF && a == 1) set3(&D_00622B10, 0,1,0);
    if (b == 0xFFFF && a == 1) set3(&D_00622B20, 0,0,1);
    if (b == 0xFFFF && a == 1) set3(&D_00622B30, -1,0,0);
    if (b == 0xFFFF && a == 1) set3(&D_00622B40, 0,-1,0);
    if (b == 0xFFFF && a == 1) set3(&D_00622B50, 0,0,-1);
}
