/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_00400FA0(float) throw();
extern "C" float func_00401008(float x) {
 if(x>0.0f) return func_00400FA0(x);
 return -func_00400FA0(-x);
}
