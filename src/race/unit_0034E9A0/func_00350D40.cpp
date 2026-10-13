typedef float f32;

void func_00350D40(void *arg0) {
    f32 k = 0x1.111110p-6f;
    f32 *v = (f32 *)((char *)arg0 + 0x63C);
    f32 t0 = *(f32 *)((char *)arg0 + 0x588);
    f32 t3 = *v;
    f32 *q = (f32 *)((char *)arg0 + 0x640);
    f32 temp_f1 = *q;
    f32 temp_f1_2;
    f32 s;

    temp_f1_2 = temp_f1 + ((((t0 - t3) * 500.0f) - (temp_f1 * 20.0f)) * k);
    *q = temp_f1_2;
    s = temp_f1_2 * k;
    *v = *v + s;
}
