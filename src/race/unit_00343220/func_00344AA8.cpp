/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { unsigned char tag, count; };
struct Obj { char pad[0x10]; void *p10; char pad14[0x554 - 0x14]; float f554; };
extern "C" Info *func_00359510(void *);
extern "C" float func_00344AA8(Obj *self, int index, float t) {
    Info *info = func_00359510(self->p10);
    if (index >= info->count) return 0.0f;
    t += self->f554;
    float f = *(float *)(index * 4 + (char *)self + 0x900);
    char *e = (char *)self + index * 0xEC;
    return f * t + *(float *)(e + 0x16C) * (1.0f - t);
}
