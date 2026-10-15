/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Ref_00309348 {
    void *field_0;
    operator void *() const { return field_0; }
    Ref_00309348(const Ref_00309348 &) __asm__("func_00309360");
    ~Ref_00309348() __asm__("func_00309378");
    Ref_00309348 &operator=(const Ref_00309348 &other) {
        if (this != &other) {
            void *value = other.field_0;
            if (value) func_003285A8(value);
            if (field_0) func_003285F8(field_0);
            field_0 = value;
        }
        return *this;
    }
};

struct GarageRef : Ref_00309348 {
    GarageRef(void *) __asm__("func_0013BDC0");
    ~GarageRef() __asm__("func_0013BD68");
};
struct ArrayRef : Ref_00309348 {
    ArrayRef(int) __asm__("func_002EFC48");
    ~ArrayRef() __asm__("func_002ED5C0");
    Ref_00309348 &operator[](int) __asm__("func_002EFCE0");
};
struct IntegerRef : Ref_00309348 {
    IntegerRef(int) __asm__("func_002FE278");
    ~IntegerRef() __asm__("func_002FC870");
};

struct FloatArrayRef : Ref_00309348 {
    FloatArrayRef(int *, int) __asm__("func_00200140");
    ~FloatArrayRef() __asm__("func_001FFF30");
};
struct FloatRef : Ref_00309348 {
    FloatRef(float) __asm__("func_002F9360");
    ~FloatRef() __asm__("func_002F7B68");
};
struct Spec { char bytes[0x600]; };
struct Curve {
    float peakPower, peakTorque, unknown8;
    unsigned short endRPM, count;
    short rpm[24];
    float power[24], torque[24];
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
extern "C" char *func_00147D80(void *);
extern "C" void *func_00441248(void *);
extern "C" void func_004413C8(void *, Spec *);
extern "C" void func_0034B960(Spec *, void *, Curve *, void *);
extern "C" int *func_00575DC8(int);
static inline char *car_for(void *context) {
    GarageRef garage(context);
    return func_00147D80(garage);
}
static inline void compute_curve(Curve &curve, void *context) {
    char intermediate[0x80];
    char *car = car_for(context);
    Spec spec;
    void *data = func_00441248(car);
    car += 0x4A0;
    func_004413C8(data, &spec);
    func_0034B960(&spec, intermediate, &curve, car);
}
extern "C" void MCarGarage__buildEngineCurveData(Ref_00309348 *destination, void *context, int argc, Obj **argv) {
    Curve curve;
    int normalize = 1;
    compute_curve(curve, context);
    if (argc > 0) normalize = integer(argv[0]) != 0;
    float powerLimit = 1000.0f;
    if (argc >= 2) powerLimit = real(argv[1]);
    float torqueLimit = 200.0f;
    if (argc >= 3) torqueLimit = real(argv[2]);
    ArrayRef array(6);
    int count = curve.count;
    int *power = func_00575DC8(0x804);
    power[0] = count;
    {
        float scale = powerLimit;
        if (normalize) scale = curve.peakPower;
        else if (scale < curve.peakPower) scale = curve.peakPower;
        if (__builtin_expect(count, 0)) {
            int first = curve.rpm[0];
            float range = (int)curve.endRPM - first;
            const float *value = curve.power;
            const short *rpm = curve.rpm;
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
    {
        Ref_00309348 &element = array[0];
        FloatArrayRef value(power, 1);
        element = value;
    }
    int *torque = func_00575DC8(0x804);
    torque[0] = count;
    {
        float scale = torqueLimit;
        if (normalize) scale = curve.peakTorque;
        else if (scale < curve.peakTorque) scale = curve.peakTorque;
        if (__builtin_expect(count, 0)) {
            int first = curve.rpm[0];
            float range = (int)curve.endRPM - first;
            const float *value = curve.torque;
            const short *rpm = curve.rpm;
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
    {
        Ref_00309348 &element = array[1];
        FloatArrayRef value(torque, 1);
        element = value;
    }
    {
        Ref_00309348 &element = array[2];
        FloatRef value(curve.peakPower);
        element = value;
    }
    {
        Ref_00309348 &element = array[3];
        FloatRef value(curve.peakTorque);
        element = value;
    }
    {
        Ref_00309348 &element = array[4];
        FloatRef value(count > 0 ? (float)curve.rpm[0] : 0.0f);
        element = value;
    }
    {
        Ref_00309348 &element = array[5];
        FloatRef value((float)curve.endRPM);
        element = value;
    }
    *destination = array;
}
