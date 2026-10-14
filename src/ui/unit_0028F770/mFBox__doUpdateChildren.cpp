/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Rect { char pad[8]; f32 x; f32 y; };
extern "C" {
f32 func_00200EA8(void *);
f32 func_00200EB8(void *);
f32 func_00200EC8(void *);
f32 func_00200ED8(void *);
void *func_00206868(void *);
void func_00207208(void *, void *, void *);
s32 func_002073D8(void *, void *);
Rect *func_0025BF60(void *);
void *func_0025C300(void *);
void func_00263B80(void *, f32 *, f32 *);
void mFBox__doUpdateChildren(void *arg0, void *arg1) {
    f32 sp[2];
    void *s0 = func_00206868(arg0);
    f32 mx = 0.0f;
    f32 my = 0.0f;
    if (s0 != 0) {
        do {
            func_00207208(arg0, arg1, s0);
            if (func_002073D8(arg0, s0) != 0) {
                func_00263B80(s0, &sp[0], &sp[1]);
                if (my < sp[0]) my = sp[0];
                if (mx < sp[1]) mx = sp[1];
            }
            s0 = func_0025C300(s0);
        } while (s0 != 0);
    }
    f32 a = func_00200EA8(arg0);
    f32 b = func_00200EB8(arg0);
    f32 c = func_00200EC8(arg0);
    f32 d = func_00200ED8(arg0);
    Rect *r = func_0025BF60(arg0);
    r->x = my + (a + b);
    r->y = mx + (c + d);
}
}
