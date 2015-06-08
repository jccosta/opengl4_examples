
#include <Cg/half.hpp>
#include <Cg/double.hpp>
#include <Cg/vector/xyzw.hpp>
#include <Cg/vector.hpp>
#include <Cg/iostream.hpp>
#include <Cg/dot.hpp>
#include <Cg/smoothstep.hpp>

using namespace Cg;

#define OUTPUT(_x) std::cout << #_x << "=" << (_x) << std::endl

void test_smoothstep()
{
  float scalarf = 0.2f;
  float scalari = 1;
  half scalarh = half(0.42);
  float4 foo = float4(0.1f,0.2f,0.3f,0.4f);
  half4 fooh = half4(0.1f,0.2f,0.3f,0.4f);

  OUTPUT(smoothstep(foo,foo,foo));
  OUTPUT(smoothstep(fooh,fooh,fooh));
#ifndef _MSC_VER
  OUTPUT(smoothstep(foo,foo,fooh));
  OUTPUT(smoothstep(foo,fooh,foo));
  OUTPUT(smoothstep(fooh,foo,foo));
  OUTPUT(smoothstep(4,fooh,0.95));
  OUTPUT(smoothstep(4,fooh.x,0.95));
  OUTPUT(smoothstep(4,fooh.xy,0.95));

  OUTPUT(smoothstep(0.85,foo,foo.x));
  OUTPUT(smoothstep(foo,0.95,foo.x));
  OUTPUT(smoothstep(0.85,foo.x,foo));
  OUTPUT(smoothstep(foo,foo.x,0.95));
  OUTPUT(smoothstep(0.85,foo,foo.x));
  OUTPUT(smoothstep(foo,0.95,foo.x));

  OUTPUT(smoothstep(0.85,foo.zzw,foo.x));
  OUTPUT(smoothstep(foo.zzw,0.95,foo.x));
  OUTPUT(smoothstep(0.85,foo.x,foo.zzw));
  OUTPUT(smoothstep(foo.zzw,foo.x,0.95));
  OUTPUT(smoothstep(0.85,foo.zzw,foo.x));
  OUTPUT(smoothstep(foo.zzw,0.95,foo.x));

  OUTPUT(smoothstep(foo,foo.x,foo));
  OUTPUT(smoothstep(foo.x,foo,foo.x));

  OUTPUT(smoothstep(foo.x,foo.x,foo.x));

  OUTPUT(smoothstep(4,0.95,fooh.xy));
  OUTPUT(smoothstep(foo,foo,foo.x));
  OUTPUT(smoothstep(foo,foo.x,foo.x));
  OUTPUT(smoothstep(foo.x,foo,foo));
  OUTPUT(smoothstep(foo.x,foo.x,foo));
  OUTPUT(smoothstep(foo,foo,foo.x));
  OUTPUT(smoothstep(foo,foo,fooh.x));
  OUTPUT(smoothstep(foo.xxy,foo.zzx,foo.x));
  OUTPUT(smoothstep(foo,0.95,foo));
  OUTPUT(smoothstep(foo,foo.x,foo.x));
  OUTPUT(smoothstep(foo,foo.wzxy,foo.x));
  OUTPUT(smoothstep(foo,0.95,foo));
  OUTPUT(smoothstep(foo,0.95,foo.wzxy));
  OUTPUT(smoothstep(foo,0.95,0.95));
  OUTPUT(smoothstep(foo,0.95,0.55f));
  OUTPUT(smoothstep(foo,0.95,0.9));
  OUTPUT(smoothstep(foo,0.95,scalarf));
  OUTPUT(smoothstep(foo,0.95,scalari));
  OUTPUT(smoothstep(foo,0.95,scalarh));
  OUTPUT(smoothstep(foo,0.55f,foo));
  OUTPUT(smoothstep(foo,0.55f,foo.wzxy));
  OUTPUT(smoothstep(foo,0.55f,0.95));
  OUTPUT(smoothstep(foo,0.55f,0.55f));
  OUTPUT(smoothstep(foo,0.55f,0.9));
  OUTPUT(smoothstep(foo,0.55f,scalarf));
  OUTPUT(smoothstep(foo,0.55f,scalari));
  OUTPUT(smoothstep(foo,0.55f,scalarh));
  OUTPUT(smoothstep(foo,0.9,foo));
  OUTPUT(smoothstep(foo,0.9,foo.wzxy));
  OUTPUT(smoothstep(foo,0.9,0.95));
  OUTPUT(smoothstep(foo,0.9,0.55f));
  OUTPUT(smoothstep(foo,0.9,0.9));
  OUTPUT(smoothstep(foo,0.9,scalarf));
  OUTPUT(smoothstep(foo,0.9,scalari));
  OUTPUT(smoothstep(foo,0.9,scalarh));
  OUTPUT(smoothstep(foo,scalarf,foo));
  OUTPUT(smoothstep(foo,scalarf,foo.wzxy));
  OUTPUT(smoothstep(foo,scalarf,0.95));
  OUTPUT(smoothstep(foo,scalarf,0.55f));
  OUTPUT(smoothstep(foo,scalarf,0.9));
  OUTPUT(smoothstep(foo,scalarf,scalarf));
  OUTPUT(smoothstep(foo,scalarf,scalari));
  OUTPUT(smoothstep(foo,scalarf,scalarh));
  OUTPUT(smoothstep(foo,scalari,foo));
  OUTPUT(smoothstep(foo,scalari,foo.wzxy));
  OUTPUT(smoothstep(foo,scalari,0.95));
  OUTPUT(smoothstep(foo,scalari,0.55f));
  OUTPUT(smoothstep(foo,scalari,0.9));
  OUTPUT(smoothstep(foo,scalari,scalarf));
  OUTPUT(smoothstep(foo,scalari,scalari));
  OUTPUT(smoothstep(foo,scalari,scalarh));
  OUTPUT(smoothstep(foo,scalarh,foo));
  OUTPUT(smoothstep(foo,foo,foo.xyzw));
  OUTPUT(smoothstep(foo,foo,scalarf));
  OUTPUT(smoothstep(foo,foo,5.0f));
  OUTPUT(smoothstep(foo,foo,0.55f));
  OUTPUT(smoothstep(foo,foo,0.9));
  OUTPUT(smoothstep(foo,foo,scalarf));
  OUTPUT(smoothstep(foo,foo,scalari));
  OUTPUT(smoothstep(foo,foo,scalarh));
  OUTPUT(smoothstep(foo,foo.x,foo));
  OUTPUT(smoothstep(foo,foo.x,foo.wzxy));
  OUTPUT(smoothstep(foo,foo.x,0.95));
  OUTPUT(smoothstep(foo,foo.x,0.55f));
  OUTPUT(smoothstep(foo,foo.x,0.9));
  OUTPUT(smoothstep(foo,foo.x,scalarf));
  OUTPUT(smoothstep(foo,foo.x,scalari));
  OUTPUT(smoothstep(foo,foo.x,scalarh));
  OUTPUT(smoothstep(foo,foo.wzxy,foo));
  OUTPUT(smoothstep(foo,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(foo,foo.wzxy,0.95));
  OUTPUT(smoothstep(foo,foo.wzxy,0.55f));
  OUTPUT(smoothstep(foo,foo.wzxy,0.9));
  OUTPUT(smoothstep(foo,foo.wzxy,scalarf));
  OUTPUT(smoothstep(foo,foo.wzxy,scalari));
  OUTPUT(smoothstep(foo,foo.wzxy,scalarh));
  OUTPUT(smoothstep(foo,0.95,foo.x));
  OUTPUT(smoothstep(foo,0.55f,foo.x));
  OUTPUT(smoothstep(foo,0.9,foo.x));
  OUTPUT(smoothstep(foo,scalarf,foo.x));
  OUTPUT(smoothstep(foo,scalari,foo.x));
  OUTPUT(smoothstep(foo,scalarh,foo.x));
  OUTPUT(smoothstep(foo,scalarh,foo.wzxy));
  OUTPUT(smoothstep(foo,scalarh,0.95));
  OUTPUT(smoothstep(foo,scalarh,0.55f));
  OUTPUT(smoothstep(foo,scalarh,0.9));
  OUTPUT(smoothstep(foo,scalarh,scalarf));
  OUTPUT(smoothstep(foo,scalarh,scalari));
  OUTPUT(smoothstep(foo,scalarh,scalarh));
  OUTPUT(smoothstep(foo.x,foo,foo));
  OUTPUT(smoothstep(foo.x,foo,foo.x));
  OUTPUT(smoothstep(foo.x,foo,foo.wzxy));
  OUTPUT(smoothstep(foo.x,foo,0.95));
  OUTPUT(smoothstep(foo.x,foo,0.55f));
  OUTPUT(smoothstep(foo.x,foo,0.9));
  OUTPUT(smoothstep(foo.x,foo,scalarf));
  OUTPUT(smoothstep(foo.x,foo,scalari));
  OUTPUT(smoothstep(foo.x,foo,scalarh));
  OUTPUT(smoothstep(foo.x,foo.x,foo));
  OUTPUT(smoothstep(float1(foo.x),foo.x,foo.x)); // ambigugous
  OUTPUT(smoothstep(foo.x,foo.x,foo.wzxy));
  OUTPUT(smoothstep(float1(foo.x),foo.x,0.95)); // ambigugous
  OUTPUT(smoothstep(foo.x,float1(foo.x),0.55f)); // ambigugous
  OUTPUT(smoothstep(foo.x,foo.x,float1(0.9f)));  // ambigugous
  OUTPUT(smoothstep(foo.x,float1(foo.x),scalarf));
  OUTPUT(smoothstep(foo.x,float1(foo.x),scalari));
  OUTPUT(smoothstep(foo.x,float1(foo.x),scalarh));
  OUTPUT(smoothstep(foo.x,foo.wzxy,foo));
  OUTPUT(smoothstep(foo.x,foo.wzxy,foo.x));
  OUTPUT(smoothstep(foo.x,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(foo.x,foo.wzxy,0.95));
  OUTPUT(smoothstep(foo.x,foo.wzxy,0.55f));
  OUTPUT(smoothstep(foo.x,foo.wzxy,0.9));
  OUTPUT(smoothstep(foo.x,foo.wzxy,scalarf));
  OUTPUT(smoothstep(foo.x,foo.wzxy,scalari));
  OUTPUT(smoothstep(foo.x,foo.wzxy,scalarh));
  OUTPUT(smoothstep(foo.x,0.95,foo));
  OUTPUT(smoothstep(foo.x,0.95,float1(foo.x)));
  OUTPUT(smoothstep(foo.x,0.95,foo.wzxy));
  OUTPUT(smoothstep(float1(foo.x),0.95,0.95));
  OUTPUT(smoothstep(float1(foo.x),0.95,0.55f));
  OUTPUT(smoothstep(foo.x,float1(5),0.9));
  OUTPUT(smoothstep(foo.x,float1(5),scalarf));
  OUTPUT(smoothstep(foo.x,float1(5),scalari));
  OUTPUT(smoothstep(foo.x,0.95,float1(scalarh)));
  OUTPUT(smoothstep(foo.x,0.55f,foo));
  OUTPUT(smoothstep(float1(foo.x),0.55f,foo.x));
  OUTPUT(smoothstep(foo.x,0.55f,foo.wzxy));
  OUTPUT(smoothstep(float1(foo.x),0.55f,0.95));
  OUTPUT(smoothstep(float1(foo.x),0.55f,0.55f));
  OUTPUT(smoothstep(float1(foo.x),0.55f,0.9));
  OUTPUT(smoothstep(float1(foo.x),0.55f,scalarf));
  OUTPUT(smoothstep(foo.x,0.55f,float1(scalari)));
  OUTPUT(smoothstep(foo.x,0.55f,float1(scalarh)));
  OUTPUT(smoothstep(foo.x,0.9,foo));
  OUTPUT(smoothstep(foo.x,0.9,foo.x));
  OUTPUT(smoothstep(foo.x,0.9,foo.wzxy));
  OUTPUT(smoothstep(foo.x,0.9,0.95));
  OUTPUT(smoothstep(foo.x,0.9,0.55f));
  OUTPUT(smoothstep(foo.x,0.9,0.9));
  OUTPUT(smoothstep(foo.x,0.9,scalarf));
  OUTPUT(smoothstep(foo.x,0.9,scalari));
  OUTPUT(smoothstep(foo.x,0.9,scalarh));
  OUTPUT(smoothstep(foo.x,scalarf,foo));
  OUTPUT(smoothstep(foo.x,scalarf,foo.x));
  OUTPUT(smoothstep(foo.x,scalarf,foo.wzxy));
  OUTPUT(smoothstep(foo.x,scalarf,0.95));
  OUTPUT(smoothstep(foo.x,scalarf,0.55f));
  OUTPUT(smoothstep(foo.x,scalarf,0.9));
  OUTPUT(smoothstep(foo.x,scalarf,scalarf));
  OUTPUT(smoothstep(foo.x,scalarf,scalari));
  OUTPUT(smoothstep(foo.x,scalarf,scalarh));
  OUTPUT(smoothstep(foo.x,scalari,foo));
  OUTPUT(smoothstep(foo.x,scalari,foo.x));
  OUTPUT(smoothstep(foo.x,scalari,foo.wzxy));
  OUTPUT(smoothstep(foo.x,scalari,0.95));
  OUTPUT(smoothstep(foo.x,scalari,0.55f));
  OUTPUT(smoothstep(foo.x,scalari,0.9));
  OUTPUT(smoothstep(foo.x,scalari,scalarf));
  OUTPUT(smoothstep(foo.x,scalari,scalari));
  OUTPUT(smoothstep(foo.x,scalari,scalarh));
  OUTPUT(smoothstep(foo.x,scalarh,foo));
  OUTPUT(smoothstep(foo.x,scalarh,foo.x));
  OUTPUT(smoothstep(foo.x,scalarh,foo.wzxy));
  OUTPUT(smoothstep(foo.x,scalarh,0.95));
  OUTPUT(smoothstep(foo.x,scalarh,0.55f));
  OUTPUT(smoothstep(foo.x,scalarh,0.9));
  OUTPUT(smoothstep(foo.x,scalarh,scalarf));
  OUTPUT(smoothstep(foo.x,scalarh,scalari));
  OUTPUT(smoothstep(foo.x,scalarh,scalarh));
  OUTPUT(smoothstep(foo.wzxy,foo,foo));
  OUTPUT(smoothstep(foo.wzxy,foo,foo.x));
  OUTPUT(smoothstep(foo.wzxy,foo,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,foo,0.95));
  OUTPUT(smoothstep(foo.wzxy,foo,0.55f));
  OUTPUT(smoothstep(foo.wzxy,foo,0.9));
  OUTPUT(smoothstep(foo.wzxy,foo,scalarf));
  OUTPUT(smoothstep(foo.wzxy,foo,scalari));
  OUTPUT(smoothstep(foo.wzxy,foo,scalarh));
  OUTPUT(smoothstep(foo.wzxy,foo.x,foo));
  OUTPUT(smoothstep(foo.wzxy,foo.x,foo.x));
  OUTPUT(smoothstep(foo.wzxy,foo.x,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,foo.x,0.95));
  OUTPUT(smoothstep(foo.wzxy,foo.x,0.55f));
  OUTPUT(smoothstep(foo.wzxy,foo.x,0.9));
  OUTPUT(smoothstep(foo.wzxy,foo.x,scalarf));
  OUTPUT(smoothstep(foo.wzxy,foo.x,scalari));
  OUTPUT(smoothstep(foo.wzxy,foo.x,scalarh));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,foo));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,foo.x));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,0.95));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,0.55f));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,0.9));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,scalarf));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,scalari));
  OUTPUT(smoothstep(foo.wzxy,foo.wzxy,scalarh));
  OUTPUT(smoothstep(foo.wzxy,0.95,foo));
  OUTPUT(smoothstep(foo.wzxy,0.95,foo.x));
  OUTPUT(smoothstep(foo.wzxy,0.95,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,0.95,0.95));
  OUTPUT(smoothstep(foo.wzxy,0.95,0.55f));
  OUTPUT(smoothstep(foo.wzxy,0.95,0.9));
  OUTPUT(smoothstep(foo.wzxy,0.95,scalarf));
  OUTPUT(smoothstep(foo.wzxy,0.95,scalari));
  OUTPUT(smoothstep(foo.wzxy,0.95,scalarh));
  OUTPUT(smoothstep(foo.wzxy,0.55f,foo));
  OUTPUT(smoothstep(foo.wzxy,0.55f,foo.x));
  OUTPUT(smoothstep(foo.wzxy,0.55f,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,0.55f,0.95));
  OUTPUT(smoothstep(foo.wzxy,0.55f,0.55f));
  OUTPUT(smoothstep(foo.wzxy,0.55f,0.9));
  OUTPUT(smoothstep(foo.wzxy,0.55f,scalarf));
  OUTPUT(smoothstep(foo.wzxy,0.55f,scalari));
  OUTPUT(smoothstep(foo.wzxy,0.55f,scalarh));
  OUTPUT(smoothstep(foo.wzxy,0.9,foo));
  OUTPUT(smoothstep(foo.wzxy,0.9,foo.x));
  OUTPUT(smoothstep(foo.wzxy,0.9,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,0.9,0.95));
  OUTPUT(smoothstep(foo.wzxy,0.9,0.55f));
  OUTPUT(smoothstep(foo.wzxy,0.9,0.9));
  OUTPUT(smoothstep(foo.wzxy,0.9,scalarf));
  OUTPUT(smoothstep(foo.wzxy,0.9,scalari));
  OUTPUT(smoothstep(foo.wzxy,0.9,scalarh));
  OUTPUT(smoothstep(foo.wzxy,scalarf,foo));
  OUTPUT(smoothstep(foo.wzxy,scalarf,foo.x));
  OUTPUT(smoothstep(foo.wzxy,scalarf,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,scalarf,0.95));
  OUTPUT(smoothstep(foo.wzxy,scalarf,0.55f));
  OUTPUT(smoothstep(foo.wzxy,scalarf,0.9));
  OUTPUT(smoothstep(foo.wzxy,scalarf,scalarf));
  OUTPUT(smoothstep(foo.wzxy,scalarf,scalari));
  OUTPUT(smoothstep(foo.wzxy,scalarf,scalarh));
  OUTPUT(smoothstep(foo.wzxy,scalari,foo));
  OUTPUT(smoothstep(foo.wzxy,scalari,foo.x));
  OUTPUT(smoothstep(foo.wzxy,scalari,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,scalari,0.95));
  OUTPUT(smoothstep(foo.wzxy,scalari,0.55f));
  OUTPUT(smoothstep(foo.wzxy,scalari,0.9));
  OUTPUT(smoothstep(foo.wzxy,scalari,scalarf));
  OUTPUT(smoothstep(foo.wzxy,scalari,scalari));
  OUTPUT(smoothstep(foo.wzxy,scalari,scalarh));
  OUTPUT(smoothstep(foo.wzxy,scalarh,foo));
  OUTPUT(smoothstep(foo.wzxy,scalarh,foo.x));
  OUTPUT(smoothstep(foo.wzxy,scalarh,foo.wzxy));
  OUTPUT(smoothstep(foo.wzxy,scalarh,0.95));
  OUTPUT(smoothstep(foo.wzxy,scalarh,0.55f));
  OUTPUT(smoothstep(foo.wzxy,scalarh,0.9));
  OUTPUT(smoothstep(foo.wzxy,scalarh,scalarf));
  OUTPUT(smoothstep(foo.wzxy,scalarh,scalari));
  OUTPUT(smoothstep(foo.wzxy,scalarh,scalarh));
  OUTPUT(smoothstep(0.85,foo,foo));
  OUTPUT(smoothstep(0.85,foo,foo.x));
  OUTPUT(smoothstep(0.85,foo,foo.wzxy));
  OUTPUT(smoothstep(0.85,foo,0.95));
  OUTPUT(smoothstep(0.85,foo,0.55f));
  OUTPUT(smoothstep(0.85,foo,0.9));
  OUTPUT(smoothstep(0.85,foo,scalarf));
  OUTPUT(smoothstep(0.85,foo,scalari));
  OUTPUT(smoothstep(0.85,foo,scalarh));
  OUTPUT(smoothstep(0.85,foo.x,foo));
  OUTPUT(smoothstep(0.85,foo.x,foo.x));
  OUTPUT(smoothstep(0.85,foo.x,foo.wzxy));
  OUTPUT(smoothstep(0.85,foo.x,0.95));
  OUTPUT(smoothstep(0.85,foo.x,0.55f));
  OUTPUT(smoothstep(0.85,foo.x,0.9));
  OUTPUT(smoothstep(0.85,foo.x,scalarf));
  OUTPUT(smoothstep(0.85,foo.x,scalari));
  OUTPUT(smoothstep(0.85,foo.x,scalarh));
  OUTPUT(smoothstep(0.85,foo.wzxy,foo));
  OUTPUT(smoothstep(0.85,foo.wzxy,foo.x));
  OUTPUT(smoothstep(0.85,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(0.85,foo.wzxy,0.95));
  OUTPUT(smoothstep(0.85,foo.wzxy,0.55f));
  OUTPUT(smoothstep(0.85,foo.wzxy,0.9));
  OUTPUT(smoothstep(0.85,foo.wzxy,scalarf));
  OUTPUT(smoothstep(0.85,foo.wzxy,scalari));
  OUTPUT(smoothstep(0.85,foo.wzxy,scalarh));
  OUTPUT(smoothstep(0.85,0.95,foo));
  OUTPUT(smoothstep(0.85,0.95,foo.x));
  OUTPUT(smoothstep(0.85,0.95,foo.wzxy));
  OUTPUT(smoothstep(0.85,0.95,0.95));
  OUTPUT(smoothstep(0.85,0.95,0.55f));
  OUTPUT(smoothstep(0.85,0.95,0.9));
  OUTPUT(smoothstep(0.85,0.95,scalarf));
  OUTPUT(smoothstep(0.85,0.95,scalari));
  OUTPUT(smoothstep(0.85,0.95,scalarh));
  OUTPUT(smoothstep(0.85,0.55f,foo));
  OUTPUT(smoothstep(0.85,0.55f,foo.x));
  OUTPUT(smoothstep(0.85,0.55f,foo.wzxy));
  OUTPUT(smoothstep(0.85,0.55f,0.95));
  OUTPUT(smoothstep(0.85,0.55f,0.55f));
  OUTPUT(smoothstep(0.85,0.55f,0.9));
  OUTPUT(smoothstep(0.85,0.55f,scalarf));
  OUTPUT(smoothstep(0.85,0.55f,scalari));
  OUTPUT(smoothstep(0.85,0.55f,scalarh));
  OUTPUT(smoothstep(0.85,0.9,foo));
  OUTPUT(smoothstep(0.85,0.9,foo.x));
  OUTPUT(smoothstep(0.85,0.9,foo.wzxy));
  OUTPUT(smoothstep(0.85,0.9,0.95));
  OUTPUT(smoothstep(0.85,0.9,0.55f));
  OUTPUT(smoothstep(0.85,0.9,0.9));
  OUTPUT(smoothstep(0.85,0.9,scalarf));
  OUTPUT(smoothstep(0.85,0.9,scalari));
  OUTPUT(smoothstep(0.85,0.9,scalarh));
  OUTPUT(smoothstep(0.85,scalarf,foo));
  OUTPUT(smoothstep(0.85,scalarf,foo.x));
  OUTPUT(smoothstep(0.85,scalarf,foo.wzxy));
  OUTPUT(smoothstep(0.85,scalarf,0.95));
  OUTPUT(smoothstep(0.85,scalarf,0.55f));
  OUTPUT(smoothstep(0.85,scalarf,0.9));
  OUTPUT(smoothstep(0.85,scalarf,scalarf));
  OUTPUT(smoothstep(0.85,scalarf,scalari));
  OUTPUT(smoothstep(0.85,scalarf,scalarh));
  OUTPUT(smoothstep(0.85,scalari,foo));
  OUTPUT(smoothstep(0.85,scalari,foo.x));
  OUTPUT(smoothstep(0.85,scalari,foo.wzxy));
  OUTPUT(smoothstep(0.85,scalari,0.95));
  OUTPUT(smoothstep(0.85,scalari,0.55f));
  OUTPUT(smoothstep(0.85,scalari,0.9));
  OUTPUT(smoothstep(0.85,scalari,scalarf));
  OUTPUT(smoothstep(0.85,scalari,scalari));
  OUTPUT(smoothstep(0.85,scalari,scalarh));
  OUTPUT(smoothstep(0.85,scalarh,foo));
  OUTPUT(smoothstep(0.85,scalarh,foo.x));
  OUTPUT(smoothstep(0.85,scalarh,foo.wzxy));
  OUTPUT(smoothstep(0.85,scalarh,0.95));
  OUTPUT(smoothstep(0.85,scalarh,0.55f));
  OUTPUT(smoothstep(0.85,scalarh,0.9));
  OUTPUT(smoothstep(0.85,scalarh,scalarf));
  OUTPUT(smoothstep(0.85,scalarh,scalari));
  OUTPUT(smoothstep(0.85,scalarh,scalarh));
  OUTPUT(smoothstep(0.55f,foo,foo));
  OUTPUT(smoothstep(0.55f,foo,foo.x));
  OUTPUT(smoothstep(0.55f,foo,foo.wzxy));
  OUTPUT(smoothstep(0.55f,foo,0.95));
  OUTPUT(smoothstep(0.55f,foo,0.55f));
  OUTPUT(smoothstep(0.55f,foo,0.9));
  OUTPUT(smoothstep(0.55f,foo,scalarf));
  OUTPUT(smoothstep(0.55f,foo,scalari));
  OUTPUT(smoothstep(0.55f,foo,scalarh));
  OUTPUT(smoothstep(0.55f,foo.x,foo));
  OUTPUT(smoothstep(0.55f,foo.x,foo.x));
  OUTPUT(smoothstep(0.55f,foo.x,foo.wzxy));
  OUTPUT(smoothstep(0.55f,foo.x,0.95));
  OUTPUT(smoothstep(0.55f,foo.x,0.55f));
  OUTPUT(smoothstep(0.55f,foo.x,0.9));
  OUTPUT(smoothstep(0.55f,foo.x,scalarf));
  OUTPUT(smoothstep(0.55f,foo.x,scalari));
  OUTPUT(smoothstep(0.55f,foo.x,scalarh));
  OUTPUT(smoothstep(0.55f,foo.wzxy,foo));
  OUTPUT(smoothstep(0.55f,foo.wzxy,foo.x));
  OUTPUT(smoothstep(0.55f,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(0.55f,foo.wzxy,0.95));
  OUTPUT(smoothstep(0.55f,foo.wzxy,0.55f));
  OUTPUT(smoothstep(0.55f,foo.wzxy,0.9));
  OUTPUT(smoothstep(0.55f,foo.wzxy,scalarf));
  OUTPUT(smoothstep(0.55f,foo.wzxy,scalari));
  OUTPUT(smoothstep(0.55f,foo.wzxy,scalarh));
  OUTPUT(smoothstep(0.55f,0.95,foo));
  OUTPUT(smoothstep(0.55f,0.95,foo.x));
  OUTPUT(smoothstep(0.55f,0.95,foo.wzxy));
  OUTPUT(smoothstep(0.55f,0.95,0.95));
  OUTPUT(smoothstep(0.55f,0.95,0.55f));
  OUTPUT(smoothstep(0.55f,0.95,0.9));
  OUTPUT(smoothstep(0.55f,0.95,scalarf));
  OUTPUT(smoothstep(0.55f,0.95,scalari));
  OUTPUT(smoothstep(0.55f,0.95,scalarh));
  OUTPUT(smoothstep(0.55f,0.55f,foo));
  OUTPUT(smoothstep(0.55f,0.55f,foo.x));
  OUTPUT(smoothstep(0.55f,0.55f,foo.wzxy));
  OUTPUT(smoothstep(0.55f,0.55f,0.95));
  OUTPUT(smoothstep(0.55f,0.55f,0.55f));
  OUTPUT(smoothstep(0.55f,0.55f,0.9));
  OUTPUT(smoothstep(0.55f,0.55f,scalarf));
  OUTPUT(smoothstep(0.55f,0.55f,scalari));
  OUTPUT(smoothstep(0.55f,0.55f,scalarh));
  OUTPUT(smoothstep(0.55f,0.9,foo));
  OUTPUT(smoothstep(0.55f,0.9,foo.x));
  OUTPUT(smoothstep(0.55f,0.9,foo.wzxy));
  OUTPUT(smoothstep(0.55f,0.9,0.95));
  OUTPUT(smoothstep(0.55f,0.9,0.55f));
  OUTPUT(smoothstep(0.55f,0.9,0.9));
  OUTPUT(smoothstep(0.55f,0.9,scalarf));
  OUTPUT(smoothstep(0.55f,0.9,scalari));
  OUTPUT(smoothstep(0.55f,0.9,scalarh));
  OUTPUT(smoothstep(0.55f,scalarf,foo));
  OUTPUT(smoothstep(0.55f,scalarf,foo.x));
  OUTPUT(smoothstep(0.55f,scalarf,foo.wzxy));
  OUTPUT(smoothstep(0.55f,scalarf,0.95));
  OUTPUT(smoothstep(0.55f,scalarf,0.55f));
  OUTPUT(smoothstep(0.55f,scalarf,0.9));
  OUTPUT(smoothstep(0.55f,scalarf,scalarf));
  OUTPUT(smoothstep(0.55f,scalarf,scalari));
  OUTPUT(smoothstep(0.55f,scalarf,scalarh));
  OUTPUT(smoothstep(0.55f,scalari,foo));
  OUTPUT(smoothstep(0.55f,scalari,foo.x));
  OUTPUT(smoothstep(0.55f,scalari,foo.wzxy));
  OUTPUT(smoothstep(0.55f,scalari,0.95));
  OUTPUT(smoothstep(0.55f,scalari,0.55f));
  OUTPUT(smoothstep(0.55f,scalari,0.9));
  OUTPUT(smoothstep(0.55f,scalari,scalarf));
  OUTPUT(smoothstep(0.55f,scalari,scalari));
  OUTPUT(smoothstep(0.55f,scalari,scalarh));
  OUTPUT(smoothstep(0.55f,scalarh,foo));
  OUTPUT(smoothstep(0.55f,scalarh,foo.x));
  OUTPUT(smoothstep(0.55f,scalarh,foo.wzxy));
  OUTPUT(smoothstep(0.55f,scalarh,0.95));
  OUTPUT(smoothstep(0.55f,scalarh,0.55f));
  OUTPUT(smoothstep(0.55f,scalarh,0.9));
  OUTPUT(smoothstep(0.55f,scalarh,scalarf));
  OUTPUT(smoothstep(0.55f,scalarh,scalari));
  OUTPUT(smoothstep(0.55f,scalarh,scalarh));
  OUTPUT(smoothstep(0.9,foo,foo));
  OUTPUT(smoothstep(0.9,foo,foo.x));
  OUTPUT(smoothstep(0.9,foo,foo.wzxy));
  OUTPUT(smoothstep(0.9,foo,0.95));
  OUTPUT(smoothstep(0.9,foo,0.55f));
  OUTPUT(smoothstep(0.9,foo,0.9));
  OUTPUT(smoothstep(0.9,foo,scalarf));
  OUTPUT(smoothstep(0.9,foo,scalari));
  OUTPUT(smoothstep(0.9,foo,scalarh));
  OUTPUT(smoothstep(0.9,foo.x,foo));
  OUTPUT(smoothstep(0.9,foo.x,foo.x));
  OUTPUT(smoothstep(0.9,foo.x,foo.wzxy));
  OUTPUT(smoothstep(0.9,foo.x,0.95));
  OUTPUT(smoothstep(0.9,foo.x,0.55f));
  OUTPUT(smoothstep(0.9,foo.x,0.9));
  OUTPUT(smoothstep(0.9,foo.x,scalarf));
  OUTPUT(smoothstep(0.9,foo.x,scalari));
  OUTPUT(smoothstep(0.9,foo.x,scalarh));
  OUTPUT(smoothstep(0.9,foo.wzxy,foo));
  OUTPUT(smoothstep(0.9,foo.wzxy,foo.x));
  OUTPUT(smoothstep(0.9,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(0.9,foo.wzxy,0.95));
  OUTPUT(smoothstep(0.9,foo.wzxy,0.55f));
  OUTPUT(smoothstep(0.9,foo.wzxy,0.9));
  OUTPUT(smoothstep(0.9,foo.wzxy,scalarf));
  OUTPUT(smoothstep(0.9,foo.wzxy,scalari));
  OUTPUT(smoothstep(0.9,foo.wzxy,scalarh));
  OUTPUT(smoothstep(0.9,0.95,foo));
  OUTPUT(smoothstep(0.9,0.95,foo.x));
  OUTPUT(smoothstep(0.9,0.95,foo.wzxy));
  OUTPUT(smoothstep(0.9,0.95,0.95));
  OUTPUT(smoothstep(0.9,0.95,0.55f));
  OUTPUT(smoothstep(0.9,0.95,0.9));
  OUTPUT(smoothstep(0.9,0.95,scalarf));
  OUTPUT(smoothstep(0.9,0.95,scalari));
  OUTPUT(smoothstep(0.9,0.95,scalarh));
  OUTPUT(smoothstep(0.9,0.55f,foo));
  OUTPUT(smoothstep(0.9,0.55f,foo.x));
  OUTPUT(smoothstep(0.9,0.55f,foo.wzxy));
  OUTPUT(smoothstep(0.9,0.55f,0.95));
  OUTPUT(smoothstep(0.9,0.55f,0.55f));
  OUTPUT(smoothstep(0.9,0.55f,0.9));
  OUTPUT(smoothstep(0.9,0.55f,scalarf));
  OUTPUT(smoothstep(0.9,0.55f,scalari));
  OUTPUT(smoothstep(0.9,0.55f,scalarh));
  OUTPUT(smoothstep(0.9,0.9,foo));
  OUTPUT(smoothstep(0.9,0.9,foo.x));
  OUTPUT(smoothstep(0.9,0.9,foo.wzxy));
  OUTPUT(smoothstep(0.9,0.9,0.95));
  OUTPUT(smoothstep(0.9,0.9,0.55f));
  OUTPUT(smoothstep(0.9,0.9,0.9));
  OUTPUT(smoothstep(0.9,0.9,scalarf));
  OUTPUT(smoothstep(0.9,0.9,scalari));
  OUTPUT(smoothstep(0.9,0.9,scalarh));
  OUTPUT(smoothstep(0.9,scalarf,foo));
  OUTPUT(smoothstep(0.9,scalarf,foo.x));
  OUTPUT(smoothstep(0.9,scalarf,foo.wzxy));
  OUTPUT(smoothstep(0.9,scalarf,0.95));
  OUTPUT(smoothstep(0.9,scalarf,0.55f));
  OUTPUT(smoothstep(0.9,scalarf,0.9));
  OUTPUT(smoothstep(0.9,scalarf,scalarf));
  OUTPUT(smoothstep(0.9,scalarf,scalari));
  OUTPUT(smoothstep(0.9,scalarf,scalarh));
  OUTPUT(smoothstep(0.9,scalari,foo));
  OUTPUT(smoothstep(0.9,scalari,foo.x));
  OUTPUT(smoothstep(0.9,scalari,foo.wzxy));
  OUTPUT(smoothstep(0.9,scalari,0.95));
  OUTPUT(smoothstep(0.9,scalari,0.55f));
  OUTPUT(smoothstep(0.9,scalari,0.9));
  OUTPUT(smoothstep(0.9,scalari,scalarf));
  OUTPUT(smoothstep(0.9,scalari,scalari));
  OUTPUT(smoothstep(0.9,scalari,scalarh));
  OUTPUT(smoothstep(0.9,scalarh,foo));
  OUTPUT(smoothstep(0.9,scalarh,foo.x));
  OUTPUT(smoothstep(0.9,scalarh,foo.wzxy));
  OUTPUT(smoothstep(0.9,scalarh,0.95));
  OUTPUT(smoothstep(0.9,scalarh,0.55f));
  OUTPUT(smoothstep(0.9,scalarh,0.9));
  OUTPUT(smoothstep(0.9,scalarh,scalarf));
  OUTPUT(smoothstep(0.9,scalarh,scalari));
  OUTPUT(smoothstep(0.9,scalarh,scalarh));
  OUTPUT(smoothstep(scalarf,foo,foo));
  OUTPUT(smoothstep(scalarf,foo,foo.x));
  OUTPUT(smoothstep(scalarf,foo,foo.wzxy));
  OUTPUT(smoothstep(scalarf,foo,0.95));
  OUTPUT(smoothstep(scalarf,foo,0.55f));
  OUTPUT(smoothstep(scalarf,foo,0.9));
  OUTPUT(smoothstep(scalarf,foo,scalarf));
  OUTPUT(smoothstep(scalarf,foo,scalari));
  OUTPUT(smoothstep(scalarf,foo,scalarh));
  OUTPUT(smoothstep(scalarf,foo.x,foo));
  OUTPUT(smoothstep(scalarf,foo.x,foo.x));
  OUTPUT(smoothstep(scalarf,foo.x,foo.wzxy));
  OUTPUT(smoothstep(scalarf,foo.x,0.95));
  OUTPUT(smoothstep(scalarf,foo.x,0.55f));
  OUTPUT(smoothstep(scalarf,foo.x,0.9));
  OUTPUT(smoothstep(scalarf,foo.x,scalarf));
  OUTPUT(smoothstep(scalarf,foo.x,scalari));
  OUTPUT(smoothstep(scalarf,foo.x,scalarh));
  OUTPUT(smoothstep(scalarf,foo.wzxy,foo));
  OUTPUT(smoothstep(scalarf,foo.wzxy,foo.x));
  OUTPUT(smoothstep(scalarf,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(scalarf,foo.wzxy,0.95));
  OUTPUT(smoothstep(scalarf,foo.wzxy,0.55f));
  OUTPUT(smoothstep(scalarf,foo.wzxy,0.9));
  OUTPUT(smoothstep(scalarf,foo.wzxy,scalarf));
  OUTPUT(smoothstep(scalarf,foo.wzxy,scalari));
  OUTPUT(smoothstep(scalarf,foo.wzxy,scalarh));
  OUTPUT(smoothstep(scalarf,0.95,foo));
  OUTPUT(smoothstep(scalarf,0.95,foo.x));
  OUTPUT(smoothstep(scalarf,0.95,foo.wzxy));
  OUTPUT(smoothstep(scalarf,0.95,0.95));
  OUTPUT(smoothstep(scalarf,0.95,0.55f));
  OUTPUT(smoothstep(scalarf,0.95,0.9));
  OUTPUT(smoothstep(scalarf,0.95,scalarf));
  OUTPUT(smoothstep(scalarf,0.95,scalari));
  OUTPUT(smoothstep(scalarf,0.95,scalarh));
  OUTPUT(smoothstep(scalarf,0.55f,foo));
  OUTPUT(smoothstep(scalarf,0.55f,foo.x));
  OUTPUT(smoothstep(scalarf,0.55f,foo.wzxy));
  OUTPUT(smoothstep(scalarf,0.55f,0.95));
  OUTPUT(smoothstep(scalarf,0.55f,0.55f));
  OUTPUT(smoothstep(scalarf,0.55f,0.9));
  OUTPUT(smoothstep(scalarf,0.55f,scalarf));
  OUTPUT(smoothstep(scalarf,0.55f,scalari));
  OUTPUT(smoothstep(scalarf,0.55f,scalarh));
  OUTPUT(smoothstep(scalarf,0.9,foo));
  OUTPUT(smoothstep(scalarf,0.9,foo.x));
  OUTPUT(smoothstep(scalarf,0.9,foo.wzxy));
  OUTPUT(smoothstep(scalarf,0.9,0.95));
  OUTPUT(smoothstep(scalarf,0.9,0.55f));
  OUTPUT(smoothstep(scalarf,0.9,0.9));
  OUTPUT(smoothstep(scalarf,0.9,scalarf));
  OUTPUT(smoothstep(scalarf,0.9,scalari));
  OUTPUT(smoothstep(scalarf,0.9,scalarh));
  OUTPUT(smoothstep(scalarf,scalarf,foo));
  OUTPUT(smoothstep(scalarf,scalarf,foo.x));
  OUTPUT(smoothstep(scalarf,scalarf,foo.wzxy));
  OUTPUT(smoothstep(scalarf,scalarf,0.95));
  OUTPUT(smoothstep(scalarf,scalarf,0.55f));
  OUTPUT(smoothstep(scalarf,scalarf,0.9));
  OUTPUT(smoothstep(scalarf,scalarf,scalarf));
  OUTPUT(smoothstep(scalarf,scalarf,scalari));
  OUTPUT(smoothstep(scalarf,scalarf,scalarh));
  OUTPUT(smoothstep(scalarf,scalari,foo));
  OUTPUT(smoothstep(scalarf,scalari,foo.x));
  OUTPUT(smoothstep(scalarf,scalari,foo.wzxy));
  OUTPUT(smoothstep(scalarf,scalari,0.95));
  OUTPUT(smoothstep(scalarf,scalari,0.55f));
  OUTPUT(smoothstep(scalarf,scalari,0.9));
  OUTPUT(smoothstep(scalarf,scalari,scalarf));
  OUTPUT(smoothstep(scalarf,scalari,scalari));
  OUTPUT(smoothstep(scalarf,scalari,scalarh));
  OUTPUT(smoothstep(scalarf,scalarh,foo));
  OUTPUT(smoothstep(scalarf,scalarh,foo.x));
  OUTPUT(smoothstep(scalarf,scalarh,foo.wzxy));
  OUTPUT(smoothstep(scalarf,scalarh,0.95));
  OUTPUT(smoothstep(scalarf,scalarh,0.55f));
  OUTPUT(smoothstep(scalarf,scalarh,0.9));
  OUTPUT(smoothstep(scalarf,scalarh,scalarf));
  OUTPUT(smoothstep(scalarf,scalarh,scalari));
  OUTPUT(smoothstep(scalarf,scalarh,scalarh));
  OUTPUT(smoothstep(scalari,foo,foo));
  OUTPUT(smoothstep(scalari,foo,foo.x));
  OUTPUT(smoothstep(scalari,foo,foo.wzxy));
  OUTPUT(smoothstep(scalari,foo,0.95));
  OUTPUT(smoothstep(scalari,foo,0.55f));
  OUTPUT(smoothstep(scalari,foo,0.9));
  OUTPUT(smoothstep(scalari,foo,scalarf));
  OUTPUT(smoothstep(scalari,foo,scalari));
  OUTPUT(smoothstep(scalari,foo,scalarh));
  OUTPUT(smoothstep(scalari,foo.x,foo));
  OUTPUT(smoothstep(scalari,foo.x,foo.x));
  OUTPUT(smoothstep(scalari,foo.x,foo.wzxy));
  OUTPUT(smoothstep(scalari,foo.x,0.95));
  OUTPUT(smoothstep(scalari,foo.x,0.55f));
  OUTPUT(smoothstep(scalari,foo.x,0.9));
  OUTPUT(smoothstep(scalari,foo.x,scalarf));
  OUTPUT(smoothstep(scalari,foo.x,scalari));
  OUTPUT(smoothstep(scalari,foo.x,scalarh));
  OUTPUT(smoothstep(scalari,foo.wzxy,foo));
  OUTPUT(smoothstep(scalari,foo.wzxy,foo.x));
  OUTPUT(smoothstep(scalari,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(scalari,foo.wzxy,0.95));
  OUTPUT(smoothstep(scalari,foo.wzxy,0.55f));
  OUTPUT(smoothstep(scalari,foo.wzxy,0.9));
  OUTPUT(smoothstep(scalari,foo.wzxy,scalarf));
  OUTPUT(smoothstep(scalari,foo.wzxy,scalari));
  OUTPUT(smoothstep(scalari,foo.wzxy,scalarh));
  OUTPUT(smoothstep(scalari,0.95,foo));
  OUTPUT(smoothstep(scalari,0.95,foo.x));
  OUTPUT(smoothstep(scalari,0.95,foo.wzxy));
  OUTPUT(smoothstep(scalari,0.95,0.95));
  OUTPUT(smoothstep(scalari,0.95,0.55f));
  OUTPUT(smoothstep(scalari,0.95,0.9));
  OUTPUT(smoothstep(scalari,0.95,scalarf));
  OUTPUT(smoothstep(scalari,0.95,scalari));
  OUTPUT(smoothstep(scalari,0.95,scalarh));
  OUTPUT(smoothstep(scalari,0.55f,foo));
  OUTPUT(smoothstep(scalari,0.55f,foo.x));
  OUTPUT(smoothstep(scalari,0.55f,foo.wzxy));
  OUTPUT(smoothstep(scalari,0.55f,0.95));
  OUTPUT(smoothstep(scalari,0.55f,0.55f));
  OUTPUT(smoothstep(scalari,0.55f,0.9));
  OUTPUT(smoothstep(scalari,0.55f,scalarf));
  OUTPUT(smoothstep(scalari,0.55f,scalari));
  OUTPUT(smoothstep(scalari,0.55f,scalarh));
  OUTPUT(smoothstep(scalari,0.9,foo));
  OUTPUT(smoothstep(scalari,0.9,foo.x));
  OUTPUT(smoothstep(scalari,0.9,foo.wzxy));
  OUTPUT(smoothstep(scalari,0.9,0.95));
  OUTPUT(smoothstep(scalari,0.9,0.55f));
  OUTPUT(smoothstep(scalari,0.9,0.9));
  OUTPUT(smoothstep(scalari,0.9,scalarf));
  OUTPUT(smoothstep(scalari,0.9,scalari));
  OUTPUT(smoothstep(scalari,0.9,scalarh));
  OUTPUT(smoothstep(scalari,scalarf,foo));
  OUTPUT(smoothstep(scalari,scalarf,foo.x));
  OUTPUT(smoothstep(scalari,scalarf,foo.wzxy));
  OUTPUT(smoothstep(scalari,scalarf,0.95));
  OUTPUT(smoothstep(scalari,scalarf,0.55f));
  OUTPUT(smoothstep(scalari,scalarf,0.9));
  OUTPUT(smoothstep(scalari,scalarf,scalarf));
  OUTPUT(smoothstep(scalari,scalarf,scalari));
  OUTPUT(smoothstep(scalari,scalarf,scalarh));
  OUTPUT(smoothstep(scalari,scalari,foo));
  OUTPUT(smoothstep(scalari,scalari,foo.x));
  OUTPUT(smoothstep(scalari,scalari,foo.wzxy));
  OUTPUT(smoothstep(scalari,scalari,0.95));
  OUTPUT(smoothstep(scalari,scalari,0.55f));
  OUTPUT(smoothstep(scalari,scalari,0.9));
  OUTPUT(smoothstep(scalari,scalari,scalarf));
  OUTPUT(smoothstep(scalari,scalari,scalari));
  OUTPUT(smoothstep(scalari,scalari,scalarh));
  OUTPUT(smoothstep(scalari,scalarh,foo));
  OUTPUT(smoothstep(scalari,scalarh,foo.x));
  OUTPUT(smoothstep(scalari,scalarh,foo.wzxy));
  OUTPUT(smoothstep(scalari,scalarh,0.95));
  OUTPUT(smoothstep(scalari,scalarh,0.55f));
  OUTPUT(smoothstep(scalari,scalarh,0.9));
  OUTPUT(smoothstep(scalari,scalarh,scalarf));
  OUTPUT(smoothstep(scalari,scalarh,scalari));
  OUTPUT(smoothstep(scalari,scalarh,scalarh));
  OUTPUT(smoothstep(scalarh,foo,foo));
  OUTPUT(smoothstep(scalarh,foo,foo.x));
  OUTPUT(smoothstep(scalarh,foo,foo.wzxy));
  OUTPUT(smoothstep(scalarh,foo,0.95));
  OUTPUT(smoothstep(scalarh,foo,0.55f));
  OUTPUT(smoothstep(scalarh,foo,0.9));
  OUTPUT(smoothstep(scalarh,foo,scalarf));
  OUTPUT(smoothstep(scalarh,foo,scalari));
  OUTPUT(smoothstep(scalarh,foo,scalarh));
  OUTPUT(smoothstep(scalarh,foo.x,foo));
  OUTPUT(smoothstep(scalarh,foo.x,foo.x));
  OUTPUT(smoothstep(scalarh,foo.x,foo.wzxy));
  OUTPUT(smoothstep(scalarh,foo.x,0.95));
  OUTPUT(smoothstep(scalarh,foo.x,0.55f));
  OUTPUT(smoothstep(scalarh,foo.x,0.9));
  OUTPUT(smoothstep(scalarh,foo.x,scalarf));
  OUTPUT(smoothstep(scalarh,foo.x,scalari));
  OUTPUT(smoothstep(scalarh,foo.x,scalarh));
  OUTPUT(smoothstep(scalarh,foo.wzxy,foo));
  OUTPUT(smoothstep(scalarh,foo.wzxy,foo.x));
  OUTPUT(smoothstep(scalarh,foo.wzxy,foo.wzxy));
  OUTPUT(smoothstep(scalarh,foo.wzxy,0.95));
  OUTPUT(smoothstep(scalarh,foo.wzxy,0.55f));
  OUTPUT(smoothstep(scalarh,foo.wzxy,0.9));
  OUTPUT(smoothstep(scalarh,foo.wzxy,scalarf));
  OUTPUT(smoothstep(scalarh,foo.wzxy,scalari));
  smoothstep(foo,foo,foo);
  smoothstep(foo,foo.wzxy,foo);
  smoothstep(scalarh,foo.wzxy,foo);
  smoothstep(scalarh,foo.wzxy,scalarh);
  OUTPUT(smoothstep(scalarh,foo.wzxy,scalarh));
  OUTPUT(smoothstep(scalarh,0.95,foo));
  OUTPUT(smoothstep(scalarh,0.95,foo.x));
  OUTPUT(smoothstep(scalarh,0.95,foo.wzxy));
  OUTPUT(smoothstep(scalarh,0.95,0.95));
  OUTPUT(smoothstep(scalarh,0.95,0.55f));
  OUTPUT(smoothstep(scalarh,0.95,0.9));
  OUTPUT(smoothstep(scalarh,0.95,scalarf));
  OUTPUT(smoothstep(scalarh,0.95,scalari));
  OUTPUT(smoothstep(scalarh,0.95,scalarh));
  OUTPUT(smoothstep(scalarh,0.55f,foo));
  OUTPUT(smoothstep(scalarh,0.55f,foo.x));
  OUTPUT(smoothstep(scalarh,0.55f,foo.wzxy));
  OUTPUT(smoothstep(scalarh,0.55f,0.95));
  OUTPUT(smoothstep(scalarh,0.55f,0.55f));
  OUTPUT(smoothstep(scalarh,0.55f,0.9));
  OUTPUT(smoothstep(scalarh,0.55f,scalarf));
  OUTPUT(smoothstep(scalarh,0.55f,scalari));
  OUTPUT(smoothstep(scalarh,0.55f,scalarh));
  OUTPUT(smoothstep(scalarh,0.9,foo));
  OUTPUT(smoothstep(scalarh,0.9,foo.x));
  OUTPUT(smoothstep(scalarh,0.9,foo.wzxy));
  OUTPUT(smoothstep(scalarh,0.9,0.95));
  OUTPUT(smoothstep(scalarh,0.9,0.55f));
  OUTPUT(smoothstep(scalarh,0.9,0.9));
  OUTPUT(smoothstep(scalarh,0.9,scalarf));
  OUTPUT(smoothstep(scalarh,0.9,scalari));
  OUTPUT(smoothstep(scalarh,0.9,scalarh));
  OUTPUT(smoothstep(scalarh,scalarf,foo));
  OUTPUT(smoothstep(scalarh,scalarf,foo.x));
  OUTPUT(smoothstep(scalarh,scalarf,foo.wzxy));
  OUTPUT(smoothstep(scalarh,scalarf,0.95));
  OUTPUT(smoothstep(scalarh,scalarf,0.55f));
  OUTPUT(smoothstep(scalarh,scalarf,0.9));
  OUTPUT(smoothstep(scalarh,scalarf,scalarf));
  OUTPUT(smoothstep(scalarh,scalarf,scalari));
  OUTPUT(smoothstep(scalarh,scalarf,scalarh));
  OUTPUT(smoothstep(scalarh,scalari,foo));
  OUTPUT(smoothstep(scalarh,scalari,foo.x));
  OUTPUT(smoothstep(scalarh,scalari,foo.wzxy));
  OUTPUT(smoothstep(scalarh,scalari,0.95));
  OUTPUT(smoothstep(scalarh,scalari,0.55f));
  OUTPUT(smoothstep(scalarh,scalari,0.9));
  OUTPUT(smoothstep(scalarh,scalari,scalarf));
  OUTPUT(smoothstep(scalarh,scalari,scalari));
  OUTPUT(smoothstep(scalarh,scalari,scalarh));
  OUTPUT(smoothstep(scalarh,scalarh,foo));
  OUTPUT(smoothstep(scalarh,scalarh,foo.x));
  OUTPUT(smoothstep(scalarh,scalarh,foo.wzxy));
  OUTPUT(smoothstep(scalarh,scalarh,0.95));
  OUTPUT(smoothstep(scalarh,scalarh,0.55f));
  OUTPUT(smoothstep(scalarh,scalarh,0.9));
  OUTPUT(smoothstep(scalarh,scalarh,scalarf));
  OUTPUT(smoothstep(scalarh,scalarh,scalari));
  OUTPUT(smoothstep(scalarh,scalarh,scalarh));
  OUTPUT(smoothstep(float4(-1,2,5.4,10),1.1,7));

  OUTPUT(smoothstep(float4(1,2,3,4), float4(2,3,4,0.95f), 0.5));
#endif

  OUTPUT(smoothstep(float4(1,1,1,1),float4(3,3,3,3),float4(0.5f, 1.1f, 2.3f, 3.9f)));
}