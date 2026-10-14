/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct Cam {
    char pad0[0x28];
    u8 b28;
    u8 b29;
    u8 b2A;
    u8 b2B;
};
struct Sub {
    char pad[4];
};
struct Input {
    int mode;
    int flag;
    int out;
};
struct Obj {
    char pad0[0xDD0];
    Cam cam;
    char padDD4[0xE28 - 0xDD0 - sizeof(Cam)];
    Sub sub;
    char padE2C[0xF30 - 0xE28 - sizeof(Sub)];
    int state;
};

extern "C" void func_0036FE18(Sub *, Cam *) throw();
extern "C" void func_00370640(Sub *, Cam *) throw();
extern "C" void func_00370898(Sub *) throw();
extern "C" void func_003708D0(Sub *);
extern "C" void func_00370928(Sub *) throw();
extern "C" int func_00370950(Sub *) throw();
extern "C" void func_00370960(Sub *, Cam *);
extern "C" void func_00370BE0(Sub *) throw();
extern "C" void func_00370C48(Sub *) throw();
extern "C" void func_00370C68(Sub *) throw();
extern "C" int func_00370CC0(Sub *) throw();
extern "C" void func_003FAC90(Cam *, int);

extern "C" void func_00378778(Obj *self, int a1, int a2, Input *in) {
    Cam *cam = &self->cam;
    int moved = 0;
    Sub *sub = &self->sub;
    int mode = in->mode;
    if (in->flag != 0) {
        self->state = 1;
        if (mode == 2)
            func_00370898(sub);
        else
            func_00370BE0(sub);
    }
    func_003FAC90(cam, 1);
    int st = self->state;
    switch (st) {
    case 1:
        if (cam->b28 != 0) {
            if (mode == 2) {
                if (func_00370950(sub) != 0) {
                    func_003708D0(sub);
                    self->state = mode;
                }
            } else {
                if (func_00370CC0(sub) != 0) {
                    func_00370C48(sub);
                    self->state = 2;
                }
            }
            moved = 1;
        }
        if (cam->b2A != 0) {
            self->state = 3;
            if (mode == 2)
                func_00370928(sub);
            else
                func_00370C68(sub);
            moved = 1;
        }
        break;
    case 2:
    case 3:
        moved = 1;
        if ((cam->b29 == 0) & (cam->b2B == 0)) {
            self->state = 0;
            in->out = moved;
        }
        break;
    }
    if (moved != 0) {
        func_0036FE18(sub, cam);
        return;
    }
    if (mode == 2) {
        func_00370640(sub, cam);
        return;
    }
    func_00370960(sub, cam);
}
