/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Box { float min[3]; float max[3]; };
extern "C" void func_003E6E28(float *, const float *, const float *, float, int) throw();
extern "C" int func_003E71C8(Box *, float *, float *, int);
extern "C" void *func_005A47D4(void *, const void *, unsigned) throw();

static inline void copyRange(const float *first, const float *last, float *out) {
    func_005A47D4(out, first, (const char *)last - (const char *)first);
}

extern "C" int func_003E6E90(Box *b, float *o1, float *o2, float *from, float *dir) {
    for (int i = 0; i < 3; i++) {
        float p = from[i];
        if (p < b->min[i]) {
            if (dir[i] <= 0.0f) return 0;
            func_003E6E28(o1, from, dir, b->min[i], i);
            func_003E6E28(o2, from, dir, b->max[i], i);
        } else if (b->max[i] < p) {
            if (dir[i] >= 0.0f) return 0;
            func_003E6E28(o1, from, dir, b->max[i], i);
            func_003E6E28(o2, from, dir, b->min[i], i);
        } else if (dir[i] == 0.0f) {
            continue;
        } else {
            copyRange(from, from + 3, o1);
            func_003E6E28(o2, from, dir, dir[i] < 0.0f ? b->min[i] : b->max[i], i);
        }
        return func_003E71C8(b, o1, o2, i + 1);
    }
    return 0;
}
