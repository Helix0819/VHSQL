# DBMS

#### 介绍

在根目录下建立两个文件夹，一个是code（是工程代码区），一个是data（是工程DBMS根目录）







#### 接口

==DDL==

创建数据库：creatDb

删除数据库：dropDb

切换数据库：useDb

创建表：creatTable

删除表：dropTable



#### SQLParser

找了一个开源的SQLParser 使用flex&bison 编写

源码在parser文件夹，具体使用方法在parser/src放了一个小demo

在parser文件夹下make即可，添加命令行参数提供要解析的SQL语句

补充:
makefile中添加了install、uninstall
root 模式下运行 make install 

######################################################################

在table类下添加del方法，实现删除指定行（但是当前仅实现了OP为=的情况）

main.cpp中已添加del方法的测试 make后运行 /data/student/student.dat中第二行数据将被删除

即helix 40这一行

todo:OP > < 等仍需实现

######################################################################
 
更换了新的前端SQL解析器

添加了DROP DATABASE DBNAME的解析


