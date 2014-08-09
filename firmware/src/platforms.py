# platforms.py -- build settings for each "standard" firmware build.
#
#   Individuals can extend the list of known platforms by supplying
#   the file ~/.sailfish_platforms.py containing additional entries
#   for the platforms{} dictionary.  In the following example, an
#   entry is defined for a platform named "franken-board"
#
#     % cat ~/.sailfish_platforms.py
#     platforms['franken-board'] = {
#         'mcu' : 'atmega2560',
#         'programmer' : 'stk500v2',
#         'board_directory' : 'mighty_one',
#         'defines' : [ 'CORE_XY', 'BUILD_STATS', 'ALTERNATE_UART',
#                       'HEATERS_ON_STEROIDS', 'MAX31855' ]
#     }
#
#  It can then be built with the simple command
#
#     % scons platform=franken-board
#
#  which would be largely equivalent to
#
#     % scons platform=mighty_one-2560 core_xy=1 heaters_on_steroids=1 \
#          alt_uart=1 max31855=1
#
#  It misses setting -DBUILD_STATS since there is no command line option
#  to select that.

from os.path import expanduser, isfile

platforms = {

# This is a dictionary of platform names to build.
# Each platform to build is itself a dictionary containing build settings.
# The settings are
#
#   mcu        -- Processor name (e.g., atmega1280)
#   programmer -- avrdude programmer type (e.g., stk500v1)
#   board_directory -- Name of the motherboard specific board directory to
#                      use under firmware/src/MightyBoard/Motherboard/boards/
#                      (e.g., mighty_one)
#   defines    -- List of #defines to establish.  Any string prefixed with '-'
#                 will be removed from the list of #defines to establish.
#   squeeze    -- Source files to compile --mcall-prologues so as to save
#                 code space.

    'ramps13-2560' :
        { 'mcu' : 'atmega2560',
          'programmer' : 'stk500v2',
          'board_directory' : 'ramps13',
          'defines' : [ 'BUILD_STATS', 'ALTERNATE_UART', 'AUTO_LEVEL' ]
        }

}

# Load data from ~/.sailfish_platforms.py

tmp_dict = { 'platforms' : {} }
home = expanduser('~')
if home[-1] != '/':
    home += '/'
site_file = home + '.sailfish_platforms.py'

if isfile(site_file):
    with open(site_file) as f:
        exec(f.read(), tmp_dict)

    if 'platforms' in tmp_dict:
        tmp_platforms = tmp_dict['platforms']
        for key in tmp_platforms:
            platforms[key] = tmp_platforms[key]

if __name__ == '__main__':
    list = ''
    for key in platforms:
        list += key + ' '
    print list[:-1]
