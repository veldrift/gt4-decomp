/* compiler: ee-gcc2.96-nsa-nosib */
typedef unsigned int u32;
struct String {
    struct Rep { u32 len, cap, ref, sel; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    bool empty() const { return length() == 0; }
    void terminate() const { rep()->data()[length()] = 0; }
    const char *data() const { return dat; }
};
extern char D_00698058[];
static inline const char *c_str(const String &s) {
    if (s.length() == 0) return D_00698058;
    s.terminate();
    return s.data();
}
extern "C" int func_002208E8(char *, unsigned, const char *, const char *) throw();
extern "C" int func_002209B0(String *s, char *dst, unsigned capacity) {
    if (s->empty()) return 0;
    return func_002208E8(dst, capacity, c_str(*s), 0);
}
