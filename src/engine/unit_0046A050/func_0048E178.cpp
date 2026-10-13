struct Mat44 {
    float m[16];
};

extern "C" void func_0048E178(struct Mat44 *a, float s) {
    a->m[0] += s;
    a->m[1] += s;
    a->m[2] += s;
    a->m[3] += s;
    a->m[4] += s;
    a->m[5] += s;
    a->m[6] += s;
    a->m[7] += s;
    a->m[8] += s;
    a->m[9] += s;
    a->m[10] += s;
    a->m[11] += s;
    a->m[12] += s;
    a->m[13] += s;
    a->m[14] += s;
    a->m[15] += s;
}
