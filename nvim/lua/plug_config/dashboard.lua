vim.g.dashboard_custom_header = {                                                                                
'   @@@@@@@@@@@          @,                                                      ',
'  @@          @@     .@@ %@%.@@@@@       @@@@@@@@@@@@@@@     @@                 ',
'  @@   @@@@@@@@      @@           @@@@    @@                 @@                 ',
'  @@@@@@@@@@         @@              &@@   @@@@@@@@@         @@                 ',
'  %@%       .@@@      @@               @@   @@               @@                 ',
'  #@#          @@@     @@             @@.   @@              @@                  ',
'  %@@            @@      @@@@    @@@@@                      @@@@@@@@@@@@@@      ',
'                                                                                ',
'                                                                                ',
'                                                                                ',
'                                 @@                            @@@@@%           ',
'       @@                                           @@@@@@    @@    @@          ',
'        @@         @@@*         @@               @@@      @@@(@(     @@         ',
'        @@        @@            @@           @@ @@          @@@(      @@        ',
'         @@     &@@             @@            @@@@           @@@       @@       ',
'          @@   (@@              #@*           @@@            @@@       @@       ',
'          @@   @@                @@            @@            %@@       @@       ',
'           @@ @@                 @@            @@             @@        @@      ',
'           @@@@                  @@            @@             @@        @@      ',
'           @@@                   @             @@             @@                ',
'                                               @@                               ',
'                                                                                '
}

vim.g.dashboard_default_executive = 'telescope'

vim.g.dashboard_custom_section = {
    a = {
        description = { '  New File                       LDR n' },
        command = 'enew',
    },
    c = {
        description = { '  Find Files                     LDR f' },
        command = 'Telescope find_files',
    },
    d = {
        description = { '  Find History                   LDR o' },
        command = 'Telescope oldfiles',
    },
    e = {
        description = { '  Configuration                       '},
        command = 'e ~/.config/nvim/lua/general.lua',
    },
    f = {
        description = { '  Plugins                             '},
        command = 'e ~/.config/nvim/lua/plugins.lua',
    },
}

local plugins_count = vim.fn.len(
    vim.fn.globpath('~/.local/share/nvim/site/pack/packer/start', '*', 0, 1)
)

vim.g.dashboard_custom_footer = {
    '-- Roflvim Loaded ' .. plugins_count .. ' Plugins --',
}

vim.cmd([[highlight DashboardHeader guifg=#66d9ef]])

