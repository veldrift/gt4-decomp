/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Ref_00309348 {
    void *field_0;
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
struct RangeField { unsigned char byte0, byte1, byte2, byte3; };
struct RangeData { char unknown[0xF8]; RangeField fields[6]; };
static inline RangeData *range_for(void *context) {
    GarageRef garage(context);
    return (RangeData *)((char *)garage.field_0 + 0x30);
}
template<int index, int offset>
static inline void store(ArrayRef &array, RangeData *range) {
    Ref_00309348 &element = array[index];
    IntegerRef value(((unsigned char *)range)[offset]);
    element = value;
}
extern "C" void MCarGarage__getLSDRange(Ref_00309348 *destination, void *context) {
    RangeData *range = range_for(context);
    ArrayRef array(18);
    store<0, 0xF8>(array, range);
    store<1, 0xF9>(array, range);
    store<2, 0xFC>(array, range);
    store<3, 0xFD>(array, range);
    store<4, 0x100>(array, range);
    store<5, 0x101>(array, range);
    store<6, 0x104>(array, range);
    store<7, 0x105>(array, range);
    store<8, 0x108>(array, range);
    store<9, 0x109>(array, range);
    store<10, 0x10C>(array, range);
    store<11, 0x10D>(array, range);
    store<12, 0xFA>(array, range);
    store<13, 0xFE>(array, range);
    store<14, 0x102>(array, range);
    store<15, 0x106>(array, range);
    store<16, 0x10A>(array, range);
    store<17, 0x10E>(array, range);
    *destination = array;
}
