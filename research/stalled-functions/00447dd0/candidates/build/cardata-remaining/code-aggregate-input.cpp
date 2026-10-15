struct Identifier { long value; };
struct Info { long code; char other[24]; };
extern char D_006235A8[];
extern "C" int func_00443ED0(void *, long, Info *);
extern "C" long func_00447DD0(Identifier identifier, int kind) {
    long high = identifier.value >> 32;
    if (high == 0) return high;
    Info info;
    if (!func_00443ED0(D_006235A8, identifier.value, &info)) return 0;
    return info.code;
}
