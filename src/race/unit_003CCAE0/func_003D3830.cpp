/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0x34]; float x, y; };
extern "C" float func_003CCB60(void *, float, float);
extern "C" float func_003D35A8(int, int) throw();
extern "C" int func_003D3830(Self *self, void *rng, int kind, int side) {
    float y;
    if (side == 0) {
        self->x = func_003CCB60(rng, 0.0f, 0.25f) + -2.75f;
        y = func_003D35A8(kind, 0);
        y += func_003CCB60(rng, -0x1.999998p-4f, 0x1.999998p-4f);
        self->y = y;
    } else {
        self->x = func_003CCB60(rng, -0.25f, 0.0f) + 2.75f;
        y = func_003D35A8(kind, side);
        y += func_003CCB60(rng, -0x1.999998p-4f, 0x1.999998p-4f);
        self->y = y;
    }
}
