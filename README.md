# README

很久前写的

只实现了简单的增改查

## Linux下编译运行

```shell
> make 
```

## Tree B+树主体

主要实现如下函数

```c++
private:
	/*插入自平衡*/
	void insertBalance(Node* node);
	/*删除自平衡*/
	void deleteBalance(Node* node);
public:
	/*查找结点接口*/
	bool findElem(int num, Node* node);
	/*更新结点接口*/
	bool modifyElem(int origin, int changed, Node* node); 
	/*删除结点接口*/
	bool deleteElem(int num, Node* node); 
	/*插入结点接口*/
	void insertElem(int num, Node* node);
```

## demo

用于测试的main函数

实现依次插入值14 ~ 1，100 ~ 114， 65 ~ 41， 7， 7的结点

然后依次删除值7， 7， 8

**正常编译运行结果**

```shell
> ./B+Tree
1 2
3 4 5
6 7
9 10 11
12 13
14 41 42
43 44 45
46 47 48
49 50 51
52 53 54
55 56 57
58 59 60
61 62 63
64 65 100
101 102
103 104
105 106
107 108
109 110
111 112 113 114
```

其中每次行表示一个B+树叶子结点，默认每个结点包含4个元素

## BUG

删除部分尚有bug，比如删除值100 ~ 111的结点，会出现如下信息

```shell
pos: -1 size: 3
Error: illegal position in getElem !
1 2
3 4 5
6 7
9 10 11
12 13
14 41 42
43 44 45
46 47 48
49 50 51
52 53 54
55 56 57
58 59 60
61 62 63
64 65

112 113 114
```

猜想是删除时的B+树自平衡函数有问题，暂时还没有找到好的解决方法

