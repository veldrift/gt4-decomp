/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Reader;
extern "C" int func_0020E670(Reader *) throw();
extern "C" void func_0020E6F8(Reader *, int) throw();
extern "C" int func_0020FAD8(Reader *r) {
 int c;
 while ((c = func_0020E670(r)) == '/') {
  int first = c;
  c = func_0020E670(r);
  if (c == first) {
   while ((c = func_0020E670(r)) != -1 && c != '\n') {}
   if (c == -1) return c;
  } else if (c == '*') {
   int prev = func_0020E670(r);
   if (prev != -1) {
    c = func_0020E670(r);
    if (c != -1) {
     int depth = 1;
     while (1) {
      if (prev == '*') { if (c == '/') --depth; }
      if (prev == '/') { if (c == '*') ++depth; }
      if (depth == 0) break;
      prev = c;
      c = func_0020E670(r);
      if (c == -1) return c;
     }
    } else {
     func_0020E6F8(r, c);
     func_0020E6F8(r, prev);
     func_0020E6F8(r, '*');
     return '/';
    }
   } else {
    func_0020E6F8(r, -1);
    func_0020E6F8(r, '*');
    return '/';
   }
  } else {
   func_0020E6F8(r, c);
   return '/';
  }
 }
 return c;
}
