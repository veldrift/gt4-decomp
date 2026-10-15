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
struct ArrayRef_002EFBF0 : public Ref_00309348 {
    ArrayRef_002EFBF0() __asm__("func_002EFBF0");
    ~ArrayRef_002EFBF0() __asm__("func_002ED5C0");
    ArrayObj_002EEEB0 *operator->() const { return (ArrayObj_002EEEB0 *)field_0; }
};
struct ArrayObj_002EEEB0 {
    Ref_00309348 append(const StringRef_00314B20 &) __asm__("func_002EEEB0");
};
struct VEntryString_18 { s16 delta_0, index_2; String_005C2630 (*function_4)(void *); };
struct VEntryInt { s16 delta_0, index_2; s32 (*function_4)(void *); };
struct VEntryIndex { s16 delta_0, index_2; s32 (*function_4)(void *, s32); };
struct VObj_At04 { s32 field_0; char *vtable_4; };
struct VObj_At0C { char fields_0[0xc]; char *vtable_c; };
struct Arg_00191078 { char fields_0[8]; VObj_At04 *field_8; };
extern "C" VObj_At0C *func_001908C0(void *, Arg_00191078 *);
extern "C" s32 func_004382B0(const char *);
extern "C" const char *func_004384F8(VObj_At0C *, s32);
static inline String_005C2630 vcall18(VObj_At04 *object) {
    VEntryString_18 *entry=(VEntryString_18 *)(object->vtable_4 + 0x18);
    return entry->function_4((char *)object+entry->delta_0);
}
static inline s32 vcall20(VObj_At0C *object) {
    VEntryInt *entry=(VEntryInt *)(object->vtable_c+0x20);
    return entry->function_4((char *)object+entry->delta_0);
}
static inline s32 vcall28(VObj_At0C *object, s32 index) {
    VEntryIndex *entry=(VEntryIndex *)(object->vtable_c+0x28);
    return entry->function_4((char *)object+entry->delta_0,index);
}
extern "C" void MOption__searchAnalogConfig(Ref_00309348 *destination, void *context, s32 count, Arg_00191078 *arguments) {
    if (count >= 3) {
        VObj_At0C *object = func_001908C0(context, arguments);
        if (object) {
            const char *name=vcall18(arguments->field_8).c_str();
            s32 key=func_004382B0(name);
            s32 index=0;
            ArrayRef_002EFBF0 array;
            s32 limit=vcall20(object);
            if (limit>0) do {
                s32 value=vcall28(object,index);
                if (value==key) {
                    array->append(StringRef_00314B20(String_005C2630(func_004384F8(object,index))));
                }
                ++index;
            } while(index<limit);
            *destination=array;
        }
    }
}
