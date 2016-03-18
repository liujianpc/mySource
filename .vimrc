""c文件的自动补全功能，有三个插件，1.一个是vim/template文件夹里的tpl.c（所有格式的文件均可以按此建立一个tpl模板）,2.还有.vimrc脚本文件中的一段代码可以设置c和cpp等文件的模板。3.c插件里的模板的c-surport/c.comments.template里面
"
""F1查看帮助文件
""F2去空行  C-F2 比较文件  alt+F2新建标签栏
""F3查找光标所在的单词  C-F3打开树状文件目录
""F4查看当前目录的所有文件列表
""F5编译代码和运行
""F6显示当前文件的Taglist（Tlist）Ctrl+W切换到窗口
""F7 NERDTree命令
""F8 Gdb调试
""F9调用存储输入数据函数
""F10
""F11全文缩进
""F12 :A命令，源代码和头文件之间的切换  C-F12生存tags文件
""<leader>w :w!
""<leader>f :find
""<leader>lk <Plug>LookupFile<cr>   "映射LookupFile为,lk
""<leader>ll :LUBufs<cr>            "映射LUBufs为,ll
""<leader>lw :LUWalk<cr>            "映射LUWalk为,lw
filetype plugin on
filetype indent on
map <F9> :call SaveInputData()<CR>
func! SaveInputData()
	exec "tabnew"
	exec 'normal "+gP'
	exec "w! /tmp/input_data"
endfunc
"colorscheme torte
"colorscheme murphy
"colorscheme desert 
"colorscheme desert 
"colorscheme elflord
colorscheme seoul256
"set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
let &termencoding=&encoding
set fileencodings=utf-8,gbk,big5
"set fileencoding=utf-8
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"设置自己的模板
let g:template_load = 1
let g:template_tags_replacing = 1
let g:T_AUTHOR = "liujianpc"
let g:T_AUTHOR_EMAIL = "ljlovelife@foxmail.com"
let g:T_AUTHOR_WEBSITE = "http://www.prettyapp.sinaapp.com"
let g:T_CREATE_DATE = "..".strftime("%c")
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"设置python补全
 let g:pydiction_location = 'D:\Program Files\Vim\vimfiles\complete-dict' 
" 显示相关  
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
au GUIEnter * simalt ~x
set shortmess=atI   " 启动的时候不显示那个援助乌干达儿童的提示  
winpos 5 5          " 设定窗口位置  
set lines=40 columns=155    " 设定窗口大小  
set go=             " 不要图形按钮  
"color seoul256    " 设置背景主题  
""set guifont=Monaco:h12:cANSI   " 设置字体  
set guifont=consolas:h14:cANSI   " 设置字体  
syntax on           " 语法高亮  
autocmd InsertLeave * se nocul  " 用浅色高亮当前行  
autocmd InsertEnter * se cul    " 用浅色高亮当前行  
set ruler           " 显示标尺  
set showcmd         " 输入的命令显示出来，看的清楚些  
set cmdheight=1     " 命令行（在状态行下）的高度，设置为1  
set whichwrap+=<,>,h,l   " 允许backspace和光标键跨越行边界(不建议)  
set scrolloff=3     " 光标移动到buffer的顶部和底部时保持3行距离  
set novisualbell    " 不要闪烁(不明白)  
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   "状态行显示的内容  
set laststatus=1    " 启动显示状态行(1),总是显示状态行(2)  
set foldenable      " 允许折叠  
set foldmethod=manual   " 手动折叠  
set background=dark "背景使用黑色 
set nocompatible  "去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限  
" 显示中文帮助
if version >= 603
	set helplang=cn
	set encoding=utf-8
