/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0xf81a]; unsigned char type; };
struct Obj { char pad[4]; Data *data; };
struct State { char pad0[0x53]; signed char id; char pad1[0xc]; float x, y; };
extern "C" int func_0034AA88(Obj *o, int *id, float *x, float *y) {
    State *s = (State *)((char *)o + 0x14);
    if (o->data->type == 6) return 0;
    int index = s->id;
    float a = s->x;
    float b = s->y;
    if (index == -1) return 0;
    *id = index;
    *x = a;
    *y = -b;
    return 1;
}
