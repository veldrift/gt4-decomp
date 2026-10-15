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
extern "C" void MCarGarage__getSuspensionRange(Ref_00309348 *destination, void *context) {
    RangeData *range = range_for(context);
    ArrayRef array(42);
    store<0, 0x84, unsigned short>(array, range);
    store<1, 0x86, unsigned short>(array, range);
    store<2, 0x8A, unsigned short>(array, range);
    store<3, 0x8C, unsigned short>(array, range);
    store<4, 0x93, unsigned char>(array, range);
    store<5, 0x94, unsigned char>(array, range);
    store<6, 0x96, unsigned char>(array, range);
    store<7, 0x97, unsigned char>(array, range);
    store<8, 0xAB, unsigned char>(array, range);
    store<9, 0xAC, unsigned char>(array, range);
    store<10, 0xAE, unsigned char>(array, range);
    store<11, 0xAF, unsigned char>(array, range);
    store<12, 0xB8, unsigned char>(array, range);
    store<13, 0xB9, unsigned char>(array, range);
    store<14, 0xBB, unsigned char>(array, range);
    store<15, 0xBC, unsigned char>(array, range);
    store<16, 0xCC, unsigned char>(array, range);
    store<17, 0xCD, unsigned char>(array, range);
    store<18, 0xCE, unsigned char>(array, range);
    store<19, 0xD0, unsigned char>(array, range);
    store<20, 0xD1, unsigned char>(array, range);
    store<21, 0xD3, unsigned char>(array, range);
    store<22, 0xD4, unsigned char>(array, range);
    store<23, 0xD5, unsigned char>(array, range);
    store<24, 0xD7, unsigned char>(array, range);
    store<25, 0xD8, unsigned char>(array, range);
    store<26, 0xDA, unsigned char>(array, range);
    store<27, 0xDB, unsigned char>(array, range);
    store<28, 0xDC, unsigned char>(array, range);
    store<29, 0xDE, unsigned char>(array, range);
    store<30, 0xDF, unsigned char>(array, range);
    store<31, 0xE1, unsigned char>(array, range);
    store<32, 0xE2, unsigned char>(array, range);
    store<33, 0xE3, unsigned char>(array, range);
    store<34, 0xE5, unsigned char>(array, range);
    store<35, 0xE6, unsigned char>(array, range);
    store<36, 0xEA, unsigned char>(array, range);
    store<37, 0xEB, unsigned char>(array, range);
    store<38, 0xEC, unsigned char>(array, range);
    store<39, 0xEE, unsigned char>(array, range);
    store<40, 0xEF, unsigned char>(array, range);
    store<41, 0xF0, unsigned char>(array, range);
    *destination = array;
}
