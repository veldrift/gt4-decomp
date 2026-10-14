/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x38c]; float t, x, y, z, angle, end; char gap[0x10]; float dx, dy, dz, da; };
extern "C" void func_0045C750(char *);
extern "C" void func_0045C668(Obj *p, float t) {
    float old = p->t;
    float den = p->end - old;
    float ratio = den == 0.0f ? 0.0f : (t - old) / den;
    float dx = p->dx * ratio;
    float dy = p->dy * ratio;
    float dz = p->dz * ratio;
    float da = p->da * ratio;
    float x = p->x + dx;
    float y = p->y + dy;
    float z = p->z + dz;
    float angle = p->angle + da;
    p->t = t;
    p->da = da;
    p->dx = dx;
    p->dy = dy;
    p->dz = dz;
    p->angle = angle;
    p->x = x;
    p->y = y;
    p->z = z;
    func_0045C750((char *)p);
}
