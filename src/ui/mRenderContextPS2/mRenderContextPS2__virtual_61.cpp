/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, z, w; };
struct Entry { short delta, index; void (*fn)(void *, Vec4 *, int); };
struct Obj { int first; Entry *vtbl; };
extern "C" void func_004A1638(int);
extern "C" void func_004A2DF8(float, float, float, float);
extern "C" void mRenderContextPS2__virtual_61(Obj *self, int arg) {
    Vec4 v;
    float zero = 0.0f;
    v.x = zero;
    v.y = zero;
    v.z = zero;
    v.w = zero;
    Entry *e = (Entry *)((char *)self->vtbl + 0x1F8);
    e->fn((char *)self + e->delta, &v, arg);
    func_004A1638(0x12);
    func_004A2DF8(v.x, v.y, v.z, v.w);
}
