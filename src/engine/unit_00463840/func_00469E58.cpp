/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x1e];
    unsigned char mode;
    char pad1[5];
    float a;
    float b;
    char pad2[0x14];
    signed char result;
    signed char flag;
    char pad3[0xa6];
    char *data;
};
extern "C" void func_00469E48(Obj *) throw();
extern "C" int func_0036BF68(char *, float);
static inline float minimum(float value, float other) {
    if (!(value < other)) value = other;
    return value;
}
extern "C" void func_00469E58(Obj *self) {
    char *data = self->data;
    func_00469E48(self);
    char *p = data + 0x104;
    float limit;
    float current;
    switch (self->mode) {
    case 3:
        current = *(float *)(p + 0x53c);
        limit = self->b;
        goto compare;
    case 4: {
        current = self->b;
        float other = self->a;
        limit = minimum(current, other);
        current = *(float *)(p + 0x53c);
        break;
    }
    default:
        current = *(float *)(p + 0x53c);
        goto fallback;
    }
compare:
    if (current < limit) return;
    self->flag = 1;
    goto call;
fallback:
    limit = self->b;
    if (current < limit) return;
call:
    self->result = func_0036BF68(data, limit);
}
