
>
Refreshing IP repositories
234*coregenZ19-234h px? 
?
 Loaded user IP repository '%s'.
1135*coregen2=
)/home/augustom/Documents/lab_482/CPRE482X2default:defaultZ19-1700h px? 
?
?If you move the project, the path for repository '%s' may become invalid. A better location for the repostory would be in a path adjacent to the project. (Current project location is '%s'.)1680*coregen2=
)/home/augustom/Documents/lab_482/CPRE482X2default:default2r
^/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/tc_piped_mac/tc_piped_mac.runs/synth_12default:defaultZ19-3656h px? 
?
"Loaded Vivado IP repository '%s'.
1332*coregen2?
+/remote/Xilinx/2020.1/Vivado/2020.1/data/ip2default:defaultZ19-2313h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2'
update_ip_catalog: 2default:default2
00:00:00.692default:default2
00:00:122default:default2
2258.8982default:default2
0.0002default:default2
12532default:default2
155052default:defaultZ17-722h px? 
v
Command: %s
53*	vivadotcl2E
1synth_design -top piped_mac -part xc7z020clg484-12default:defaultZ4-113h px? 
:
Starting synth_design
149*	vivadotclZ4-321h px? 
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2
xc7z0202default:defaultZ17-347h px? 
?
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2
xc7z0202default:defaultZ17-349h px? 
V
Loading part %s157*device2#
xc7z020clg484-12default:defaultZ21-403h px? 
?
HMultithreading enabled for synth_design using a maximum of %s processes.4828*oasys2
42default:defaultZ8-7079h px? 
a
?Launching helper process for spawning children vivado processes4827*oasysZ8-7078h px? 
`
#Helper process launched with PID %s4824*oasys2
163652default:defaultZ8-7075h px? 
?
%s*synth2?
?Starting RTL Elaboration : Time (s): cpu = 00:00:04 ; elapsed = 00:00:09 . Memory (MB): peak = 2283.801 ; gain = 24.762 ; free physical = 752 ; free virtual = 14950
2default:defaulth px? 
?
synthesizing module '%s'638*oasys2
	piped_mac2default:default2s
]/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/hw/MacPipe/hdl/piped_mac_template.vhd2default:default2
532default:default8@Z8-638h px? 
b
%s
*synth2J
6	Parameter C_DATA_WIDTH bound to: 32 - type: integer 
2default:defaulth p
x
? 
?
default block is never used226*oasys2s
]/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/hw/MacPipe/hdl/piped_mac_template.vhd2default:default2
1292default:default8@Z8-226h px? 
?
%done synthesizing module '%s' (%s#%s)256*oasys2
	piped_mac2default:default2
12default:default2
12default:default2s
]/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/hw/MacPipe/hdl/piped_mac_template.vhd2default:default2
532default:default8@Z8-256h px? 
?
%s*synth2?
?Finished RTL Elaboration : Time (s): cpu = 00:00:06 ; elapsed = 00:00:12 . Memory (MB): peak = 2323.750 ; gain = 64.711 ; free physical = 787 ; free virtual = 14985
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
M
%s
*synth25
!Start Handling Custom Attributes
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Handling Custom Attributes : Time (s): cpu = 00:00:06 ; elapsed = 00:00:13 . Memory (MB): peak = 2341.555 ; gain = 82.516 ; free physical = 732 ; free virtual = 14930
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished RTL Optimization Phase 1 : Time (s): cpu = 00:00:06 ; elapsed = 00:00:13 . Memory (MB): peak = 2341.555 ; gain = 82.516 ; free physical = 732 ; free virtual = 14930
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:002default:default2
2341.5552default:default2
0.0002default:default2
7092default:default2
149082default:defaultZ17-722h px? 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px? 
>

Processing XDC Constraints
244*projectZ1-262h px? 
=
Initializing timing engine
348*projectZ1-569h px? 
?
Parsing XDC File [%s]
179*designutils2?
y/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/tc_piped_mac/tc_piped_mac.srcs/constrs_1/new/timing_pipelined.xdc2default:default8Z20-179h px? 
?
Finished Parsing XDC File [%s]
178*designutils2?
y/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/tc_piped_mac/tc_piped_mac.srcs/constrs_1/new/timing_pipelined.xdc2default:default8Z20-178h px? 
H
&Completed Processing XDC Constraints

245*projectZ1-263h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
2461.3482default:default2
0.0002default:default2
4122default:default2
146102default:defaultZ17-722h px? 
~
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common24
 Constraint Validation Runtime : 2default:default2
00:00:00.012default:default2
00:00:00.012default:default2
2461.3482default:default2
0.0002default:default2
4052default:default2
146032default:defaultZ17-722h px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Constraint Validation : Time (s): cpu = 00:00:13 ; elapsed = 00:00:25 . Memory (MB): peak = 2461.352 ; gain = 202.312 ; free physical = 789 ; free virtual = 14987
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
V
%s
*synth2>
*Start Loading Part and Timing Information
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
J
%s
*synth22
Loading part: xc7z020clg484-1
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Loading Part and Timing Information : Time (s): cpu = 00:00:13 ; elapsed = 00:00:25 . Memory (MB): peak = 2461.352 ; gain = 202.312 ; free physical = 789 ; free virtual = 14987
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
Z
%s
*synth2B
.Start Applying 'set_property' XDC Constraints
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished applying 'set_property' XDC Constraints : Time (s): cpu = 00:00:13 ; elapsed = 00:00:25 . Memory (MB): peak = 2461.352 ; gain = 202.312 ; free physical = 790 ; free virtual = 14988
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished RTL Optimization Phase 2 : Time (s): cpu = 00:00:13 ; elapsed = 00:00:25 . Memory (MB): peak = 2461.359 ; gain = 202.320 ; free physical = 781 ; free virtual = 14980
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
L
%s
*synth24
 Start RTL Component Statistics 
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
X
%s
*synth2@
,	   2 Input   64 Bit       Adders := 1     
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               64 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               48 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 2     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                2 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 4     
2default:defaulth p
x
? 
?
%s
*synth2'
+---Multipliers : 
2default:defaulth p
x
? 
X
%s
*synth2@
,	              32x32  Multipliers := 1     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
X
%s
*synth2@
,	   4 Input   64 Bit        Muxes := 1     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   2 Input   64 Bit        Muxes := 1     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   4 Input   48 Bit        Muxes := 1     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   2 Input   32 Bit        Muxes := 2     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   6 Input    2 Bit        Muxes := 1     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   2 Input    2 Bit        Muxes := 1     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   4 Input    1 Bit        Muxes := 7     
2default:defaulth p
x
? 
X
%s
*synth2@
,	   2 Input    1 Bit        Muxes := 1     
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
O
%s
*synth27
#Finished RTL Component Statistics 
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
H
%s
*synth20
Start Part Resource Summary
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s
*synth2k
WPart Resources:
DSPs: 220 (col length:60)
BRAMs: 280 (col length: RAMB18 60 RAMB36 30)
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Finished Part Resource Summary
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
W
%s
*synth2?
+Start Cross Boundary and Area Optimization
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
e
%s
*synth2M
9DSP Report: Generating DSP ARG, operation Mode is: A2*B.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: register ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
o
%s
*synth2W
CDSP Report: Generating DSP ARG, operation Mode is: (PCIN>>17)+A*B.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
f
%s
*synth2N
:DSP Report: Generating DSP ARG, operation Mode is: A2*B2.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: register ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: register ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
p
%s
*synth2X
DDSP Report: Generating DSP ARG, operation Mode is: (PCIN>>17)+A2*B.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: register ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
_
%s
*synth2G
3DSP Report: operator ARG is absorbed into DSP ARG.
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Cross Boundary and Area Optimization : Time (s): cpu = 00:00:15 ; elapsed = 00:00:28 . Memory (MB): peak = 2461.359 ; gain = 202.320 ; free physical = 767 ; free virtual = 14969
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?---------------------------------------------------------------------------------
Start ROM, RAM, DSP and Shift Register Reporting
2default:defaulth px? 
~
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px? 
^
%s*synth2F
2
DSP: Preliminary Mapping	Report (see note below)
2default:defaulth px? 
?
%s*synth2?
?+------------+-----------------+--------+--------+--------+--------+--------+------+------+------+------+-------+------+------+
2default:defaulth px? 
?
%s*synth2?
?|Module Name | DSP Mapping     | A Size | B Size | C Size | D Size | P Size | AREG | BREG | CREG | DREG | ADREG | MREG | PREG | 
2default:defaulth px? 
?
%s*synth2?
?+------------+-----------------+--------+--------+--------+--------+--------+------+------+------+------+-------+------+------+
2default:defaulth px? 
?
%s*synth2?
?|piped_mac   | A2*B            | 18     | 15     | -      | -      | 48     | 1    | 0    | -    | -    | -     | 0    | 0    | 
2default:defaulth px? 
?
%s*synth2?
?|piped_mac   | (PCIN>>17)+A*B  | 15     | 15     | -      | -      | 48     | 0    | 0    | -    | -    | -     | 0    | 0    | 
2default:defaulth px? 
?
%s*synth2?
?|piped_mac   | A2*B2           | 18     | 18     | -      | -      | 48     | 1    | 1    | -    | -    | -     | 0    | 0    | 
2default:defaulth px? 
?
%s*synth2?
?|piped_mac   | (PCIN>>17)+A2*B | 18     | 15     | -      | -      | 48     | 1    | 0    | -    | -    | -     | 0    | 0    | 
2default:defaulth px? 
?
%s*synth2?
?+------------+-----------------+--------+--------+--------+--------+--------+------+------+------+------+-------+------+------+

2default:defaulth px? 
?
%s*synth2?
?Note: The table above is a preliminary report that shows the DSPs inferred at the current stage of the synthesis flow. Some DSP may be reimplemented as non DSP primitives later in the synthesis flow. Multiple instantiated DSPs are reported only once.
2default:defaulth px? 
?
%s*synth2?
?---------------------------------------------------------------------------------
Finished ROM, RAM, DSP and Shift Register Reporting
2default:defaulth px? 
~
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
R
%s
*synth2:
&Start Applying XDC Timing Constraints
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Applying XDC Timing Constraints : Time (s): cpu = 00:00:23 ; elapsed = 00:00:40 . Memory (MB): peak = 2461.359 ; gain = 202.320 ; free physical = 615 ; free virtual = 14817
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
F
%s
*synth2.
Start Timing Optimization
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Timing Optimization : Time (s): cpu = 00:00:24 ; elapsed = 00:00:40 . Memory (MB): peak = 2481.367 ; gain = 222.328 ; free physical = 609 ; free virtual = 14811
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-
Start Technology Mapping
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Technology Mapping : Time (s): cpu = 00:00:24 ; elapsed = 00:00:41 . Memory (MB): peak = 2489.375 ; gain = 230.336 ; free physical = 600 ; free virtual = 14802
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s
*synth2'
Start IO Insertion
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
Q
%s
*synth29
%Start Flattening Before IO Insertion
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
T
%s
*synth2<
(Finished Flattening Before IO Insertion
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
H
%s
*synth20
Start Final Netlist Cleanup
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Finished Final Netlist Cleanup
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished IO Insertion : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 600 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
O
%s
*synth27
#Start Renaming Generated Instances
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Renaming Generated Instances : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 600 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
L
%s
*synth24
 Start Rebuilding User Hierarchy
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Rebuilding User Hierarchy : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 599 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Start Renaming Generated Ports
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Renaming Generated Ports : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 599 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
M
%s
*synth25
!Start Handling Custom Attributes
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Handling Custom Attributes : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 599 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
J
%s
*synth22
Start Renaming Generated Nets
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Renaming Generated Nets : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 599 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Start Writing Synthesis Report
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
A
%s
*synth2)

Report BlackBoxes: 
2default:defaulth p
x
? 
J
%s
*synth22
+-+--------------+----------+
2default:defaulth p
x
? 
J
%s
*synth22
| |BlackBox name |Instances |
2default:defaulth p
x
? 
J
%s
*synth22
+-+--------------+----------+
2default:defaulth p
x
? 
J
%s
*synth22
+-+--------------+----------+
2default:defaulth p
x
? 
A
%s*synth2)

Report Cell Usage: 
2default:defaulth px? 
E
%s*synth2-
+------+--------+------+
2default:defaulth px? 
E
%s*synth2-
|      |Cell    |Count |
2default:defaulth px? 
E
%s*synth2-
+------+--------+------+
2default:defaulth px? 
E
%s*synth2-
|1     |BUFG    |     1|
2default:defaulth px? 
E
%s*synth2-
|2     |CARRY4  |    28|
2default:defaulth px? 
E
%s*synth2-
|3     |DSP48E1 |     4|
2default:defaulth px? 
E
%s*synth2-
|5     |LUT1    |     2|
2default:defaulth px? 
E
%s*synth2-
|6     |LUT2    |   112|
2default:defaulth px? 
E
%s*synth2-
|7     |LUT3    |     4|
2default:defaulth px? 
E
%s*synth2-
|8     |LUT4    |   129|
2default:defaulth px? 
E
%s*synth2-
|9     |LUT5    |     1|
2default:defaulth px? 
E
%s*synth2-
|10    |LUT6    |    34|
2default:defaulth px? 
E
%s*synth2-
|11    |FDRE    |   149|
2default:defaulth px? 
E
%s*synth2-
|12    |IBUF    |    70|
2default:defaulth px? 
E
%s*synth2-
|13    |OBUF    |    35|
2default:defaulth px? 
E
%s*synth2-
|14    |OBUFT   |     8|
2default:defaulth px? 
E
%s*synth2-
+------+--------+------+
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Writing Synthesis Report : Time (s): cpu = 00:00:28 ; elapsed = 00:00:44 . Memory (MB): peak = 2496.316 ; gain = 237.277 ; free physical = 599 ; free virtual = 14801
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
r
%s
*synth2Z
FSynthesis finished with 0 errors, 0 critical warnings and 0 warnings.
2default:defaulth p
x
? 
?
%s
*synth2?
?Synthesis Optimization Runtime : Time (s): cpu = 00:00:26 ; elapsed = 00:00:42 . Memory (MB): peak = 2496.316 ; gain = 117.484 ; free physical = 663 ; free virtual = 14865
2default:defaulth p
x
? 
?
%s
*synth2?
?Synthesis Optimization Complete : Time (s): cpu = 00:00:28 ; elapsed = 00:00:45 . Memory (MB): peak = 2496.320 ; gain = 237.277 ; free physical = 665 ; free virtual = 14867
2default:defaulth p
x
? 
B
 Translating synthesized netlist
350*projectZ1-571h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:00.012default:default2
2496.3202default:default2
0.0002default:default2
7362default:default2
149382default:defaultZ17-722h px? 
f
-Analyzing %s Unisim elements for replacement
17*netlist2
322default:defaultZ29-17h px? 
j
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px? 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px? 
u
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
2499.2852default:default2
0.0002default:default2
6792default:default2
148802default:defaultZ17-722h px? 
~
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px? 
U
Releasing license: %s
83*common2
	Synthesis2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
202default:default2
12default:default2
02default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
synth_design2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2"
synth_design: 2default:default2
00:00:402default:default2
00:01:032default:default2
2499.2852default:default2
240.3872default:default2
8262default:default2
150282default:defaultZ17-722h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2?
l/home/augustom/Documents/lab_482/CPRE482X/cpre482x-lab3/tc_piped_mac/tc_piped_mac.runs/synth_1/piped_mac.dcp2default:defaultZ17-1381h px? 
?
%s4*runtcl2|
hExecuting : report_utilization -file piped_mac_utilization_synth.rpt -pb piped_mac_utilization_synth.pb
2default:defaulth px? 
?
Exiting %s at %s...
206*common2
Vivado2default:default2,
Mon Nov 15 14:06:04 20212default:defaultZ17-206h px? 


End Record