endif
" 设置配色方案
"colorscheme murphy
"字体 
"if (has("gui_running")) 
"   set guifont=Bitstream\ Vera\ Sans\ Mono\ 10 
"endif
" 开启文件类型检测
filetype plugin on
filetype indent on
"开启C插件
let  g:C_UseTool_cmake    = 'yes' 
let  g:C_UseTool_doxygen = 'yes'
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""新文件标题
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"新建.c,.h,.sh,.java文件，自动插入文件头 
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()" 
""定义函数SetTitle，自动插入文件头 
func SetTitle() 
	"如果文件类型为.sh文件 
	if &filetype == 'sh' 
		call setline(1,"\#########################################################################") 
		call append(line("."), "\# File Name: ".expand("%")) 
		call append(line(".")+1, "\# Author: liujianpc") 
		call append(line(".")+2, "\# mail: zhouhu8899@163.com") 
		call append(line(".")+3, "\# Created Time: ".strftime("%c")) 
		call append(line(".")+4, "\#########################################################################") 
		call append(line(".")+5, "\#!/bin/bash") 
		call append(line(".")+6, "") 

	else 
		call setline(1, "/*************************************************************************") 
		call append(line("."), "*    File Name: ".expand("%")) 
		call append(line(".")+1, "*    Author: liujianpc") 
		call append(line(".")+2, "*    Email: zhouhu8899@163.com ") 
		call append(line(".")+3, "*    Created: ".strftime("%c")) 
		call append(line(".")+4, " ************************************************************************/") 
		call append(line(".")+5, "")
	
	endif
	if &filetype == 'cpp'
		call append(line(".")+6, "#include<iostream>")
		call append(line(".")+7, "using namespace std;")
		call append(line(".")+8, "int main(void)")
		call append(line(".")+9, "{")
		call append(line(".")+10, "")
		call append(line(".")+11, "    return 0;")
		call append(line(".")+12, "}")
	endif
	if &filetype == 'c'

		call append(line(".")+6, "#include<stdio.h>")
		call append(line(".")+7, "#include<stdlib.h>")
		call append(line(".")+8, "int main(void)")
		call append(line(".")+9, "{")
		call append(line(".")+10, "")
		call append(line(".")+11, "    return 0;")
		call append(line(".")+12, "}")
	endif
	if &filetype == 'java'
			call append(line(".")+6,"public class ")
			call append(line(".")+7,"")
		endif
	
	"新建文件后，自动定位到文件末尾
	autocmd BufNewFile * normal G
endfunc 
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"键盘命令
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
iab xtime <c-r>=strftime("%Y-%m-%d %H:%M:%S")<cr> 
let mapleader=","
nmap <leader>w :w!<cr>
nmap <leader>f :find<cr>
" 映射全选+复制 ctrl+a
map <C-A> ggVGY
map! <C-A> <Esc>ggVGY
map <F11> gg=G
" 选中状态下 Ctrl+c 复制
vmap <C-c> "+y
"去空行  
nnoremap <F2> :g/^\s*$/d<CR> 
"比较文件  
nnoremap <C-F2> :vert diffsplit 
"新建标签  
map <M-F2> :tabnew<CR>  
"列出当前目录文件  
map <F4> :tabnew .<CR>  
"打开树状文件目录  
map <C-F3> \be  
"C，C++ 按F5编译运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
	if &filetype == 'c'
		exec "!g++ % -o %<"
		exec "! %<"
	elseif &filetype == 'cpp'
		exec "!g++ % -o %<"
		exec "! %<"
	elseif &filetype == 'java' 
		exec "!javac %" 
		exec "!java %<"
	elseif &filetype == 'sh'
		:!./%
	elseif &filetype == 'py'
		exec "!python %"
		exec "!python %<"
	endif
endfunc
"C,C++的调试
map <F8> :call Rungdb()<CR>
func! Rungdb()
	exec "w"
	exec "!g++ % -g -o %<"
	exec "!gdb ./%<"
