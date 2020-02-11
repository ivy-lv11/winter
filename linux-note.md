# "HH's Guide to Lunix"  
ctrl shift N   open a new terminal  
ctrl ++ zoom 
ctrl + - zoom out

## in tmux tmux使用 
ctrl B % 
ctrl B "
ctrl B x quit  
ctrl B j/l/k/h

## switch between the multitasks 多任务切换 
Alt + Tab  

## switch between the desktop 切换桌面 
ctrl  Alt left/right/up/down  

## less /etc/passwd  
display the info in a screen. use "space" to move forward  
and use "b" back  
"q" to quit.
"/" to search  
"^" at the beginning  
例子cat ch4.md | less
cat ch4.md | more  

## cal日历使用
display a calendar for a particular year.  
eg: cal 1952  
cal 2019 | less  
cal 12 1952		//specify a month  

## whoami  
whoami //lv
sudo whoami //root  

## Tab补全
不仅仅是文件名，还有命令也可以  
例如whoa<Tab> 得到 whoami  
 
## 查看磁盘使用和剩余空间  
df
详细man df  

## 安装软件 dpkg -i sth  
sudo apt-get install flameshot -y
sudo dpkg -i EasyConnect.deb  
sudo dpkg -i wps-office_11.1.0.9080_amd64.deb  

没有声音的问题  
https://blog.csdn.net/chusu2966/article/details/100617725  
lspci | grep Audio  
lsmod | grep snd  
alsamixer 调节音量大小   
sudo alsactl init  

## 快捷键  
home光标移到本行开头  
end移到末尾  


pwd返回当前工作目录名  
rm filename  
rm -rf folder 删除文件夹  
压缩文件夹 tar -czvf filename.tar.gz folder-name  
解压缩 tar -xzvf filename.tar.gz  

## 重定位  
直接开一个新文件，如果已有，原内容永久丢失sort > name  
把新内容加到后面sort >> name  
使用ctrl+D 来表示输入结束eol
默认是键盘输入，屏幕输出  
改为文件输入sort < name  

### wc 统计  
cat name names | grep aa | wc -l  
aa出现多少次  
| 表示pipeline,上一个的标准输出是下一个的标准输入  
  
### tee命令  
read data from standard input and send a copy to both standard output and to a file.  
例子 cat name names | tee a b | grep ad  

### grep命令  
grep ad name  
返回符合的行，到屏幕上  


## condition execution  
上一个命令成功执行了，才会执行下一个命令 command1 && command2  
只有上一个命令没有成功执行，才会去执行下一个命令 command1 || command2  
grep se name && sort name > t  

## filter  
### cat命令  
cat old new | grep Har | sort | less  
cat/grep/sort都是filter  
利用重定向cat < name > names 从name读入,输出到names中  
注意不要把输入重定向到输出  
  
### split命令  
split -d -a 3 data  

### tac命令（逆序输出行）  
tac [file...]  
tac name  

### rev命令（每一行逆序）  
rev [file...]  
rev graph | tac  

### head, tail命令  
head [OPTION] ... [FILE] ...   
例子cat name1 name2 | head -n 10| sort  
sort name1 | head -n 200 | less  

### colrm 命令  
colrm [start col [endcol]]  
colrm 24 30 < students | less  
不指定endcol，从开始start col全部删除  
colrm 5 < name  
TIPS: 标准输入，标准输出  

## cmp命令  
cmp file1 file2 由于该命令是按字节比较，所以可以比较文本、图像等等  

## comm命令  
input files must be sorted, which in many cases is not possible.  

### diff命令  
针对unsorted/large files  
diff [-bBiqswy] [-c|clilnes|-u|-Ulines] file1 file2  
the goal of the diff is to display the instructions you would need to follow to change the firstfile into thesecond file.  
the output of diff uses three different 1 character instructions :  
c(change),d(delete),a(append)  
例子3c3: change line 3 of the first file to line 3 of the second file.  
lines from the first file are marked by a < , lilnes from the second file are marked by a >.  
例子1a2
 > will  
this tells you hhow to change the first file into the second.  
append a single line to the first.append line 2 after line1  
 > 后面是加上的内容  
例子4d3
 < mark  
删去第四行mark的内容，<后面是删除的内容  

使用-i 忽略大小写  
使用-w,-b忽略whitespace  
-w 忽略所有whitespace, -b 忽略相同个数的  
-q tell if they are different
-s tell if they are identical  
-c/-u 更用户友好  

### cut 命令  
cut -c 5,6 name1  
cut -c 2,4-6 name1  
cut -c 5,6 name1 | sort  
cut -c 1,2 name1 | sort | grep as | wc -l  
选择区域  
cut -f 2 -d ':' name1  

### paste命令  
paste name1 name2  
paste name1 name2 -d ',' 修改分隔符  

### 统计文件夹下有多少个文件  
ls . | wc -l 
ls ch4.md -l  

### fold命令  
每行最多多少个字符 -w num  
fold -w 10 name1  

### nl命令  
nl file1 > file2  
nl file1 file2 | lpr  
设置起始的行号-v 100  
设置间隔-i 5  
例子nl file1 -i 5 -v 20 > file2  

 > grep命令  
从标准输入或者文件中读入，根据特征提取，输出到标准输出  
grep [-cilLnrsvwx] pattern [file...]  
grep < name1 skdf | cut -c 4-6  > age  
-c 计数  
-n 所在行 grep -n lv name1  
搜索多个文件的时候使用-l来显示所在的文件 grep lv name1 name2 -l  
-L does the opposite  
grep lv name1 name2 ch4.md -l | wc -l  
grep -ns pattern $(find .)  


