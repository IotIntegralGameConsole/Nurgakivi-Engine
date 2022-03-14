// [Codename Nurgakivi] Nurgakivi Engine SoC Device Tree
/* Nurgakivi Lab. Nurgakivi Entertainment (Estonia)
Independence Video Game Console "integral" / Video Game Arcade "Iinnexxyy" */

#include "Nurgakivi_Engine.h"

// CPU Cores
/ {

  cpus {
      #address-cells = <2>;
		#size-cells = <2>;

        chosen { };
        aliases { };
 
      cpu0:cpu@0 {
          compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
          device_type = "cpu";
          // i-Cache
          i-cache-block-size = <64>;
          i-cache-sets = <128>;
          i-cache-size = <32768>;
          i-tlb-sets = <2>;
          i-tlb-size = <40>;
          // mmu type
          mmu-type = "riscv, rv64";
          next-level-cache = <&ccache>;
          reg = <0x0>;
          // 64-bit risc isa
          riscv,isa = "rv64imafdc";
          status = "disabled";
          tlb-split;
          cpu0_intc: interrupt-controller {
              #interrupt-cells = <2>;
              compatible = "riscv, cpu-intc";
              interrupt-controller;
      };
  };

    cpu1:cpu@1 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
            device_type = "cpu";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size =  <64>;
        d-cache-sets = <128>;
        d-cache-size = <32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        mmu-type = "riscv, rv64";
        next-level-cache = <&ccache>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu1_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
       };
    };

    cpu2:cpu@2 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size = <64>;
        d-cache-sets = <128>;
        d-cache-size = <32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        mmu-type = "riscv, rv64";
        next-level-cache = <&ccache>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu2_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
        };
    };

    cpu3:cpu@3 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size = <64>;
        d-cache-sets = <128>;
        d-cache-size = <32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        mmu-type = "riscv, rv64";
        next-level-cache = <&ccache>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu3_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
        };
    };

    cpu4:cpu@4 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size = <64>;
        d-cache-sets = <128>;
        d-cache-size =<32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        mmu-type = "riscv, rv64";
        next-level-cache = <&ccache>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu4_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
        };
    };

    cpu5:cpu@5 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size = <64>;
        d-cache-sets = <128>;
        d-cache-size = <32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        mmu-type = "riscv, rv64";
        next-level-cache = <&ccache>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu5_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
        };
    };

    cpu6:cpu@6 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size = <64>;
        d-cache-sets = <128>;
        d-cache-size = <32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu6_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
        };
    };

    cpu7:cpu@7 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        // i-cache, d-cache
        i-cache-block-size = <64>;
        i-cache-sets = <128>;
        i-cache-size = <32768>;
        i-tlb-sets = <2>;
        i-tlb-size = <40>;
        d-cache-block-size = <64>;
        d-cache-sets = <128>;
        d-cache-size = <32768>;
        d-tlb-sets = <2>;
        d-tlb-size = <40>;
        // 64-bit riscv isa
        riscv isa = "rv64imafdc";
        tlb-split;
        cpu7_intc: interrupt-controller {
            #interrupt-cells = <2>;
            compatible = "riscv, cpu-intc";
        };
    };
  };
    // AMD GCN GPU (Southern islands ISA & Volcanic isalnds ISA)

    
    // SoC
    /*
    soc {
    #address-cells = <2>;
    #size-cells = <2>;
    compatible = "simple-bus";
    ranges;
    plic0: interrupt-controller@c000000 {
        #interrupt-cells = <2>;
        #address-cells = <2>;
        compatible = "Nurgakivi_lab,Nurgakivi_Engine-plic, "Nurgakivi_lab,plic-1.0.0";
        reg = <0x0 0xc000000 0x0 0x4000000>;
        riscv, ndev =<69>;
        interrupt-controller;
        interrupts-extended = <
            &cpu0_intc 0xffffffff
            &cpu1_intc 0xffffffff &cpu1_intc 9
            &cpu2_intc 0xffffffff &cpu2_intc 9 
            &cpu3_intc 0xffffffff &cpu3_intc 9
            &cpu4_intc 0xffffffff &cpu4_intc 9
            &cpu5_intc 0xffffffff &cpu5_intc 9
            &cpu6_intc 0xffffffff &cpu6_intc 9
            &cpu7_intc 0xffffffff &cpu7_intc 9>;
    };
    */

    // System Processor

    // Flash Memory

    // Memory
    memory {
                device_type = "memory";
                reg = <0x00000000 0x40000000>;
        };

    soc {

    interrupt-controller@10140000 {
            compatible =" , ";
    };

    // Spi
    spi@10110000 {
        compatible =" , ";
    };

    // System Bus
    Systme-bus {
        compatible =" , ";
    };


    // External Bus

    
    // Giga-Ethernet

    // HDMI

    // pci express

    // Serial
    uart0: serial@101f0000 {
        compatible ="Nurgakivi_lab, Nurgakivi_Engine", "riscv, uart0";
        
         };
    uart1: serial@101f100 {
    };
};