launch_simulation
add_force {/piped_mac/ACLK} -radix bin {0 0ns} {1 50000ps} -repeat_every 100000ps
add_force {/piped_mac/SD_AXIS_TVALID} -radix hex {0 0ns}
add_force {/piped_mac/ARESETN} -radix hex {0 0ns}

add_force {/piped_mac/SD_AXIS_TUSER} -radix hex {0 0ns}
add_force {/piped_mac/SD_AXIS_TLAST} -radix hex {0 0ns}

run 100ns
add_force {/piped_mac/ARESETN} -radix hex {1 0ns}


for {set i 0} {$i < 10} {incr i} {

    add_force {/piped_mac/SD_AXIS_TDATA} -radix hex {0001FFFF0000FF00 0ns} 

    add_force {/piped_mac/SD_AXIS_TVALID} -radix hex {1 0ns}   
    run 100ns 

}

add_force {/piped_mac/SD_AXIS_TLAST} -radix hex {1 0ns}

run 100ns

add_force {/piped_mac/SD_AXIS_TLAST} -radix hex {0 0ns}

# set accum to a constant
add_force {/piped_mac/SD_AXIS_TUSER} -radix hex {1 0ns}
add_force {/piped_mac/SD_AXIS_TDATA} -radix hex {00000000000000F0 0ns} 
run 300ns

add_force {/staged_mac/SD_AXIS_TVALID} -radix hex {0 0ns}
add_force {/staged_mac/SD_AXIS_TDATA} -radix hex {0001FFFF0000FF00 0ns} 
run 1000ns