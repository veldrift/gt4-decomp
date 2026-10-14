struct Arg { int value; int status; };
extern "C" {
int func_0050AF68();
int func_0050AF78();
void func_0050E828();
extern int D_0064A30C;
extern short D_0064A310;
void func_0050AEC0(Arg *p) {
 int status = p->status;
 if (status == 1) {
  D_0064A30C = p->value;
  if (D_0064A310 == status) func_0050E828();
 } else { D_0064A30C = p->value; }
 if (func_0050AF68()) {
  int v = func_0050AF78();
  ((void (*)(int,int))func_0050AF68())(D_0064A30C,v);
 }
}
}
