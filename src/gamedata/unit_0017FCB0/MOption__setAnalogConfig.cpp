/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct Rep_00659FA8;
struct Heap_00659988 { const char *field_0; };
extern "C" Heap_00659988 *func_005C11A8();
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" char *func_005C2560(Rep_00659FA8 *);
extern "C" char D_00692090[];
struct Rep_00659FA8 {
    s32 length_0, capacity_4, refs_8, selfish_c;
    char *data() { return (char *)(this + 1); }
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
    String_005C2630(const String_005C2630 &other) { field_0 = other.rep()->grab(); }
    ~String_005C2630() { rep()->release(); }
};
struct VEntryString_18 { s16 delta_0, index_2; String_005C2630 (*function_4)(void *); };
struct VObj_At04 {
    s32 field_0;
    virtual void slot_08();
    virtual void slot_10();
    virtual String_005C2630 slot_18();
};
struct VObj_At0C { char unknown_0[0xc]; char *vtable_c; };
struct Arg_00190D38 { char unknown_0[8]; VObj_At04 *field_8; VObj_At04 *field_c; };
extern "C" VObj_At0C *func_001908C0(void *, Arg_00190D38 *);
extern "C" s32 func_004382B0(const char *);
extern "C" void func_004384A0(VObj_At0C *, const char *, s32);
static inline String_005C2630 vcall18(VObj_At04 *object) {
    return object->slot_18();
}
static inline const char *name_18(VObj_At04 *object) {
    String_005C2630 text = object->slot_18();
    return text.c_str();
}
extern "C" void func_00190D38(void *arg0, void *context, s32 count, Arg_00190D38 *arguments) {
    if (count >= 4) {
        VObj_At0C *object = func_001908C0(context, arguments);
        if (object) {
            const char *name = name_18(arguments->field_8);
            const char *value = name_18(arguments->field_c);
            s32 key = func_004382B0(value);
            func_004384A0(object, name, key);
        }
    }
}

