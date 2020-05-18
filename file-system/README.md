使用make进行编译,NAME=...指定编译文件  
dup.c管道  
create.c文件创建读写  
dirent.c目录遍历  
##### hard link
ln old new  
创建别名，没有真正新建文件，修改link数量，通过stat查看。它们的inode一样，通过ls -i 或者stat查看。  
##### soft link
ln -s old new
和hard link一样，修改new，old也发生了变化  
具体见chapter 39  
##### mount

