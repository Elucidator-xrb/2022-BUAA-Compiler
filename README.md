# SysY-MIPS编译器

> BUAA 编译原理与技术课程设计

SysY文法为C文法的真子集

## 一. 参考编译器介绍

> 总结所阅读的编译器的总体结构、接口设计、文件组织等内容

尚未阅读别人的编译器，接口均按课设要求

## 二. 编译器总体设计

> 介绍自己的将要实现的编译器的总体结构、接口设计、文件组织等内容

目前采用传统7模块编译器实现结构，多遍读取翻译。

## 三. 词法分析设计

> 编码前的设计、编码完成之后的修改    

## 四. 语法分析设计

> 编码前的设计、编码完成之后的修改

## 五. 错误处理设计

> 编码前的设计、编码完成之后的修改

## 六. 代码生成设计

> 编码前的设计、编码完成之后的修改

关于各parse函数间消息传递的参数名，我们约定：

- OUT_xxx 表示通过函数参数，将数据xxx传出函数
- IN_xxx 表示通过函数参数，从函数外部传入的数据xxx
- GET_xxx 表示在函数内通过调用其他函数获取的数据xxx
- PUT_xxx 表示在函数内向其他函数传递数据xxx
- xxx 函数声明的形参用名，表名数据实体xxx

（有点像http协议的请求）

错误处理时对各parse函数的调整（参数和返回值）设计的并不是很好；这也会与代码生成时的调整相互错杂糅合，很难搞，先不管它最后再合并吧



ConstInitVal 的文法设计很怪，加上语义限制的话，完全可以改成更好的递归表述

改为:

```
ConstInitVal → ConstExp | '{' ConstInitVal { ',' ConstInitVal } '}'
```



生成mips

- 临时变量消除
- 变量名变成唯一标识： 通过加上#layerNo#来区分
- t寄存器也需要保存



- DEF_END 和 DEF_FUN_END 可能还是得区分一下（但好像不影响正确性）



## 七. 代码优化设计 

> 编码前的设计、编码完成之后的修改，未选择MIPS代码生成的同学无需完成此项内容





关于编译器代码本身的优化：

- 看看有没有可以改为emplace_back()的vector容器操作
- 视情况，为每个类补充“拷贝构造函数”和”移动构造函数“
- 将.h的具体函数代码移至.cpp中
- 梳理头文件引用，现在是随便引



除法（尤其是%，纯数（const value）的话可以优化）