syntax enable
syntax on
filetype plugin indent on
"set colorschem with desert
colorscheme desert

"write the old file out when switching between file
set autowrite 

set timeoutlen=500

"switch between buffer without saving 
set hidden 

let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
"call wmtoggle with wm
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

nmap <C-_>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-_>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-_>d :cs find d <C-R>=expand("<cword>")<CR><CR>

nmap <F6> :cn<cr>
nmap <F7> :cp<cr>

let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplMapWindowNavArrows = 1

nnoremap <silent> <F12> :A<CR>

"set the grep command
nnoremap <silent> <F3> :Grep<CR>

let g:SuperTabDefaultCompletionType="<C-X><C-O>"
" 设置按下<Tab>后默认的补全方式, 默认是<C-P>, 
" 现在改为<C-X><C-O>. 关于<C-P>的补全方式, 
" 还有其他的补全方式, 你可以看看下面的一些帮助:
" :help ins-completion
" :help compl-omni
let g:SuperTabRetainCompletionType=2
" 0 - 不记录上次的补全方式
" 1 - 记住上次的补全方式,直到用其他的补全命令改变它
" 2 - 记住上次的补全方式,直到按ESC退出插入模式为止

filetype plugin indent on
set completeopt=longest,menu
"Markdown to HTML  
nmap md :%!/usr/local/bin/Markdown.pl --html4tags <cr>

"set line number
set number

"faster shoter comment for comment
map <leader>c <c-_><c-_>

"faster call to NERDTree
map <leader>n :NERDTree

"use pathogen 
call pathogen#infect()
