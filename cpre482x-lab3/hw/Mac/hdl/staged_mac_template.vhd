-------------------------------------------------------------------------
-- Matthew Dwyer
-- Department of Electrical and Computer Engineering
-- Iowa State University
-------------------------------------------------------------------------


-- staged_mac.vhd
-------------------------------------------------------------------------
-- DESCRIPTION: This file contains a basic staged axi-stream mac unit. It
-- multiplies two integer/Q values togeather and accumulates them.
--
-- NOTES:
-- 10/25/21 by MPD::Inital template creation
-------------------------------------------------------------------------

library work;
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity staged_mac is
  generic(
      -- Parameters of mac
      C_DATA_WIDTH : integer := 32
    );
	port (
        ACLK	: in	std_logic;
		ARESETN	: in	std_logic;       

        -- AXIS slave data interface
		SD_AXIS_TREADY	: out	std_logic;
		SD_AXIS_TDATA	: in	std_logic_vector(C_DATA_WIDTH*2-1 downto 0);  -- Packed data input
		SD_AXIS_TLAST	: in	std_logic;
        SD_AXIS_TUSER   : in    std_logic;  -- Should we treat this first value in the stream as an inital accumulate value?
		SD_AXIS_TVALID	: in	std_logic;
        SD_AXIS_TID     : in    std_logic_vector(7 downto 0);

        -- AXIS master accumulate result out interface
		MO_AXIS_TVALID	: out	std_logic;
		MO_AXIS_TDATA	: out	std_logic_vector(C_DATA_WIDTH-1 downto 0);
		MO_AXIS_TLAST	: out	std_logic;
		MO_AXIS_TREADY	: in	std_logic;
		MO_AXIS_TID     : out   std_logic_vector(7 downto 0)
    );

attribute SIGIS : string; 
attribute SIGIS of ACLK : signal is "Clk"; 

end staged_mac;


architecture behavioral of staged_mac is
    -- Internal Signals
    --accumulator 2x input size (can make bigger)
	signal accum_reg : std_logic_vector(C_DATA_WIDTH*2-1 downto 0);
    --Register inputs to save first value when TVALID goes high
    signal a_reg : std_logic_vector(C_DATA_WIDTH-1 downto 0);
    signal b_reg : std_logic_vector(C_DATA_WIDTH-1 downto 0);
	
	-- Mac state
    type STATE_TYPE is (WAIT_FOR_VALUES, PROCESS_VALUES);
    signal state : STATE_TYPE;
	
	-- Debug signals, make sure we aren't going crazy
    signal mac_debug : std_logic_vector(31 downto 0);

begin

    -- Interface signals
    --TODO CLAMPING
    MO_AXIS_TDATA <= accum_reg(C_DATA_WIDTH -1 downto 0);
    -- Internal signals
	
	
	-- Debug Signals
    mac_debug <= x"00000000";  -- Double checking sanity
   
   process (ACLK) is
   begin 
    if rising_edge(ACLK) then  -- Rising Edge

      -- Reset values if reset is low
      if ARESETN = '0' then  -- Reset
        state       <= WAIT_FOR_VALUES;
        accum_reg <= (others => '0');
        a_reg <= (others => '0');
        b_reg <= (others => '0');

        SD_AXIS_TREADY <= '0';
        MO_AXIS_TVALID <= '0';
        MO_AXIS_TLAST <= '0';
      else
      
       a_reg <= SD_AXIS_TDATA(C_DATA_WIDTH*2-1 downto C_DATA_WIDTH);
       b_reg <= SD_AXIS_TDATA(C_DATA_WIDTH-1 downto 0);
        case state is  -- State
           
            -- Wait here until we receive values
            when WAIT_FOR_VALUES =>
                -- Wait here until we recieve valid values
                -- The TREADY signals to the Master that the Slave is ready to accept new data when high. 
			    SD_AXIS_TREADY <= '1';
                -- The TVALID signal signifies that the data on the TDATA bus is valid
			    if SD_AXIS_TVALID = '1' then
                    state <= PROCESS_VALUES;
			    end if;
                --Output nothing, accum has not changed
                MO_AXIS_TVALID <= '0';

			-- Other stages go here	
			
            when PROCESS_VALUES =>
            -- Right shift multiplication result by x
                accum_reg <= std_logic_vector(unsigned(accum_reg) + shift_right(unsigned(a_reg) * unsigned(b_reg),C_DATA_WIDTH/2)); --
                if SD_AXIS_TLAST = '1' or SD_AXIS_TVALID = '0' then
                    state <= WAIT_FOR_VALUES;
                end if;
                --Output
                if MO_AXIS_TREADY = '1' then
                    MO_AXIS_TVALID <= '1';
                end if;

            when others =>
                state <= WAIT_FOR_VALUES;
                -- Not really important, this case should never happen
                -- Needed for proper synthisis         
        end case;  -- State
      end if;  -- Reset

    end if;  -- Rising Edge
   end process;
end architecture behavioral;
