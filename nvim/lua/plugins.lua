return require('packer').startup(function(use)
    use 'wbthomason/packer.nvim'

    use 'L3MON4D3/LuaSnip'
    use 'glepnir/dashboard-nvim'
    use 'marko-cerovac/material.nvim'
    use 'sainnhe/sonokai'
    use 'tomasr/molokai'
    use 'tanvirtin/monokai.nvim'

    use 'neovim/nvim-lspconfig'
    use 'hrsh7th/nvim-cmp'
    use 'hrsh7th/cmp-buffer'
    use 'hrsh7th/cmp-nvim-lsp'
    use 'hrsh7th/cmp-path'
    use "saadparwaiz1/cmp_luasnip" -- snippet completions
    use 'williamboman/nvim-lsp-installer'
    use 'onsails/lspkind-nvim'
    use 'nvim-treesitter/nvim-treesitter'
    use 'nvim-treesitter/nvim-treesitter-refactor'
    use 'akinsho/nvim-toggleterm.lua'
    use 'windwp/nvim-autopairs'
    use 'windwp/nvim-ts-autotag'
    use 'norcalli/nvim-colorizer.lua'
    use 'WhoIsSethDaniel/toggle-lsp-diagnostics.nvim'
    use 'kdheepak/lazygit.nvim'
    use 'terrortylor/nvim-comment'
    use 'rafamadriz/friendly-snippets'
  
    use {
      'lewis6991/gitsigns.nvim',
      requires = {
        'nvim-lua/plenary.nvim'
      }
    }
  
    use {
      'akinsho/nvim-bufferline.lua',
      requires = 'kyazdani42/nvim-web-devicons'
    }
  
    use {
      'hoob3rt/lualine.nvim',
      requires = {
        'kyazdani42/nvim-web-devicons',
        opt = true
      }
    }
  
    use {
      'nvim-telescope/telescope.nvim',
      requires = {{'nvim-lua/popup.nvim'}, {'nvim-lua/plenary.nvim'}}
    }
    use {'nvim-telescope/telescope-fzf-native.nvim', run = 'make' }

  use {
    'kyazdani42/nvim-tree.lua',
    requires = 'kyazdani42/nvim-web-devicons',
    config = function() require'nvim-tree'.setup {} end
  }
  use {
  "folke/which-key.nvim",
  config = function()
    require("which-key").setup {
      -- your configuration comes here
      -- or leave it empty to use the default settings
      -- refer to the configuration section below
    }
  end
}

end)
