/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { char pad[0x18]; int error; };
struct Data { int size[3][2]; char pad[0x734 - 0x18]; int coef[64]; int prev[3]; };
struct Encoder { int err, detail, x8; Data d; };
struct Obj { char pad[0xc]; Encoder enc; char pad2[0x85c - 0xc - sizeof(Encoder)]; State state; char pad3[0x87c - 0x85c - sizeof(State)]; char coord[16]; };
extern "C" void func_0046C1C0(void *) throw();
extern "C" void func_0046C218(void *) throw();
extern "C" void func_00471170(void *, void *, int, int);
extern "C" void func_00471550(void *, int, int);
extern "C" int func_00471738(void *, void *, int);
extern "C" int func_0046C520(Obj *self, int x, int y) {
    Encoder *in = &self->enc;
    func_00471170(in, self->coord, x, y);
    State *st = &self->state;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < in->d.size[i][0] * in->d.size[i][1]; j++) {
            func_00471550(in, i, j);
            if (!func_00471738(in, st, i)) { func_0046C1C0(self); return 0; }
            if (st->error) { func_0046C218(self); return 0; }
            in->d.prev[i] = in->d.coef[0];
        }
    }
    return 1;
}
