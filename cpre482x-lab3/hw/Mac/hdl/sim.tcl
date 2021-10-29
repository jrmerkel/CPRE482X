launch_simulation
add_force {/staged_mac/ACLK} -radix bin {0 0ns} {1 50000ps} -repeat_every 100000ps
add_force {/staged_mac/SD_AXIS_TVALID} -radix hex {0 0ns}
add_force {/staged_mac/ARESETN} -radix hex {0 0ns}
run 100ns
add_force {/staged_mac/ARESETN} -radix hex {1 0ns}


for {set i 0} {$i < 10} {incr i} {

    add_force {/staged_mac/SD_AXIS_TDATA} -radix hex {0001FFFF0000FF00 0ns} 

    add_force {/staged_mac/SD_AXIS_TVALID} -radix hex {1 0ns}   
    run 100ns 

}

add_force {/staged_mac/SD_AXIS_TVALID} -radix hex {0 0ns}