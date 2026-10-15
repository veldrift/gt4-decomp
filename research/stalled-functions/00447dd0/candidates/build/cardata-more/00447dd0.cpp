typedef long s64;
struct Info { s64 code; char other[0x18]; };
extern char D_006235A8[];
extern "C" int func_00443ED0(void *, s64, Info *);
static inline bool lookup(s64 id, Info *info) { return func_00443ED0(D_006235A8, id, info) != 0; }
extern "C" s64 SPEC_DATABASE__DisabledInfo__searchInfo(s64 id) {
    s64 result = id >> 32;
    if (result != 0) {
        Info info;
        bool found = lookup(id, &info);
        result = found == false ? 0 : info.code;
    }
    return result;
}
