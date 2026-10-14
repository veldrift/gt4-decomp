/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *); };
struct Rect { char pad0[8]; int width; int padC; int x, y, dx, dy; };
struct Obj { int first; Entry *vtbl; char pad[0x1D5C-8]; Rect rect; char pad2[0x1C]; int enabled; };
extern "C" int func_00215B80(Obj *) throw();
extern "C" Rect *func_00214F80(int) throw();
extern "C" int func_00105818(Rect *);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void mRenderContextPS2__virtual_71(Obj *self) {
    if (self->enabled != 0) {
        Entry *e = (Entry *)((char *)self->vtbl + 0x238);
        e->fn((char *)self + e->delta);
        Rect *r = func_00214F80(func_00215B80(self));
        float width = (float)r->width;
        float height = (float)func_00105818(r);
        Rect *rect = &self->rect;
        func_004A6788(0.0f, 0.0f, width, height, (float)rect->x, (float)rect->y, (float)(rect->x + rect->dx), (float)(rect->y + rect->dy));
    }
}
