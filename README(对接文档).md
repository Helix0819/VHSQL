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

源码在parser文件夹，具体使用方法放了一个小demo

parser文件夹下make即可，命令行参要数提供解析的SQL语句



