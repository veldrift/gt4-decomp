struct O { char pad[0x108]; char text[0x100]; unsigned offset; int error; };
extern "C" int func_0053F280(char *, unsigned *, const char *) throw();
extern "C" int func_00594470(const char *, const char *, unsigned);
extern char D_006C4EF8[], D_006C49C0[], D_006C4F08[], D_006C4F18[];
extern const char *D_0064C190, *D_0064C194, *D_0064C19C;
extern "C" void func_005404C8(const char *name, const char **attrs, O *o) {
 if (o->error == 0) {
  if (func_0053F280(o->text, &o->offset, name) == 0) o->error = 1;
  const char *p = name;
  while (*p != ':') ++p;
  if (func_00594470(D_006C4EF8, p+1, 256) == 0) {
   unsigned i=0;
   if (*attrs) {
   do {
    switch(i) {
    case 0:
     if (func_00594470(D_006C49C0, attrs[i], 5) != 0) o->error=1;
     break;
    case 1:
     if (func_00594470(D_0064C190, attrs[1], 256) != 0) o->error=i;
     break;
    case 2: {
     const char *q=attrs[2];
     while (*q != ':') ++q;
     ++q;
     if (func_00594470(D_006C4F08, q, 256) != 0) o->error=1;
     break;
    }
    case 3:
     if (func_00594470(D_0064C194, attrs[3], 256) != 0) o->error=1;
     break;
    }
    ++i;
   } while (attrs[i]);
   }
  } else if (func_00594470(D_006C4F18, name, 256) == 0) {
   unsigned i=0;
   if (*attrs) {
   do {
    switch(i) {
    case 1:
     if (func_00594470(D_006C49C0, attrs[1], 5) != 0) o->error=i;
     break;
    case 2:
     if (func_00594470(D_0064C19C, attrs[2], 256) != 0) o->error=1;
     break;
    }
    ++i;
   } while (attrs[i]);
   }
  }
 }
}
