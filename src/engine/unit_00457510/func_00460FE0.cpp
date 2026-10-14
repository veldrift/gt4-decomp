/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int index; char pad[0x10]; void *dev; };
struct Entry { int a, b, count; };
extern State D_008468D0;
struct Table { Entry entries[32]; };
extern Table D_006239A8;
extern "C" int func_0055BEC0(void *);
extern "C" void func_0055C020(void *, int, float, float);
extern "C" void func_00460FE0(float arg) {
    State *s = &D_008468D0;
    void *dev = s->dev;
    if (dev) {
        int i = s->index * 3;
        Entry *e = (Entry *)((char *)&D_006239A8 + i * 4);
        e->count = func_0055BEC0(dev) + 1;
        func_0055C020(s->dev, 2, 0.0f, arg);
        s->dev = 0;
    }
}