endfunc
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
""实用设置
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 设置当文件被改动时自动载入
set autoread
" quickfix模式
autocmd FileType c,cpp map <buffer> <leader><space> :w<cr>:make<cr> 
" 允许backspace和光标键跨越行边界
"代码补全 
set completeopt=preview,menu 
"允许插件  
filetype plugin on
"共享剪贴板  
set clipboard+=unnamed 
"从不备份  
set nobackup
"make 运行
:set makeprg=g++\ -Wall\ \ %
"自动保存
set autowrite
set ruler                   " 打开状态栏标尺
set cursorline              " 突出显示当前行
set magic                   " 设置魔术
set guioptions-=T           " 隐藏工具栏
set guioptions-=m           " 隐藏菜单栏
set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)\
" 设置在状态行显示的信息
set foldcolumn=0
set foldmethod=indent 
set foldlevel=3 
set foldenable              " 开始折叠
" 不要使用vi的键盘模式，而是vim自己的
set nocompatible
" 语法高亮
set syntax=on
" 去掉输入错误的提示声音
set noeb
" 在处理未保存或只读文件的时候，弹出确认
set confirm
" 自动缩进
set autoindent
set cindent
" Tab键的宽度
set tabstop=4
" 统一缩进为4
set softtabstop=4
set shiftwidth=4
" 不要用空格代替制表符
set noexpandtab
" 在行和段开始处使用制表符
set smarttab
" 显示行号
set number
" 历史记录数
set history=1000
"禁止生成临时文件
set nobackup
set noswapfile
"搜索忽略大小写
set ignorecase
"搜索逐字符高亮
set hlsearch
set incsearch
"行内替换
set gdefault
"编码设置
set enc=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
"语言设置
set langmenu=zh_CN.UTF-8
set helplang=cn
" 我的状态行显示的内容（包括文件类型和解码）
"set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
"set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
" 总是显示状态行
set laststatus=2
" 命令行（在状态行下）的高度，默认为1，这里是2
set cmdheight=2
" 侦测文件类型
filetype on
" 载入文件类型插件
filetype plugin on
" 为特定文件类型载入相关缩进文件
filetype indent on
" 保存全局变量
set viminfo+=!
" 带有如下符号的单词不要被换行分割
set iskeyword+=_,$,@,%,#,-
" 字符间插入的像素行数目
set linespace=0
" 增强模式中的命令行自动完成操作
set wildmenu
" 使回格键（backspace）正常处理indent, eol, start等
set backspace=2
" 允许backspace和光标键跨越行边界
set whichwrap+=<,>,h,l
" 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）
set mouse=a
set selection=exclusive
set selectmode=mouse,key
" 通过使用: commands命令，告诉我们文件的哪一行被改变过
set report=0
" 在被分割的窗口间显示空白，便于阅读
set fillchars=vert:\ ,stl:\ ,stlnc:\
" 高亮显示匹配的括号
set showmatch
" 匹配括号高亮的时间（单位是十分之一秒）
set matchtime=1
" 光标移动到buffer的顶部和底部时保持3行距离
set scrolloff=3
" 为C程序提供自动缩进
set smartindent
" 高亮显示普通txt文件（需要txt.vim脚本）
au BufRead,BufNewFile *  setfiletype txt
"解决乱码
set encoding=utf-8  
  
set fileencodings=utf-8,chinese,latin-1  
  
if has("win32")  
  
 set fileencoding=chinese  
  
else  
  
 set fileencoding=utf-8  
  
endif  
  
"解决菜单乱码  
  
source $VIMRUNTIME/delmenu.vim  
  
source $VIMRUNTIME/menu.vim  
  
"解决consle输出乱码  
language messages zh_CN.utf-8  

"自动补全
:inoremap ( ()<ESC>i
:inoremap ) <c-r>=ClosePair(')')<CR>
:inoremap { {<CR>}<ESC>O
:inoremap } <c-r>=ClosePair('}')<CR>
:inoremap [ []<ESC>i
:inoremap ] <c-r>=ClosePair(']')<CR>
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
function! ClosePair(char)
	if getline('.')[col('.') - 1] == a:char
		return "\<Right>"
	else
		return a:char
	endif
endfunction
filetype plugin indent on 
set nocp
"打开文件类型检测, 加了这句才可以用智能补全
set  dictionary+=D:\ctags\c-c++-keywords.list
set  dictionary+=D:\ctags\k+r.list
set  dictionary+=D:\ctags\stl_index.list
set  dictionary+=D:\ctags\keywords.list
"set completeopt=longest,menu
"设置SuperTab，用tab键打开cppcomplet的自动补全功能。
let g:SuperTabRetainCompletionType=2
let g:SuperTabDefaultCompletionType="<C-X><C-O>"
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"NERDtee设定
let NERDChristmasTree=1
let NERDTreeAutoCenter=1
let NERDTreeBookmarksFile=$VIM.'\Data\NerdBookmarks.txt'
let NERDTreeMouseMode=2
let NERDTreeShowBookmarks=1
let NERDTreeShowFiles=1
let NERDTreeShowHidden=1
let NERDTreeShowLineNumbers=1
let NERDTreeWinPos='left'
let NERDTreeWinSize=31
nnoremap f :NERDTreeToggle
map <F7> :NERDTree<CR>  
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set tags+=tags;
set tags+=D:\ctags\tags\cpp;
set tags+=D:\ctags\tags\mingw;
set autochdir
map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>
" OmniCppComplete
let OmniCpp_NamespaceSearch = 1
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_ShowAccess = 1
let OmniCpp_ShowPrototypeInAbbr = 1 " show function parameters
let OmniCpp_MayCompleteDot = 1 " autocomplete after .
let OmniCpp_MayCompleteArrow = 1 " autocomplete after ->
let OmniCpp_MayCompleteScope = 1 " autocomplete after ::
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]
" automatically open and close the popup menu / preview window
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest,preview

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
map <F6> :Tlist<CR>
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:miniBufExplMapCTabSwitchBufs=1
let g:miniBufExplMapWindowsNavVim=1
let g:miniBufExplMapWindowNavArrows=1
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
nnoremap <silent> <F12> :A<CR>
nnoremap <silent> <F3> :Grep<CR></cr>
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
au FileType php call AddPHPFuncList()

