/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref {
    void *value;
    operator void *() const { return value; }
};
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline void assign(Ref *self, const Ref *other) {
    if (self != other) {
        void *p = other->value;
        if (p) func_003285A8(p);
        if (self->value) func_003285F8(self->value);
        self->value = p;
    }
}
struct Spec { char bytes[0x600]; };
struct Curve {
    float peakPower, peakTorque, unknown8;
    unsigned short endRPM, count;
    short rpm[24];
    float power[24], torque[24];
};
struct Work {
    Curve curve;
    union Scratch {
        char bytes[0x80];
        struct Handles { Ref array; char pad04[12]; Ref temporary; } handles;
    } scratch;
    Ref garage; char pad184[12];
    Spec spec;
};
struct EntryInt { short delta,index; int (*function)(void *); };
struct EntryFloat { short delta,index; float (*function)(void *); };
struct Obj { int unknown0; char *table; };
static inline int integer(Obj *o) {
    EntryInt *e = (EntryInt *)(o->table + 0x58);
    return e->function((char *)o + e->delta);
}
static inline float real(Obj *o) {
    EntryFloat *e = (EntryFloat *)(o->table + 0x60);
    return e->function((char *)o + e->delta);
}
extern "C" int func_0013BDC0(Ref *, void *);
extern "C" void func_0013BD68(Ref *, int);
extern "C" char *func_00147D80(void *);
extern "C" void *func_00441248(void *);
extern "C" void func_004413C8(void *, Spec *);
extern "C" void func_0034B960(Spec *, void *, Curve *, void *);
extern "C" void func_002EFC48(Ref *, int);
extern "C" int *func_00575DC8(int);
extern "C" Ref *func_002EFCE0(Ref *, int);
extern "C" void func_00200140(Ref *, int *, int);
extern "C" void func_001FFF30(Ref *, int);
extern "C" void func_002F9360(Ref *, float);
extern "C" void func_002F7B68(Ref *, int);
extern "C" void func_002ED5C0(Ref *, int);
extern "C" void MCarGarage__buildEngineCurveData(Ref *destination, void *context, int argc, Obj **argv) {
    Work work;
    int normalize = 1;
    func_0013BDC0(&work.garage, context);
    char *car = func_00147D80(work.garage);
    func_0013BD68(&work.garage, 2);
    void *data = func_00441248(car);
    func_004413C8(data, &work.spec);
    func_0034B960(&work.spec, &work.scratch, &work.curve, car + 0x4A0);
    if (argc > 0) normalize = integer(argv[0]) != 0;
    float powerLimit = 1000.0f;
    if (argc >= 2) powerLimit = real(argv[1]);
    float torqueLimit = 200.0f;
    if (argc >= 3) torqueLimit = real(argv[2]);
    Ref &array = work.scratch.handles.array;
    func_002EFC48(&array, 6);
    int count = work.curve.count;
    int *power = func_00575DC8(0x804);
    power[0] = count;
    {
        float scale = powerLimit;
        if (normalize) scale = work.curve.peakPower;
        else if (scale < work.curve.peakPower) scale = work.curve.peakPower;
        if (count != 0) {
            int first = work.curve.rpm[0];
            float range = (int)work.curve.endRPM - first;
            const short *rpm = work.curve.rpm;
            const float *value = work.curve.power;
            float *out = (float *)power;
            int remaining = count;
            do {
                float x = (int)*rpm++ - first;
                float y = *value++ / scale;
                out[2] = y;
                out[1] = x / range;
                out += 2;
            } while (--remaining != 0);
        }
    }
    Ref *element = func_002EFCE0(&array, 0);
    Ref &temporary = work.scratch.handles.temporary;
    func_00200140(&temporary, power, 1);
    assign(element, &temporary);
    func_001FFF30(&temporary, 2);
    int *torque = func_00575DC8(0x804);
    torque[0] = count;
    {
        float scale = torqueLimit;
        if (normalize) scale = work.curve.peakTorque;
        else if (scale < work.curve.peakTorque) scale = work.curve.peakTorque;
        if (count != 0) {
            int first = work.curve.rpm[0];
            float range = (int)work.curve.endRPM - first;
            const short *rpm = work.curve.rpm;
            const float *value = work.curve.torque;
            float *out = (float *)torque;
            int remaining = count;
            do {
                float x = (int)*rpm++ - first;
                float y = *value++ / scale;
                out[2] = y;
                out[1] = x / range;
                out += 2;
            } while (--remaining != 0);
        }
    }
    element = func_002EFCE0(&array, 1);
    func_00200140(&temporary, torque, 1);
    assign(element, &temporary);
    func_001FFF30(&temporary, 2);
    element = func_002EFCE0(&array, 2);
    func_002F9360(&temporary, work.curve.peakPower);
    assign(element, &temporary);
    func_002F7B68(&temporary, 2);
    element = func_002EFCE0(&array, 3);
    func_002F9360(&temporary, work.curve.peakTorque);
    assign(element, &temporary);
    func_002F7B68(&temporary, 2);
    element = func_002EFCE0(&array, 4);
    func_002F9360(&temporary, count > 0 ? (float)work.curve.rpm[0] : 0.0f);
    assign(element, &temporary);
    func_002F7B68(&temporary, 2);
    element = func_002EFCE0(&array, 5);
    func_002F9360(&temporary, (float)work.curve.endRPM);
    assign(element, &temporary);
    func_002F7B68(&temporary, 2);
    assign(destination, &array);
    func_002ED5C0(&array, 2);
}
