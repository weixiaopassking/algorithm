# SVN命令记录

svn checkout [YOUR_SOURCE, eg: https://xxx.com] [YOU_DIR, eg: D:\dir] --username [YOUR_USER_NAME] --password [YOUR_PASSWORD]

**解决svn树冲突，内容显示：**
D     C xxxxx.file
      >   本地文件未版本控制, 进入的文件增加 接着更新
...

**根目录下使用回滚解决**
svn revert --depth=infinity [DIR, eg: .\path\to\dir\]

svn delete [file_name]

svn rm --keep-local [file-to-remove]

svn diff -r HEAD <item>

svn diff -r PREV:COMMITTED <item>

**回滚到版本号25：**
svn merge -r 28:25 something

**svn批量删除和批量添加操作**
svn status|grep ! |awk '{print $2}'|xargs svn del

svn st | awk '{if ( $1 == "?") { print $2}}' | xargs svn add  

svn status|Findstr ! |get-content '{print $2}'|xargs svn del

**vscode将4个空格替换为tab字符**
Ctrl+Shift+P 之后输入命令:
>Convert indentation to Tabs

**VS Code中，代码格式化**
Shift + Alt + F

**unicode 与 utf-8的问题需要了解**

**MAC地址，IP地址，端口地址各自的功用，有没有功能重复的地方**


**CSD文件中锚点用于和父节点的(0, 0)相重合**

# python记录

**python父类和子类问题**

**python的多重继承问题  __mro__**

**isinstance() 与 type() 区别：**
type() 不会认为子类是一种父类类型，不考虑继承关系。
isinstance() 会认为子类是一种父类类型，考虑继承关系。
如果要判断两个类型是否相同推荐使用 isinstance()。


**python的__slots__使用**
通常情况下python的对象可以动态添加方法和属性，但为了给兑现限制这种自由可以使用__slot__
例如，可以使用如下方式给类添加属性和方法：
```
class Student(object):
    pass

>>> s = Student()
>>> s.name = 'Michael' # 动态给实例绑定一个属性
>>> print(s.name)
Michael

>>> def set_age(self, age): # 定义一个函数作为实例方法
		self.age = age

>>> from types import MethodType
>>> s.set_age = MethodType(set_age, s) # 给实例绑定一个方法
>>> s.set_age(25) # 调用实例方法
>>> s.age # 测试结果
25

```

为了限制这种动态性，在__slot__内填写方法名，类只可以有__slot__内的方法
```
class Student(object):
    __slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
	
>>> s = Student() # 创建新的实例
>>> s.name = 'Michael' # 绑定属性'name'
>>> s.age = 25 # 绑定属性'age'
>>> s.score = 99 # 绑定属性'score'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'Student' object has no attribute 'score'
```


**什么是\*args和\*\*kwargs？**
```
def foo(*args, **kwargs):
    print 'args = ', args
    print 'kwargs = ', kwargs
    print '---------------------------------------'

if __name__ == '__main__':
    foo(1,2,3,4)
    foo(a=1,b=2,c=3)
    foo(1,2,3,4, a=1,b=2,c=3)
    foo('a', 1, None, a=1, b='2', c=3)
```

输出结果如下：
args =  (1, 2, 3, 4)
kwargs =  {}
---------------------------------------
args =  ()
kwargs =  {'a': 1, 'c': 3, 'b': 2}
---------------------------------------
args =  (1, 2, 3, 4)
kwargs =  {'a': 1, 'c': 3, 'b': 2}
---------------------------------------
args =  ('a', 1, None)
kwargs =  {'a': 1, 'c': 3, 'b': '2'}
---------------------------------------

可以看到，这两个是python中的可变参数。* args表示任何多个无名参数，它是一个tuple；
\*\*kwargs表示关键字参数，它是一个dict。同时使用\*args和 \*\*kwargs时，必须\*args参数列要在\*\*kwargs前。


**python中的@property**
加了@property的装饰器之后，这个方法可以变成属性调用
```
class Student(object):

    @property
    def birth(self):
        return self._birth

    @birth.setter
    def birth(self, value):
        self._birth = value

    @property
    def age(self):
        return 2014 - self._birth
```
上面的birth是可读写属性，而age就是一个只读属性，因为age可以根据birth和当前时间计算出来。


**python的__new__, __init__, __call__方法解释**
```
class B:
    def __init__(self, *args, **kwargs):
        print("init", args, kwargs)

    def __new__(cls, *args, **kwargs):
        print("new", args, kwargs)
        return super().__new__(cls)

B(1, 2, 3)  
```
以下为输出结果：
new (1, 2, 3) {}
init (1, 2, 3) {}

__new__ 方法在构造一个类的对象实例时先被调用，然后返回一个实例对象，接着 __init__ 被调用。
如果在类中实现了 __call__ 方法，那么实例对象也将成为一个可调用对象。
利用这种特性可以实现基于类的装饰器，在类里面记录状态，比如，用于记录函数被调用的次数。


**enumerate解释**
将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中。
>>>seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))       # 下标从 1 开始
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]


**python的标准装饰器写法**
```
import functools

def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator
	
@log('execute')
def now():
    print('2015-3-25')
```

通过调用now()，最后输出的结果为：
```
>>> now()
execute now():
2015-3-25
```

