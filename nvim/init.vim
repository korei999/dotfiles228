:syntax enable
:set noswapfile
:set clipboard=unnamedplus
:let g:airline_powerline_fonts = 1
:let g:airline_left_sep = ' '
:let g:airline_right_sep = ' '

call plug#begin('~/.config/nvim/autoload/plugged')

    " Better Syntax Support
    Plug 'sheerun/vim-polyglot'
    " Auto pairs for '(' '[' '{'
    Plug 'jiangmiao/auto-pairs'
    Plug 'https://github.com/tpope/vim-commentary' " For Commenting gcc & gc
    Plug 'https://github.com/ap/vim-css-color' " CSS Color Preview
    Plug 'https://github.com/neoclide/coc.nvim'  " Auto Completion
    Plug 'vim-airline/vim-airline' " Lean & mean status/tabline for vim that's light as air.

call plug#end()

:set mouse=a
:set tabstop=8
:set shiftwidth=8
:set softtabstop=8
:set noexpandtab
:set smartindent
:set smarttab

nnoremap x "_x
nnoremap d "_d
nnoremap D "_D
vnoremap d "_d

nnoremap <leader>d ""d
nnoremap <leader>D ""D
vnoremap <leader>d ""d

let mapleader = ","
let g:mapleader = ","



