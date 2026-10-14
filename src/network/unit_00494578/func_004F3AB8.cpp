/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Arg { int words[6]; int result; char pad[0x148-0x1C]; };
struct Inner { char pad[0x1D8]; Arg saved; };
struct Conn { char pad[0x5A8]; Inner *inner; };
extern Conn D_00645570;
extern "C" void func_004F0B08(Conn *,Arg *) throw();
extern "C" int func_004F0C38(Conn *,const char *) throw();
extern "C" void func_004F87E8(Conn *,int);
struct Guard {
    Conn *conn; Arg *arg;
    Guard(Conn *c, Arg *a) : conn(c),arg(a) {}
    ~Guard() { func_004F0B08(conn,arg); }
};
extern "C" void func_004F3AB8(Arg *arg,Conn *conn) {
    if (!conn) conn = &D_00645570;
    Guard guard(conn,arg);
    if (func_004F0C38(conn,"PlayerInfoCallback")) return;
    conn->inner->saved = *arg;
    func_004F87E8(conn,arg->result);
}
