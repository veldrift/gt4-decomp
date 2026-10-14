/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x, y; int pad[2]; };
extern "C" void func_002A0D78(void *, void *) throw();
extern "C" void func_002A0D20(void *, int) throw();
extern "C" void func_002F7BC0(void *, void *);
extern "C" void func_002F7B68(void *, int);
extern "C" float func_002F9158(void *);
extern "C" void func_002A3800(void *, int, Vec *);
extern "C" void MImageFace__set_texcoord_bottom(void *ret, void *ctx, int n, void *args) {
    if (n > 0) {
        void *h[4];
        void *v[4];
        Vec a, b;
        func_002A0D78(h, ctx);
        void **pv = v;
        func_002F7BC0(pv, args);
        float f = func_002F9158(*pv);
        Vec *pa = &a;
        Vec *pb = &b;
        pa->x = 0.0f;
        pa->y = f;
        pb->x = 1.0f;
        pb->y = f;
        func_002A3800(*h, 3, pa);
        func_002A3800(*h, 2, pb);
        func_002F7B68(pv, 2);
        func_002A0D20(h, 2);
    }
}
