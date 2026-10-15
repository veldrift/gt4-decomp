/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long long u64;
struct Ref_00309348;
struct VEntry_58 { s16 delta_0,index_2; s32 (*function_4)(void *); };
struct Object_At04 { s32 field_0; char *vtable_4; };
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Ref_00309348 {
    void *field_0;
    Ref_00309348(const Ref_00309348 &) __asm__("func_00309360");
    ~Ref_00309348() __asm__("func_00309378");
    Ref_00309348 &operator=(const Ref_00309348 &other) {
        if(this!=&other) {
            void *value=other.field_0;
            if(value) func_003285A8(value);
            if(field_0) func_003285F8(field_0);
            field_0=value;
        }
        return *this;
    }
    s32 to_int() const {
        Object_At04 *object=(Object_At04*)field_0;
        VEntry_58 *entry=(VEntry_58*)(object->vtable_4+0x58);
        return entry->function_4((char*)object+entry->delta_0);
    }
};
struct ArrayObj_002EF9B0 {
    char unknown_00[0x10];
    void *allocator_10;
    Ref_00309348 *begin_14,*end_18,*capacity_1c;
    s32 field_20;
    s32 size() const __asm__("func_002EF9B0");
};
struct ArrayRef_002ED618 : Ref_00309348 {
    ArrayRef_002ED618(const Ref_00309348 &) __asm__("func_002ED618");
    ArrayRef_002ED618(s32) __asm__("func_002EFC48");
    ~ArrayRef_002ED618() __asm__("func_002ED5C0");
    Ref_00309348 &operator[](s32) __asm__("func_002EFCE0");
    ArrayObj_002EF9B0 *operator->() const { return (ArrayObj_002EF9B0*)field_0; }
};
struct IntegerRef_002FE278 : Ref_00309348 {
    IntegerRef_002FE278(s32) __asm__("func_002FE278");
    ~IntegerRef_002FE278() __asm__("func_002FC870");
};
struct Row_004379F0 { u64 key_00; u8 field_08,field_09; s8 field_0a,field_0b; u8 unknown_0c[4]; };
struct Playlist_00438150 { s32 count_00; u16 cursor_04; u8 shuffle_06,empty_07; u16 seed_08; u8 unknown_0a[6]; Row_004379F0 rows_10[128]; };
struct PlaylistObj_0019E5E0 { u8 unknown_00[0x10]; Playlist_00438150 *data_10; };
struct PlaylistRef_0019E508 : Ref_00309348 {
    PlaylistRef_0019E508(const Ref_00309348 &) __asm__("func_0019E508");
    ~PlaylistRef_0019E508() __asm__("func_0019E4B0");
    PlaylistObj_0019E5E0 *operator->() const { return (PlaylistObj_0019E5E0*)field_0; }
};
extern "C" void func_00438150(Playlist_00438150 *,s32);
extern "C" void func_0019E900(Ref_00309348 *destination,const Ref_00309348 &receiver,s32 count,Ref_00309348 *arguments) {
    Playlist_00438150 *data=PlaylistRef_0019E508(receiver)->data_10;
    if(count>0) {
        ArrayRef_002ED618 input(arguments[0]);
        s32 size=input->size();
        for(s32 i=0;i<size;++i) {
            ArrayRef_002ED618 row(input[i]);
            s32 a=row[0].to_int();
            s32 b=row[1].to_int();
            s32 c=row[2].to_int();
            s32 d=row[3].to_int();
            data->rows_10[i].field_0b=a;
            data->rows_10[i].field_0a=d;
            data->rows_10[i].field_08=b;
            data->rows_10[i].field_09=c;
        }
        func_00438150(data,size);
    } else {
        s32 size=data->count_00;
        ArrayRef_002ED618 result(size);
        for(s32 i=0;i<size;++i) {
            ArrayRef_002ED618 row(4);
            row[0]=IntegerRef_002FE278(data->rows_10[i].field_0b);
            row[1]=IntegerRef_002FE278(data->rows_10[i].field_08);
            row[2]=IntegerRef_002FE278(data->rows_10[i].field_09);
            row[3]=IntegerRef_002FE278(data->rows_10[i].field_0a);
            result[i]=row;
        }
        *destination=result;
    }
}
