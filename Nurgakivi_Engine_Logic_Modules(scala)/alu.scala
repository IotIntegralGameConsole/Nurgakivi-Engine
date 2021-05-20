//////////////////////////////////////////////////////////////////
// _____   __                            ______ _____       _____
// ___  | / /___  _______________ ______ ___  /____(_)__   ____(_)
// __   |/ /_  / / /_  ___/_  __ `/  __ `/_  //_/_  /__ | / /_  /
// _  /|  / / /_/ /_  /   _  /_/ // /_/ /_  ,<  _  / __ |/ /_  /
// /_/ |_/  \__,_/ /_/    _\__, / \__,_/ /_/|_| /_/  _____/ /_/
//                        /____/
// __________              _____
// ___  ____/_____________ ___(_)___________
// __  __/  __  __ \_  __ `/_  /__  __ \  _ \
// _  /___  _  / / /  /_/ /_  / _  / / /  __/
// /_____/  /_/ /_/_\__, / /_/  /_/ /_/\___/
//                 /____/
///////////////////////////////////////////////////////////////
package chisel3

import chisel3._
import chisel3.util._

class Alu(size: Int) extends Module {
val io = IO(new Bundle {
val op = Input(UInt (3.W))
val a = Input(SInt(size.W))
val b = Input(SInt(size.W))
val y = Output(SInt(size.W))
})
val op = io.op
val a = io.a
val b = io.b
val res = WireDefault (0.S(size.W))
switch(op) {
is(add) {
res := a + b
}
is(sub) {
res := a - b
}
is(and) {
res := a & b
}
is(or) {
res := a | b
}
is(xor) {
res := a ˆ b
}
is (shr) {
// the following does NOT result in an unsigned shift
// res := (a.asUInt >> 1).asSInt
// work around
res := (a >> 1) & 0 x7fffffff .S
}
is(ld) {
res := b
}
}
io.y := res
}