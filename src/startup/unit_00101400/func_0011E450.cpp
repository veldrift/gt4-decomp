/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

struct Car {
    char pad0[0x5A8];
    f32 f5A8;
    char pad5AC[0x624 - 0x5AC];
    u8 f624;
    char pad625[0x6C8 - 0x625];
    f32 f6C8;
};

struct Sample {
    u16 gear : 3;
    u16 rpm : 13;
    u8 b2;
    u8 b3;
    s16 h4;
    s16 h6;
};

struct Log {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    Sample *buf;
    s32 *cnt;
    f32 f38;
    f32 f3C;
    f32 f40;
    Car *car;
    s32 f48;
};

extern "C" f32 func_0011E310(f32, f32, f32, f32, f32) throw() __attribute__((const));
extern "C" f32 func_0011E348(f32, f32, f32, f32, f32, f32) throw() __attribute__((const));
extern "C" s16 Automobile__GetImplicitCurrentLap(Car *);
extern "C" f32 func_00344698(Car *);
extern "C" f32 func_003446A0(Car *);
extern "C" f32 func_00344798(Car *, f32);
extern "C" f32 func_00344828(Car *, f32);

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

extern "C" void func_0011E450(Log *self) {
    if (*self->cnt < 0x4000) {
        f32 zero = 0.0f;
        s32 lap = Automobile__GetImplicitCurrentLap(self->car);
        f32 pos = self->car->f5A8;
        f32 speed = self->car->f6C8;
        u8 gear = self->car->f624;
        f32 a = func_00344698(self->car);
        f32 b = func_003446A0(self->car);
        f32 c = func_00344798(self->car, zero);
        f32 d = func_00344828(self->car, zero);
        lap--;
        pos += (f32)lap * self->f40;
        self->f2C = maxf(self->f2C, speed);
        if (self->f48) {
            self->f0 = pos;
            self->f4 = pos;
            self->f14 = pos;
            self->f48 = 0;
        } else if (pos <= self->f4) {
            pos = self->f4;
        } else {
            self->f4 = pos;
            f32 x1 = pos - self->f0;
            f32 x0 = self->f14 - self->f0;
            f32 t = (f32)*self->cnt * self->f38;
            f32 tn = t + self->f38;
            self->f8 += func_0011E348(x0, x1, self->f18, speed, t, tn);
            self->fC += func_0011E348(x0, x1, self->f1C, a, t, tn);
            self->f10 += func_0011E348(x0, x1, self->f20, b, t, tn);
            while (tn <= x1) {
                f32 v8 = self->f8 * 40.0f * self->f3C + 0.5f;
                f32 vC = self->fC * 255.0f * self->f3C + 0.5f;
                f32 v10 = self->f10 * 255.0f * self->f3C + 0.5f;
                f32 e = func_0011E310(x0, x1, self->f24, c, tn);
                f32 f = func_0011E310(x0, x1, self->f28, d, tn);
                self->buf[*self->cnt].gear = gear;
                self->buf[*self->cnt].rpm = (u32)minf(v8, 8191.0f);
                self->buf[*self->cnt].b2 = (u32)minf(vC, 255.0f);
                self->buf[*self->cnt].b3 = (u32)minf(v10, 255.0f);
                self->buf[*self->cnt].h4 = (s32)e;
                self->buf[*self->cnt].h6 = (s32)f;
                ++*self->cnt;
                if (*self->cnt >= 0x4000) {
                    return;
                }
                t += self->f38;
                tn += self->f38;
                self->f8 = func_0011E348(x0, x1, self->f18, speed, t, tn);
                self->fC = func_0011E348(x0, x1, self->f1C, a, t, tn);
                self->f10 = func_0011E348(x0, x1, self->f20, b, t, tn);
            }
        }
        self->f14 = pos;
        self->f18 = speed;
        self->f1C = a;
        self->f20 = b;
        self->f24 = c;
        self->f28 = d;
    }
}
