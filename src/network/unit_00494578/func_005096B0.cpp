struct Blob { char data[100]; };
struct Request { Blob blob; short length; };
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_0050F5E8(Request *,int *);
extern "C" int func_005096B0(Blob copy,int *out) {
 Request req;
 req.blob=copy;
 short n=func_0057F260(copy.data);
 *out=0;
 req.length=n;
 return func_0050F5E8(&req,out)==0?0:-13;
}
