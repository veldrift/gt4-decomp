/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Fade {float amount, start, end;};
struct Rec {char pad[0x444]; float spd; char pad2[0x4B2-0x448]; unsigned char flag;};
struct Self {char pad[0x7C]; Fade fade; float f88; char pad2[4]; float f90; float f94;};
extern "C" float ComputeSlowEnemyBoost(Fade *, Rec *, int, float) throw();
extern "C" float ComputeFastEnemyRestrain(Fade *, Rec *, int, float) throw();
extern "C" void DynamicsConductor__ComputeDifference(Self *, void *, Rec *, int *, float *);
extern "C" float DynamicsConductor__ControlEnemySpeed(Self *self, void *a1, Rec *rec, float mul){
    int d;
    float t;
    float r = 1.0f;
    if (rec->flag == 0) {
        DynamicsConductor__ComputeDifference(self, a1, rec, &d, &t);
        int pos;
        if (d > 0) pos = 1;
        else if (d < 0) pos = 0;
        else pos = t > 0.0f;
        if (pos) {
            if (self->f88 != 0.0f) r = ComputeSlowEnemyBoost(&self->fade, rec, d, t);
        } else {
            if (self->fade.amount != 0.0f) r = ComputeFastEnemyRestrain(&self->fade, rec, -d, -t);
        }
    }
    r = r * mul;
    if (r > 1.3f) r = 1.3f;
    rec->spd = r * self->f94;
    return r;
}
