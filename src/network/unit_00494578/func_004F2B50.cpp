/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Arg { char p[0x18]; int result; char rest[0xB8-0x1C]; };
struct Work { char p[0x1D8]; Arg saved; };
struct Sess { char p[0x5A8]; Work *work; };
extern Sess D_00645570;
extern "C" int func_004F0C38(Sess *,const char *) throw();
extern "C" int func_004F0B08(Sess *,Arg *) throw();
extern "C" void func_004F87E8(Sess *,int);
struct Guard {
    Sess *sess; Arg *arg;
    Guard(Sess *s,Arg *a):sess(s),arg(a) {}
    ~Guard() { func_004F0B08(sess,arg); }
};
extern "C" void func_004F2B50(Arg *arg,Sess *s) {
    if (!s) s=&D_00645570;
    Guard g(s,arg);
    if (func_004F0C38(s,"JoinChannelCallback")) return;
    int done=0;
    int result=arg->result;
    if (result < 0 || result == 1) {
        func_004F87E8(s,result);
        done=1;
    }
    if (done) return;
    s->work->saved=*arg;
    func_004F87E8(s,arg->result);
}
