/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { unsigned char tag, count; char pad[18]; unsigned char wheel[1]; };
struct Entry { char pad0[0x54]; float f; char pad[0xec - 0x58]; };
struct Part {
    char *car;
    char pad[0x194 - 4];
    Entry entries[4];
    float bias;
    char pad2[0x8c0 - 0x548];
    float values[4];
};
struct Obj { char pad[16]; Part part; };
extern "C" Info *func_00359510(void *);
extern "C" float func_00344B40(Obj *self, int index, float t) {
    Info *info = func_00359510(self->part.car);
    float result = 0.0f;
    if (index < info->count) {
        t += self->part.bias;
        int offset = index * sizeof(float);
        Part *part = &self->part;
        Entry *e = self->part.entries + index;
        float blend = ((Part *)(offset + (int)part))->values[0] * t + e->f * (1.0f - t);
        result = *(float *)(part->car + info->wheel[index] * 0x58 + 0x314);
        result -= blend;
    }
    return result;
}
