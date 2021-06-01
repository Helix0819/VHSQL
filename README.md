# VHSQL

## 介绍
使用C++开发的微型DBMS,前端语法解析器使用Flex/Bison生成




## 安装教程

1.  在root模式下执行make install，安装需要使用的静态库，可通过make uninstall卸载
2.  make即可
3.  main为生成的可执行文件

## 使用说明

1.  目前仅支持TEXT、INT俩种数据类型
2.  INSERT 语句仅支持 'INSERT INTO <TABLE> VALUES (...)'语法，不支持只插入指定列
3.  xxxx

## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


## 参考
前端语法分析器参考了：
https://github.com/hyrise/sql-parser/releases
并在此基础上添加了

1.CREATE DATABASE <DBNAME>;

2.DROP DATABASE <DBNAME>;

3.USE <DBNAME>

的解析。
