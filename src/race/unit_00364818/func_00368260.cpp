/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct Eng {
    char pad0[0x134];
    s16 h134;
    char pad136[0x140 - 0x136];
    f32 f140[24];
    f32 f1A0[24];
};
struct Car {
    char pad0[0x10];
    Eng *eng;
};
struct Eng2 {
    char pad[0x247];
    u8 b247;
};

extern "C" s32 func_003683A8(void *);
extern "C" s32 D_00620CAC;
extern "C" s16 D_00620CA0;
extern "C" f32 D_00844068[];
extern "C" f32 D_00844098[];

extern "C" void func_00368260(Car *self) {
    if (func_003683A8(self) != 0 && D_00620CAC == 0) {
        Eng *t = self->eng;
        if (((Eng2 *)t)->b247 == 3) {
            s32 n = t->h134 + 1;
            s32 m = n >= 13 ? 12 : n;
            D_00620CA0 = m;
            D_00844068[0] = 0;
            D_00844098[0] = 0;
            s32 i = 1;
            if (i < m) {
                do {
                    f32 a = t->f140[i-1];
                    f32 b = t->f1A0[i-1];
                    f32 rpm = (a * 60.0f) / 0x1.921fb4p+2f;
                    D_00844068[i] = ((b / 0x1.399998p+3f) * rpm) / 0x1.661998p+9f * 0x1.789374p-1f;
                    D_00844098[i] = a;
                    i++;
                } while (i < m);
            }
            D_00620CAC = 1;
        }
    }
}
