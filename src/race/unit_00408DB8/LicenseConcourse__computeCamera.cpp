/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, z, w; };
struct Vec3 { float x, y, z; };
struct Sub { char p[8]; int f8; };
struct LC {
    char p0[4];
    Sub *f4;
    char p8[0x2C - 8];
    Vec3 off;
    float angle;
    char p3C[4];
    int f40;
    int f44;
    float f48;
    Vec3 eye;
    Vec3 center;
    Vec3 up;
    char p70[8];
    int f78;
    int f7C;
};
struct Player { char p[0x10]; };
extern "C" int LicenseConcourse__isCameraPeriod(LC *);
extern "C" Player *func_00427820(Player *);
extern "C" void GT4_Motion__MotionSetPlayer__set(Player *, int, int);
extern "C" int func_00427CD8(Player *, float *, int, int, float, float);
extern "C" int func_00428298(Player *, float *, int, int, float, float);
extern "C" void func_0048AF20(Vec4 *, float);
extern "C" void func_0048A3B8(Vec4 *, Vec3 *, Vec3 *);

static inline void set(Vec3 *v, float x, float y, float z) { v->x=x; v->y=y; v->z=z; }

extern "C" void LicenseConcourse__computeCamera(LC *self) {
    float buf[12];
    Player player;
    Vec4 rot;
    Vec3 tmp;
    if (!LicenseConcourse__isCameraPeriod(self)) {
        self->f78 = 0;
        self->f7C = 0;
        return;
    }
    func_00427820(&player);
    GT4_Motion__MotionSetPlayer__set(&player, 0, self->f4->f8);
    self->f78 = func_00427CD8(&player, buf, self->f40, 0, self->f48, (float)self->f44);
    if (self->f78) {
        Vec3 *e = &self->eye;
        Vec3 *c = &self->center;
        float *ox = &self->off.x;
        float *oz = &self->off.z;
        float *oy = &self->off.y;
        set(&tmp, buf[0], buf[1], buf[2]);
        func_0048AF20(&rot, self->angle);
        func_0048A3B8(&rot, e, &tmp);
        e->x = e->x + *ox;
        set(&tmp, buf[3], buf[4], buf[5]);
        e->y = self->eye.y + *oy;
        e->z = self->eye.z + *oz;
        func_0048AF20(&rot, self->angle);
        func_0048A3B8(&rot, c, &tmp);
        c->x = c->x + *ox;
        set(&tmp, buf[6], buf[7], buf[8]);
        c->y = self->center.y + *oy;
        c->z = self->center.z + *oz;
        func_0048AF20(&rot, self->angle);
        func_0048A3B8(&rot, &self->up, &tmp);
    }
    self->f7C = func_00428298(&player, (float *)self->p70, self->f40, 0, self->f48, (float)self->f44);
}
