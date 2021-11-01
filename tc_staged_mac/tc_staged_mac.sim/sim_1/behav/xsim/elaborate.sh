#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2020.1 (64-bit)
#
# Filename    : elaborate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for elaborating the compiled design
#
# Generated by Vivado on Mon Nov 01 13:28:59 CDT 2021
# SW Build 2902540 on Wed May 27 19:54:35 MDT 2020
#
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
#
# usage: elaborate.sh
#
# ****************************************************************************
set -Eeuo pipefail
echo "xelab -wto cffdb5cc151a47b4a98ad6f45909676a --incr --debug typical --relax --mt 8 -L xil_defaultlib -L secureip --snapshot staged_mac_behav xil_defaultlib.staged_mac -log elaborate.log"
xelab -wto cffdb5cc151a47b4a98ad6f45909676a --incr --debug typical --relax --mt 8 -L xil_defaultlib -L secureip --snapshot staged_mac_behav xil_defaultlib.staged_mac -log elaborate.log

