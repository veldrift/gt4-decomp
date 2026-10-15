/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct String_005C2630;
struct Ref_00309348;
struct StringRef_00314B20;
struct ArrayObj_002EEEB0;
struct Rep_00659FA8;
struct Heap_00659988 { const char *field_0; };
extern "C" Heap_00659988 *func_005C11A8();
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" char *func_005C2560(Rep_00659FA8 *);
extern "C" u32 func_0057F260(const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" char D_00692090[];
struct Rep_00659FA8 {
    s32 length_0, capacity_4, refs_8, selfish_c;
    char *data() { return (char *)(this+1); }
    char &operator[](u32 index) { return data()[index]; }
    char *grab() {
        if (selfish_c) return func_005C2560(this);
        ++refs_8;
        return data();
    }
    void release() {
        if (--refs_8 == 0) {
            s32 size = capacity_4 + sizeof(Rep_00659FA8);
            func_00326798(this, size, 4, func_005C11A8()->field_0);
        }
    }
};
extern Rep_00659FA8 D_00659FA8;
struct String_005C2630 {
    char *field_0;
    Rep_00659FA8 *rep() const { return (Rep_00659FA8 *)field_0 - 1; }
    u32 length() const { return rep()->length_0; }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_00692090;
        terminate();
        return rep()->data();
    }
    String_005C2630 &replace(u32, u32, const char *, u32) __asm__("func_005C2630");
    String_005C2630() { field_0 = D_00659FA8.grab(); }
    String_005C2630(const char *value) {
        field_0 = D_00659FA8.grab();
        replace(0, (u32)-1, value, func_0057F260(value));
    }
    String_005C2630(const String_005C2630 &other) { field_0=other.rep()->grab(); }
    ~String_005C2630() { rep()->release(); }
};
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
struct StringRef_00314B20 : public Ref_00309348 {
    StringRef_00314B20(const String_005C2630 &) __asm__("func_00314B20");
    ~StringRef_00314B20() __asm__("func_00312318");
};
struct GarageRef_0013BDC0 : Ref_00309348 {
    GarageRef_0013BDC0(void *) __asm__("func_0013BDC0");
    ~GarageRef_0013BDC0() __asm__("func_0013BD68");
};
extern "C" void *func_00147D80(void *);
typedef long long s64;
extern "C" s64 func_00440AF0(void *);
extern "C" void func_00446EF8(s64, char *);
extern char D_0068F798[];
extern "C" void *func_005A48D8(void *, int, u32);
extern "C" void MCarGarage__getCurrentWing(Ref_00309348 *destination, void *context, int count) {
    if (count > 0) {
        s64 id;
        {
            GarageRef_0013BDC0 garage(context);
            id = func_00440AF0(func_00147D80(garage.field_0));
        }
        char name[0x40];
        __builtin_memcpy(name, D_0068F798, 5);
        func_005A48D8(name + 5, 0, 0x3b);
        func_00446EF8(id, name);
        *destination = StringRef_00314B20(name);
    }
}


