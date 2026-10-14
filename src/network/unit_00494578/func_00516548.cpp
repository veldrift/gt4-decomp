struct Result { int kind; int status; };
extern "C" int func_005165B0(int *);
extern "C" int func_00516548(int *input,Result *out) {
    if (!out) return 0x17;
    out->status = 0x1E;
    out->kind = 1;
    if (!input) {
        out->status = 0x17;
        return 0x17;
    }
    if (!*input) return 0x26;
    int r = func_005165B0(input);
    out->status = r;
    return r;
}
