/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tab { short n; short pad; float *v; float *k; };
struct Item { float m0; char p[0x6C - 4]; Tab t; };
struct Data { char p[0x18]; float m18; };
struct Slot { unsigned char m0; char pad[0xEB]; };
struct Self { char p[0x10]; Data *m10; char q[0x1ED - 0x14]; Slot arr[2]; };
extern "C" float func_0057D380(float);
extern "C" Item *func_00360F80(Data *, int, int);
extern "C" float func_00359830(Tab *, float);

extern "C" float func_00356300(Self *self) {
    char *b = (char *)self + 0x104;
    Data *d = self->m10;
    float z = 0.0f;
    float r = *(float *)(b + 0x53C) * ((*(float *)(b + 0x53C) * func_0057D380(*(float *)(b + 0x468))) / d->m18);
    if (r < z) r = -r;
    int idx = *(float *)(b + 0x468) > z;
    Slot *e = &self->arr[idx];
    Item *it = func_00360F80(d, idx, e->m0);
    float w = *(float *)(b + 0x468) * 1.5f;
    if (w < z) w = -w;
    float s = func_00359830(&it->t, w) * it->m0;
    s = s + s;
    if (s < z) s = -s;
    if (s < r) r = s;
    if (*(float *)(b + 0x468) < z) r = -r;
    return r;
}
