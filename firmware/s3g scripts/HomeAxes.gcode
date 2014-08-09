M103
M73 P0
G21 (set units to mm)
G90 (set positioning to absolute)
G162 X F2500 (home X axes maximum)
G161 Y F2500 (home Y axes minimum)
G162 Z F1100 (home Z axis max)
G91  (set positioning to relative)
G1 Z-5 (move Z down 5)
G90 (set positioning to absolute)
G162 Z F100 (slowly home Z axis maximum again)
