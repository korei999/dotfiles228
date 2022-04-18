vim.opt.termguicolors = true

-- include plugins and their config
require('plugins')
require('plug_config.treesitter')
require('plug_config.autopairs')
require('plug_config.colour')
require('plug_config.toggleTerm')
require('plug_config.lualine')
require('plug_config.colorizer')
require('plug_config.toggle_lsp_diagnostics')
require('plug_config.lsp_config.lsp-cmp')
require('plug_config.lsp_config.lsp-config')
require('plug_config.lazygit')
require('plug_config.comment')
require('plug_config.bufferline')
require('plug_config.gitsigns')
require('plug_config.dashboard')
require('plug_config.nvim-tree')
require('plug_config.telescope')
require('plug_config.whichkey')


require('general')

-- CpHelper config
vim.g.cphdir = '/home/problems'

-- Rooter config
vim.g.rooter_pattern = { 'input1', 'output1' }
