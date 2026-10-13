struct S {
    char pad0[0x4];
    int unk4;
    char pad8[0xA8];
    int unkB0;
};

extern "C" int CourseData__getRunway(S *arg0);

extern "C" float func_00395228(S *arg0, int arg1) {
    float r;
    float k;
    if (arg0->unkB0 < 0) {
        char *p = (char *)CourseData__getRunway((S *)arg0->unk4);
        int idx = arg1 << 4;
        int base = *(int *)(p + 0x5C);
        int t = idx + base;
        k = 3.14159258f;
        r = *(float *)(t + 0xC);
    } else {
        char *p = (char *)CourseData__getRunway((S *)arg0->unk4);
        int v = arg0->unkB0 << 5;
        int q = *(int *)(p + 0x9C) + v;
        k = 3.14159258f;
        int e = *(int *)(q + 0x18);
        r = *(float *)((arg1 << 4) + e + 0xC);
    }
    return r + k;
}
