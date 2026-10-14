/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Ref_00309348 {
    void *field_0;
    operator void *() const { return field_0; }
    Ref_00309348(void * const &) __asm__("func_00309348");
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

struct Date { short year; unsigned char month, day; };
extern "C" Date func_00579898(int);
struct Entry { short delta, index; int (*function)(void *); };
struct Obj { int unknown0; char *table; };
static inline int integer(Obj *object) {
    Entry *entry = (Entry *)(object->table + 0x58);
    return entry->function((char *)object + entry->delta);
}
struct IntegerRef : Ref_00309348 {
    IntegerRef(int) __asm__("func_002FE278");
    ~IntegerRef() __asm__("func_002FC870");
};
struct ArrayObject {
    Ref_00309348 append(const Ref_00309348 &) __asm__("func_002EEEB0");
};
struct ArrayRef : Ref_00309348 {
    ArrayRef() __asm__("func_002EFBF0");
    ~ArrayRef() __asm__("func_002ED5C0");
    ArrayObject *operator->() const { return (ArrayObject *)field_0; }
};
extern "C" void MCalendar__dayToDate(Ref_00309348 *destination, int argc, Obj **argv) {
    if (argc > 0) {
        Date date = func_00579898(integer(argv[0]));
        ArrayRef array;
        array->append(IntegerRef(date.year));
        array->append(IntegerRef(date.month));
        array->append(IntegerRef(date.day));
        *destination = array;
    } else {
        void *empty = 0;
        *destination = Ref_00309348(empty);
    }
}