function AddPHPFuncList()

    set dictionary-=$VIM/vimfiles/extra/php_funclist.txt dictionary+=$VIM/vimfiles/extra/php_funclist.txt

    set complete-=k complete+=k

endfunction
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"代码自动补全  （按快捷键Ctrl+X+O）

set autoindent

set omnifunc=syntaxcomplete#Complete

autocmd FileType python set omnifunc=pythoncomplete#Complete

autocmd FileType javascrīpt set omnifunc=javascrīptcomplete#CompleteJS

autocmd FileType html set omnifunc=htmlcomplete#CompleteTags

autocmd FileType css set omnifunc=csscomplete#CompleteCSS

autocmd FileType xml set omnifunc=xmlcomplete#CompleteTags

autocmd FileType php set omnifunc=phpcomplete#CompletePHP

autocmd FileType c set omnifunc=ccomplete#Complete
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"关键字补全 （快捷键 Ctrl+P）
inoremap ( ()<Esc>i

inoremap [ []<Esc>i

inoremap { {<CR>}<Esc>O

autocmd Syntax html,vim inoremap < <lt>><Esc>i|inoremap > <c-r>=ClosePair('>')<CR>

inoremap ) <c-r>=ClosePair(')')<CR>

inoremap ] <c-r>=ClosePair(']')<CR>

inoremap } <c-r>=CloseBracket()<CR>

inoremap " <c-r>=QuoteDelim('"')<CR>

inoremap ' <c-r>=QuoteDelim("'")<CR>



function CloseBracket()

 if match(getline(line('.') + 1), '\s*}') < 0

 return "\<CR>}"

 else

 return "\<Esc>j0f}a"

 endif

endf

 

function QuoteDelim(char)

 let line = getline('.')

 let col = col('.')

 if line[col - 2] == "\\"

 "Inserting a quoted quotation mark into the string

 return a:char

 elseif line[col - 1] == a:char

 "Escaping out of the string

 return "\<Right>"

 else

 "Starting a string

 return a:char.a:char."\<Esc>i"

 endif

endf
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"====================Lookupfile 相关设置========================================
let g:LookupFile_MinPatLength = 2               "最少输入2个字符才开始查找
let g:LookupFile_PreserveLastPattern = 0        "不保存上次查找的字符串
let g:LookupFile_PreservePatternHistory = 1     "保存查找历史
let g:LookupFile_AlwaysAcceptFirst = 1          "回车打开第一个匹配项目
let g:LookupFile_AllowNewFiles = 0              "不允许创建不存在的文件
if filereadable("./filenametags")                "设置tag文件的名字
    let g:LookupFile_TagExpr = '"./filenametags"'
endif
"nmap <silent> <leader>lk <Plug>LookupFile<cr>   "映射LookupFile为,lk
"nmap <silent> <leader>ll :LUBufs<cr>            "映射LUBufs为,ll
"nmap <silent> <leader>lw :LUWalk<cr>            "映射LUWalk为,lw
"有了上面的定义，当我输入”,lk”时，就会在tag文件中查找指定的文件名；
"当输入”,ll”时，就会在当前已打开的buffer中查找指定名字的buffer；
"当输入”,lw”时，就会在指定目录结构中查找。
"在用lookupfile插件查找文件时，是区分文件名的大小写的，
"如果想进行忽略大小写的匹配，把下面这段代码加入你的vimrc中，
"就可以每次在查找文件时都忽略大小写查找了：
" lookup file with ignore case
function! LookupFile_IgnoreCaseFunc(pattern)
    let _tags = &tags
    try
        let &tags = eval(g:LookupFile_TagExpr)
        let newpattern = '/c' . a:pattern
        let tags = taglist(newpattern)
    catch
        echohl ErrorMsg | echo "Exception: " . v:exception | echohl NONE
        return ""
    finally
        let &tags = _tags
    endtry
    " Show the matches for what is typed so far.
    let files = map(tags, 'v:val["filename"]')
    return files
endfunction
let g:LookupFile_LookupFunc = 'LookupFile_IgnoreCaseFunc'
"====================Lookupfile 相关设置 end========================================
"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
" Add by minico---end
"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
