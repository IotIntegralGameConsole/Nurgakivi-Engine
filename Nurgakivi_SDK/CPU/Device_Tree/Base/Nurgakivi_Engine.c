//Nurgakivi Engine SoC Device Tree
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
      };
  };

    cpu1:cpu@1 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
       };
    };

    cpu2:cpu@2 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        };
    };

    cpu3:cpu@3 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        };
    };

    cpu4:cpu@4 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        };
    };

    cpu5:cpu@5 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        };
    };

    cpu6:cpu@6 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        };
    };

    cpu7:cpu@7 {
            compatible = "Nurgakivi_lab, Nurgakivi_Engine", "riscv";
        };
    };

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


    // Serial
    serial@101f0000 {
        compatible =" , ";
         };
    };
}