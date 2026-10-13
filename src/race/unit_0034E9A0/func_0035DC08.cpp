typedef float f32;

void func_0035DC08(void *arg0) {
    char *v = (char *)arg0 + 0x104;
    f32 t2 = *(f32 *)(v + 0x5CC);
    f32 t3 = *(f32 *)(v + 0x5C4);
    f32 t0 = *(f32 *)((char *)arg0 + 0x54C) * 111.1111f;
    f32 r;
    f32 t4;
    f32 s;
    f32 u;

    if (t2 < t3) {
        r = t2 + t0;
        *(f32 *)(v + 0x5CC) = r;
        if (t3 < r) {
            *(f32 *)(v + 0x5CC) = t3;
        }
    } else {
        r = t2 - t0;
        *(f32 *)(v + 0x5CC) = r;
        if (r < t3) {
            *(f32 *)(v + 0x5CC) = t3;
        }
    }
    t4 = *(f32 *)(v + 0x560);
    s = *(f32 *)(v + 0x55C);
    u = s + ((((*(f32 *)(v + 0x554) - t4) * 200.0f) - (s * 20.0f)) * 0x1.111110p-6f);
    *(f32 *)(v + 0x55C) = u;
    *(f32 *)(v + 0x560) = t4 + u * 0x1.111110p-6f;
}
