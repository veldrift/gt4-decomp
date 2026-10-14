/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *, int); };
struct Entry0 { short delta, index; void (*fn)(void *); };
struct Context { int x; Entry *vt; };
struct Face { char pad[0x5c]; float x5c,x60; };
struct Object {
    char pad[0xa0]; Face face; int str;
    char p108[0x30]; float f138; char p13c[8]; float f144;
};
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" void func_002472B8(void *, void *);
extern "C" void func_00231170(void *, void *);
extern "C" void func_00247428(void *);
static inline void begin(Context *ctx) {
    Entry *e = (Entry *)((char *)ctx->vt + 0x1c0);
    e->fn((char *)ctx + e->delta, 0);
}
static inline void end(Context *ctx) {
    Entry0 *e = (Entry0 *)((char *)ctx->vt + 0x1c8);
    e->fn((char *)ctx + e->delta);
}
extern "C" void mToolTipFace__virtual_70(Object *self, Context *ctx, int active) {
    mWidget__virtual_70(self, ctx, 0);
    if (active) {
        Face *face = &self->face;
        begin(ctx);
        float x = self->f138;
        float y = self->f144;
        face->x5c = x;
        face->x60 = y;
        func_002472B8(face, ctx);
        func_00231170(ctx, &self->str);
        func_00247428(face);
        end(ctx);
    }
}
