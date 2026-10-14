/* compiler: ee-gcc2.96-as2004 */
extern "C" char *func_0053F398(char *p, int n) {
 char *result=0;
 if (p) {
  if (n) --n;
  char *q=p+n;
  if (n) {
   char *cursor=q;
   if (q[-1]) {
    do {
     --cursor;
     --n;
     if (!n) { q=p; break; }
     q=cursor;
    } while (q[-1]);
   }
  } else q=p;
  result=q;
 }
 return result;
}
