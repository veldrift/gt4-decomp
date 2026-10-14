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
extern "C" char D_0068E7F8[];
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
        if (length() == 0) return D_0068E7F8;
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
typedef long long s64;
struct CodeInfo_00448B48 {
    s64 field_00, field_08, field_10, field_18, field_20, field_28;
    unsigned char field_30;
    s64 field_38, field_40;
};
struct VEntryString_18 { s16 delta_0, index_2; String_005C2630 (*function_4)(void *); };
struct VObj_At04 { char unknown_00[4]; char *vtable_4; };
extern "C" s32 func_00448AD0(const char *, CodeInfo_00448B48 *);
extern "C" s32 func_00447CA0(s64, char *);
extern char D_0068E848[];
static inline String_005C2630 text_18(VObj_At04 *object) {
    VEntryString_18 *entry = (VEntryString_18 *)(object->vtable_4 + 0x18);
    return entry->function_4((char *)object + entry->delta_0);
}

struct CodeType_00447F48 {
    char unknown_00[0x10];
    unsigned char kind_10;
    char unknown_11[0x7];
};
extern "C" s64 func_00447C78(const char *);
extern "C" int func_00447F48(s64, CodeType_00447F48 *);
static inline unsigned int code_kind(const char *name) {
    unsigned int result = 0;
    CodeType_00447F48 type;
    if (func_00447F48(func_00447C78(name), &type)) result = type.kind_10;
    return result;
}
extern "C" void MCarData__ShiftCarCode(Ref_00309348 *destination, int count, VObj_At04 **arguments) {
    if (count >= 2) {
        const char *name = text_18(arguments[0]).c_str();
        const char *mode = text_18(arguments[1]).c_str();
        unsigned int kind = code_kind(mode);
        if (kind < 2) {
            *destination = StringRef_00314B20(name);
        } else {
            CodeInfo_00448B48 info;
            if (func_00448AD0(name, &info)) {
                s64 code = -1;
                if (kind == 2) code = info.field_38;
                else if (kind == 3) code = info.field_40;
                char mapped_code[0x80];
                if (func_00447CA0(code, mapped_code)) {
                    *destination = StringRef_00314B20(mapped_code);
                } else {
                    *destination = StringRef_00314B20(name);
                }
            } else {
                *destination = StringRef_00314B20(name);
            }
        }
    }
}
