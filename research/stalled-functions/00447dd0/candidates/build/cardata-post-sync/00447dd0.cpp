struct Identifier {
    long value;
    Identifier(long code) : value(code) {}
};
struct Info { long code, word8, word10; };
extern char D_006235A8[];
extern "C" int func_00443ED0(void *, Identifier, Info *);
extern "C" Identifier SPEC_DATABASE__DisabledInfo__searchInfo(Identifier identifier) {
    long high = identifier.value >> 32;
    if (high == 0) return Identifier(high);
    Info info;
    bool found = func_00443ED0(D_006235A8, identifier, &info) != 0;
    return Identifier(found ? info.code : 0);
}
