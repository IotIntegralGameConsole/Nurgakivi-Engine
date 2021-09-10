// See LICENSE.SiFive for license details.

package freechips.rocketchip.tile

import Chisel._

trait TileParams {
  val core: CoreParams                  // Core parameters (see below)
  val icache: Option[ICacheParams]      // Rocket specific: I1 cache option
  val dcache: Option[DCacheParams]      // Rocket specific: D1 cache option
  val btb: Option[BTBParams]            // Rocket specific: BTB / branch predictor option
  val hartId: Int                       // Hart ID: Must be unique within a design config (This MUST be a case class parameter)
  val beuAddr: Option[BigInt]           // Rocket specific: Bus Error Unit for Rocket Core
  val blockerCtrlAddr: Option[BigInt]   // Rocket specific: Bus Blocker for Rocket Core
  val name: Option[String]              // Name of the core
}

abstract class InstantiableTileParams[TileType <: BaseTile] extends TileParams {
  def instantiate(crossing: TileCrossingParamsLike, lookup: LookupByHartIdImpl)
                (implicit p: Parameters): TileType
}

trait CoreParams {
  val bootFreqHz: BigInt              // Frequency
  val useVM: Boolean                  // Support virtual memory
  val useUser: Boolean                // Support user mode
  val useSupervisor: Boolean          // Support supervisor mode
  val useDebug: Boolean               // Support RISC-V debug specs
  val useAtomics: Boolean             // Support A extension
  val useAtomicsOnlyForIO: Boolean    // Support A extension for memory-mapped IO (may be true even if useAtomics is false)
  val useCompressed: Boolean          // Support C extension
  val useVector: Boolean = false      // Support V extension
  val useSCIE: Boolean                // Support custom instructions (in custom-0 and custom-1)
  val useRVE: Boolean                 // Use E base ISA
  val mulDiv: Option[MulDivParams]    // *Rocket specific: M extension related setting (Use Some(MulDivParams()) to indicate M extension supported)
  val fpu: Option[FPUParams]          // F and D extensions and related setting (see below)
  val fetchWidth: Int                 // Max # of insts fetched every cycle
  val decodeWidth: Int                // Max # of insts decoded every cycle
  val retireWidth: Int                // Max # of insts retired every cycle
  val instBits: Int                   // Instruction bits (if 32 bit and 64 bit are both supported, use 64)
  val nLocalInterrupts: Int           // # of local interrupts (see SiFive interrupt cookbook)
  val nPMPs: Int                      // # of Physical Memory Protection units
  val pmpGranularity: Int             // Size of the smallest unit of region for PMP unit (must be power of 2)
  val nBreakpoints: Int               // # of hardware breakpoints supported (in RISC-V debug specs)
  val useBPWatch: Boolean             // Support hardware breakpoints
  val nPerfCounters: Int              // # of supported performance counters
  val haveBasicCounters: Boolean      // Support basic counters defined in the RISC-V counter extension
  val haveFSDirty: Boolean            // If true, the core will set FS field in mstatus CSR to dirty when appropriate
  val misaWritable: Boolean           // Support writable misa CSR (like variable instruction bits)
  val haveCFlush: Boolean             // Rocket specific: enables Rocket's custom instruction extension to flush the cache
  val nL2TLBEntries: Int              // # of L2 TLB entries
  val mtvecInit: Option[BigInt]       // mtvec CSR (of V extension) initial value
  val mtvecWritable: Boolean          // If mtvec CSR is writable

  // Normally, you don't need to change these values (except lrscCycles)
  def customCSRs(implicit p: Parameters): CustomCSRs = new CustomCSRs

  def hasSupervisorMode: Boolean = useSupervisor || useVM
  def instBytes: Int = instBits / 8
  def fetchBytes: Int = fetchWidth * instBytes
  // Rocket specific: Longest possible latency of Rocket core D1 cache. Simply set it to the default value 80 if you don't use it.
  def lrscCycles: Int

  def dcacheReqTagBits: Int = 6

  def minFLen: Int = 32
  def vLen: Int = 0
  def sLen: Int = 0
  def eLen(xLen: Int, fLen: Int): Int = xLen max fLen
  def vMemDataBits: Int = 0
}

case class FPUParams(
  minFLen: Int = 32,          // Minimum floating point length (no need to change)
  fLen: Int = 64,             // Maximum floating point length, use 32 if only single precision is supported
  divSqrt: Boolean = true,    // Div/Sqrt operation supported
  sfmaLatency: Int = 3,       // Rocket specific: Fused multiply-add pipeline latency (single precision)
  dfmaLatency: Int = 4        // Rocket specific: Fused multiply-add pipeline latency (double precision)
)
Most of the fields here (marked “Rocket spcific”) are originally designed for the Rocket core and thus contain some implementation-specific details, but many of them are general enough to be useful for other cores. You may ignore any fields marked “Rocket specific” and use their default values; however, if you need to store additional information with meaning or usage similar to these “Rocket specific” fields, it is recommended to use these fields instead of creating your own custom fields.

You will also need a CanAttachTile class to add the tile config into the config system, with the following format:

case class MyTileAttachParams(
  tileParams: MyTileParams,
  crossingParams: RocketCrossingParams
) extends CanAttachTile {
  type TileType = MyTile
  val lookup = PriorityMuxHartIdFromSeq(Seq(tileParams))
}



/*
// Heterogeneous SoCs / Creating a Rocket and BOOM System / Adding Hwachas
class BoomThenRocketHartIdTestConfig extends Config(   
new freechips.rocketchip.subsystem.WithNBigCores(4) ++   

new boom.common.WithNLargeBooms(4) ++   

new chipyard.config.AbstractConfig)
// =======================
class DualLargeBoomAndHwachaRocketConfig extends Config(   
new chipyard.config.WithMultiRoCC ++   // support heterogeneous rocc   


new chipyard.config.WithMultiRoCCHwacha(0) ++  // put hwacha on hart-0 (rocket)   new hwacha.DefaultHwachaConfig ++ 
*/