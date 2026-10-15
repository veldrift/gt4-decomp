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
struct RangeData { unsigned char unknown[0xF2]; };
static inline RangeData *range_for(void *context) {
    GarageRef garage(context);
    return (RangeData *)((char *)garage.field_0 + 0x30);
}
template<int index, int offset, typename T>
static inline void store(ArrayRef &array, RangeData *range) {
    Ref_00309348 &element = array[index];
    IntegerRef value(*(T *)((char *)range + offset));
    element = value;
}

struct Spec { unsigned char bytes[0x600]; };
struct Entry { short delta, index; int (*function)(void *); };
struct Obj { int unknown0; char *table; };
static inline int integer(Obj *object) {
    Entry *entry = (Entry *)(object->table + 0x58);
    return entry->function((char *)object + entry->delta);
}
extern "C" void *func_00147D80(void *);
extern "C" void *func_00441248(void *);
extern "C" void func_004413C8(void *, Spec *);
extern "C" int func_00445780(void *);
extern "C" int func_0043EBB8(void *);
extern "C" int func_0043EBE0(void *);
extern "C" void func_003553A0(Spec *, int, short, short *, short *);
extern "C" void *func_005A48D8(void *, int, int);
static inline void *car_for(void *context) {
    GarageRef garage(context);
    return func_00147D80(garage);
}
extern "C" void MCarGarage__getGearRange(Ref_00309348 *destination, void *context, int argc, Obj **argv) {
    RangeData *range = range_for(context);
    ArrayRef array(23);
    store<0, 0x24, unsigned short>(array, range);
    store<1, 0x26, unsigned short>(array, range);
    store<2, 0x32, unsigned char>(array, range);
    store<3, 0x33, unsigned char>(array, range);
    void *car = car_for(context);
    short low[16], high[16];
    Spec spec;
    func_004413C8(func_00441248(car), &spec);
    int count = func_00445780(func_00441248(car));
    if (((unsigned char *)range)[0x32] < ((unsigned char *)range)[0x33]) {
        if (argc > 0) spec.bytes[0x156] = integer(argv[0]);
        int value = func_0043EBB8(car) * 10;
        short limit = func_0043EBE0(car);
        func_003553A0(&spec, value, limit, low, high);
    } else {
        func_005A48D8(low, 0, 32);
        func_005A48D8(high, 0, 32);
    }
    {
        Ref_00309348 &element = array[4];
        IntegerRef value(count);
        element = value;
    }
    {
        Ref_00309348 &element = array[5];
        IntegerRef value(low[count]);
        element = value;
    }
    {
        Ref_00309348 &element = array[6];
        IntegerRef value(high[1]);
        element = value;
    }
    {
        Ref_00309348 &element = array[7];
        IntegerRef value(low[0]);
        element = value;
    }
    {
        Ref_00309348 &element = array[8];
        IntegerRef value(high[0]);
        element = value;
    }
    {
        Ref_00309348 &element = array[9];
        IntegerRef value(low[1]);
        element = value;
    }
    {
        Ref_00309348 &element = array[10];
        IntegerRef value(high[1]);
        element = value;
    }
    {
        Ref_00309348 &element = array[11];
        IntegerRef value(low[2]);
        element = value;
    }
    {
        Ref_00309348 &element = array[12];
        IntegerRef value(high[2]);
        element = value;
    }
    {
        Ref_00309348 &element = array[13];
        IntegerRef value(low[3]);
        element = value;
    }
    {
        Ref_00309348 &element = array[14];
        IntegerRef value(high[3]);
        element = value;
    }
    {
        Ref_00309348 &element = array[15];
        IntegerRef value(low[4]);
        element = value;
    }
    {
        Ref_00309348 &element = array[16];
        IntegerRef value(high[4]);
        element = value;
    }
    {
        Ref_00309348 &element = array[17];
        IntegerRef value(low[5]);
        element = value;
    }
    {
        Ref_00309348 &element = array[18];
        IntegerRef value(high[5]);
        element = value;
    }
    {
        Ref_00309348 &element = array[19];
        IntegerRef value(low[6]);
        element = value;
    }
    {
        Ref_00309348 &element = array[20];
        IntegerRef value(high[6]);
        element = value;
    }
    {
        Ref_00309348 &element = array[21];
        IntegerRef value(low[7]);
        element = value;
    }
    {
        Ref_00309348 &element = array[22];
        IntegerRef value(high[7]);
        element = value;
    }
    *destination = array;
}