结果解释：
1.调用now()等价于执行now = log('execute')(now)
程序首先执行log('execute')，返回的是decorator函数，再调用返回的函数，参数是now函数，返回值最终是wrapper函数。
2.@functools.wraps(func)的作用
经过decorator装饰之后的函数，它们的__name__已经从原来的'now'变成了'wrapper'，即now.__name__ 调用的输出结果为'wrapper'，因为返回的wrapper()函数名字就是'wrapper'，所以，需要把原始函数的__name__等属性复制到wrapper()函数中。Python内置的functools.wraps等价于wrapper.__name__ = func.__name__ 这样的代码。


**python中的@staticmethod和@classmethod有什么异同？**
相同点：
1.可以不需要实例化调用方法，从而达到静态方法的效果。
2.两者均不需要像其他实例方法那样添加一个表示自身对象的self参数。

不同点：
1.@classmethod不需要self参数，但需要一个表示自身类的cls参数。cls可以用于调用类的属性、方法，实例化对象等。
2.@classmethod的cls参数进行类的继承时，cls会变成子类本身，避免了硬编码。

在代码上的区别是：
```
def foo(self):
	print('foo')

@staticmethod
def static_foo():
	print('static_foo')
	print(Obj.bar)

@classmethod
def class_foo(cls):
	print('class_foo')
	print(cls.bar)
	cls().foo()
	print('class_static_foo')
	cls.static_foo()
```


**python中星号(\*)的用法**
1.单个星号有两个用法：将所有参数以元组(tuple)的形式导入，以及解压参数列表
单星号的用法代码示例：
```
>>> def foo(param1, *param2):
        print param1
        print param2
>>> foo(1,2,3,4,5)
1
(2, 3, 4, 5)

>>> def foo(bar, lee):
        print bar, lee
>>> l = [1, 2]
>>> foo(*l)
1 2
```

2.双星号的用法：将参数以字典的形式导入
```
>>> def bar(param1, **param2):
        print param1
        print param2
>>> bar(1,a=2,b=3)
1
{'a': 2, 'b': 3}
```

3.单星号和双星号可以出现在同一个函数中,例如
```
>>> def foo(a, b=10, *args, **kwargs):
        print a
        print b
        print args
        print kwargs
>>> foo(1, 2, 3, 4, e=5, f=6, g=7)
1
2
3 4
{'e': 5, 'g': 7, 'f': 6}
```


# Unity记录

**解决unity 相机缩放界面没有成比例变化问题**
DialogSystem18x9  ==>  Canvas Scaler  ==> UI Scale Mode  ==> Scale With Screen Size


enable是控制GameObject上的组件激活/关闭
setactive是控制GameObject对象显示/关闭


事件系统与单例问题：剧情选择按下按钮后content.text为空
单例与事件系统是有冲突的,考虑一下两句话的区别：
EventCenter.AddListener(EventType.DECLARE_YOUR_EVENT_TYPE, MyClass.Instance.callBackFunction);

EventCenter.AddListener(EventType.DECLARE_YOUR_EVENT_TYPE, callBackFunction);


安卓上测试时出现对话界面不执行下去的bug:
原因：gameObject的setActive(true)并不是立即生效的，而要到下一次update才能生效
解决方式：修改update里面的逻辑，setActive后的下一次update才能调用需要用的object


关于单例的讨论：

脚本类的静态变量在场景切换时是否一直都不会变化？

对应脚本内类的static变量在场景结束时候没有被销毁，instance还保存上次的旧单例对象，使用instance = this 语句后，原先保存在instance中的旧对象引用计数为0，instance赋新值，产生新的对象


相机空间与屏幕空间之间的变换有如下问题：
//设置为零时转换后的pos全为0,屏幕空间的原因
//不考虑相机变换
//btnWorldPos.z = 1.0f; 
//Vector3 btnpos = Camera.main.WorldToScreenPoint(btnWorldPos);

安卓可以手机连到电脑，打开调试模式，用logcat拉取log
adb logcat -v time process > logcat.txt

[加入unity 过滤]
adb logcat -s Unity  -v  time process > logcat.txt

摄像机开高倍镜解决方式：
修改摄像机的FOV

陷阱的管理：
使用tile based 的方式，每个网格有个标志位

人物移动起来后才发送人物的位置消息

Enity Componet System(ECS)  DANTS

正常的血条该怎么做？

MongoDB的使用

对后端的数据进行更好地拆分，账号和角色

未对特殊字符进行转义  (会发生sql注入的问题)

使用行为树来管理剧情选项

所有怪物AI逻辑混杂在一个函数之中  ==>  AI状态机，行为树

默认参数问题变成只读

解决某一层canvas不在最上面的问题：
修改canvas的sort order 数值越大越上面

Awake()函数调用的注意点：
1.游戏对象gameObject状态为关闭时，运行游戏，Awake()函数不会被调用；
2.不切换场景，原本关闭的【游戏对象首次】开启，调用Awake()函数，非首次开启不调用；
3.切换场景后再重新切换回来，Awake()函数会重新调用


Start()函数调用的问题：
1.Start函数只会在【脚本实例首次】被开启时才会执行。如果是已经开启过的脚本实例被关闭后再次开启，那么Start函数不会再次执行。

https://blog.csdn.net/iov3Rain/article/details/82146027

C#中List<int> 的复制构造是构造了一个引用。
