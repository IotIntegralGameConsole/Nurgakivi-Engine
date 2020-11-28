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
// 
// Chipset Code Name "Nurgakivi" & Chipset Name "Nurgakivi Engine"
// Nurgakivi Engine ™ ® by Nurgakivi Lab., Estonia
// This powered by BSD-3 Clause / MIT License Version Licensed 2018
// Semi-Custom SoC Chipset Code Name "Nurgakivi" 
// That will develop Main Custom SoC(System on Chip) of Integral Game Console based RISC-V and AMD GCN(Under BSD / MIT license)
///////////////////////////////////////////////////////////////
package chisel3

import chisel3._
import chisel3.util._
import chisel3.experimental._ // To enable experimental features
import chisel3.core.Input
import freechips.rocketchip.config
import freechips.rocketchip.tilelink
import chisel3.util.HasBlackBoxInline

/* 2-64bit_ALU uses like 128bit
class 64bit_1 ALU extend Module {
  val io = IO(new Bundle() {
    val in1 = Input(UInt(64.W))
    val in2 = Input(UInt(64.W))
    val alu_opcode = Input(UInt(AluOpCode.64.W))
    val out = Output(UInt(128.W))
    }) 
class 64bit_2 ALU extend Module {
  val io = IO(new Bundle() {
    val in1 = Input(UInt(64.W))
    val in2 = Input(UInt(64.W))
    val alu_opcode = Input(UInt(AluOpCode.64.W))
    val out = Output(UInt(64.W))
    val out = Output(SInt(128.W))
    }) 
*/

class BlackBoxRealAdd extends BlackBox {
  val io = IO(new Bundle() {
    val in1 = Input(UInt(64.W))
    val in2 = Input(UInt(64.W))
    val out = Output(UInt(64.W))
   //val out = Output(SInt(128.W)) 
  })
  setInline("64bit_alu.v",
  /* 64Bit ALU (1)*/
"""module alu(input [63:0] A,B,
           input [63:0] ALU_Sel,
           output [63:0] ALU_Out,
           output CarryOut
          );
 reg [63:0] ALU_Result;
 wire [63:0] tmp;
 assign ALU_Out = ALU_Result;
 assign tmp = {1'b0, A} + {1'b0,B};
 assign CarryOut = tmp[8];
 always @(*) begin
    case(ALU_Sel)
     4'b0000;
        ALU_Result = A + B;
     4'b0001;
        ALU_Result = A - B;
     4'b0010;
        ALU_Result = A & B;
     4'b0011;
        ALU_Result = A ^ B;
    default: ALU_Result = A - b;
   endcase
  endcase
 endmodule   
""".stripMargin)
}

/*
- Chisel Book
https://github.com/schoeberl/chisel-book

- Instruction Documents 
http://www.five-embeddev.com/ 
*/