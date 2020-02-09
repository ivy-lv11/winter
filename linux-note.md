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



## condition execution  
上一个命令成功执行了，才会执行下一个命令 command1 && command2  
只有上一个命令没有成功执行，才会去执行下一个命令 command1 || command2  
grep se name && sort name > t  
 
