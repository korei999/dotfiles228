-- General config
vim.cmd 'colorscheme monokai_pro'
vim.opt['number'] = true
vim.opt['ruler'] = true
vim.opt['splitright'] = true
vim.opt['splitbelow'] = true
vim.opt['smarttab'] = true
vim.opt['expandtab'] = true
vim.opt['smartindent'] = true
vim.opt['autoindent'] = true
vim.opt['tabstop'] = 4
vim.opt['shiftwidth'] = 4
vim.opt['autoread'] = true
vim.opt['title'] = true
vim.opt['termguicolors'] = true
vim.opt['hlsearch'] = true
vim.opt['hidden'] = true
vim.opt['encoding'] = 'utf-8'
vim.opt['fileencoding'] = 'utf-8'
vim.opt['showmode'] = false
vim.opt['clipboard'] = 'unnamedplus'
vim.opt['swapfile'] = false
vim.opt['mouse'] = 'a'
vim.opt['updatetime'] = 300
vim.opt['timeoutlen'] = 0
-- vim.opt['ignorecase'] = true
vim.opt['smartcase'] = true
vim.opt['guicursor'] = 'i:block'

-- Persistent undo
vim.opt['undofile'] = true
vim.opt['undodir'] = '/home/korei/.cache/nvim/undo'
vim.opt['undolevels'] = 1000
vim.opt['undoreload'] = 10000

-- Stop comments on newline
vim.cmd([[autocmd BufWinEnter * :set formatoptions-=c formatoptions-=r formatoptions-=o]])

-- Disable lualine on Nvim-tree
vim.cmd ([[au BufEnter,BufWinEnter,WinEnter,CmdwinEnter * if bufname('%') == 'NvimTree' | set laststatus=0 | else | set laststatus=2 | endif]])

vim.cmd('command CDD cd %:p:h')

vim.cmd([[
    nnoremap x "_x
    nnoremap d "_d
    nnoremap D "_D
    vnoremap d "_d
    noremap h i
    noremap H I
    map i <Up>
    map j <Left>
    map k <Down>
]])

 --bindings
map = vim.api.nvim_set_keymap

-- LSP bindings: nivm/lua/plug_config/lsp_config/lsp-config.lua

map('n', '<Leader>n', ':enew<CR>', { noremap = true, silent = true })
map('n', '<Leader>f', ':Telescope find_files<CR>', { noremap = true, silent = true })
map('n', '<Leader>o', ':Telescope oldfiles<CR>', { noremap = true, silent = true })
map('n', '<Leader>[', ':vertical resize +7<CR>', { noremap = true, silent = true })
map('n', '<Leader>]', ':vertical resize -7<CR>', { noremap = true, silent = true })
map('n', '<Leader>cc', ':ColorizerToggle<CR>', { noremap = true, silent = true })
map('n', '<Leader>gg', ':LazyGit<CR>', { noremap = true, silent = true })
map('n', '<Leader>b', ':Bracey<CR>', { noremap = true, silent = true })
map('n', '<Leader>bb', ':BraceyStop<CR>', { noremap = true, silent = true })
map('n', '<Leader>bbb', ':BraceyReload<CR>', { noremap = true, silent = true })

map('n', 'f', ':BufferLinePick<CR>', { noremap = true, silent = true })
map('n', 'F', ':BufferLinePickClose<CR>', { noremap = true, silent = true })
map('n', 'm.', ':BufferLineMoveNext<CR>', { noremap = true, silent = true })
map('n', 'm,', ':BufferLineMovePrev<CR>', { noremap = true, silent = true })

map('n', '<Leader>dd', ':ToggleDiag<CR>', { noremap = true, silent = true })
map('n', '<leader>du', '<Plug>(toggle-lsp-diag-underline)', {silent = true })
map('n', '<leader>ds', '<Plug>(toggle-lsp-diag-signs)', {silent = true })
map('n', '<leader>dv', '<Plug>(toggle-lsp-diag-vtext)', {silent = true })
map('n', '<leader>di', '<Plug>(toggle-lsp-diag-update_in_insert)', {silent = true })

map('n', '<F7>', ':NvimTreeToggle<CR>', {silent = true })

map('n', '<leader>md', ':MarkdownPreviewToggle<CR>', {silent = true })
map('n', '<Leader><Space>', ':noh<CR>', { noremap = true, silent = true })

map('n', '<Leader>p', ':Neoformat<CR>', { noremap = true, silent = true })
