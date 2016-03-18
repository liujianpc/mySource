　对于这个系列里的问题，每个学Java的人都应该搞懂。当然，如果只是学Java玩玩就无所谓了。如果你认为自己已经超越初学者了，却不很懂这些问题，请将你自己重归初学者行列。内容均来自于CSDN的经典老贴。

　　问题一：我声明了什么！

  
String s = "Hello world!";

　　许多人都做过这样的事情，但是，我们到底声明了什么？回答通常是：一个String，内容是“Hello world!”。这样模糊的回答通常是概念不清的根源。如果要准确的回答，一半的人大概会回答错误。
这个语句声明的是一个指向对象的引用，名为“s”，可以指向类型为String的任何对象，目前指向"Hello world!"这个String类型的对象。这就是真正发生的事情。我们并没有声明一个String对象，我们只是声明了一个只能指向String对象的引用变量。所以，如果在刚才那句语句后面，如果再运行一句：

String string = s;

　　我们是声明了另外一个只能指向String对象的引用，名为string，并没有第二个对象产生，string还是指向原来那个对象，也就是，和s指向同一个对象。

　　问题二："=="和equals方法究竟有什么区别？

　　==操作符专门用来比较变量的值是否相等。比较好理解的一点是：

int a=10;
int b=10;

　　则a==b将是true。
　　但不好理解的地方是：

String a=new String("foo");
String b=new String("foo");

　　则a==b将返回false。

　　根据前一帖说过，对象变量其实是一个引用，它们的值是指向对象所在的内存地址，而不是对象本身。a和b都使用了new操作符，意味着将在内存中产生两个内容为"foo"的字符串，既然是“两个”，它们自然位于不同的内存地址。a和b的值其实是两个不同的内存地址的值，所以使用"=="操作符，结果会是false。诚然，a和b所指的对象，它们的内容都是"foo"，应该是“相等”，但是==操作符并不涉及到对象内容的比较。

　　对象内容的比较，正是equals方法做的事。

　　看一下Object对象的equals方法是如何实现的：

boolean equals(Object o){
return this==o;
}

　　Object对象默认使用了==操作符。所以如果你自创的类没有覆盖equals方法，那你的类使用equals和使用==会得到同样的结果。同样也可以看出，Object的equals方法没有达到equals方法应该达到的目标：比较两个对象内容是否相等。因为答案应该由类的创建者决定，所以Object把这个任务留给了类的创建者。

　　看一下一个极端的类：

Class Monster{
private String content;
...
boolean equals(Object another){ return true;}
}

　　覆盖了equals方法。这个实现会导致无论Monster实例内容如何，它们之间的比较永远返回true。

　　所以当你是用equals方法判断对象的内容是否相等，请不要想当然。因为可能你认为相等，而这个类的作者不这样认为，而类的equals方法的实现是由他掌握的。如果你需要使用equals方法，或者使用任何基于散列码的集合（HashSet,HashMap,HashTable），请察看一下java doc以确认这个类的equals逻辑是如何实现的。

 

　　问题三：String到底变了没有？

　　没有。因为String被设计成不可变(immutable)类，所以它的所有对象都是不可变对象。请看下列代码：

String s = "Hello";
s = s + " world!";

　　s所指向的对象是否改变了呢？从本系列第一篇的结论很容易导出这个结论。我们来看看发生了什么事情。在这段代码中，s原先指向一个String 对象，内容是"Hello"，然后我们对s进行了+操作，那么s所指向的那个对象是否发生了改变呢？答案是没有。这时，s不指向原来那个对象了，而指向了另一个String对象，内容为"Hello world!"，原来那个对象还存在于内存之中，只是s这个引用变量不再指向它了。

　　通过上面的说明，我们很容易导出另一个结论，如果经常对字符串进行各种各样的修改，或者说，不可预见的修改，那么使用String来代表字符串的话会引起很大的内存开销。因为String对象建立之后不能再改变，所以对于每一个不同的字符串，都需要一个String对象来表示。这时，应该考虑使用StringBuffer类，它允许修改，而不是每个不同的字符串都要生成一个新的对象。并且，这两种类的对象转换十分容易。 

　　同时，我们还可以知道，如果要使用内容相同的字符串，不必每次都new一个String。例如我们要在构造器中对一个名叫s的String引用变量进行初始化，把它设置为初始值，应当这样做：

public class Demo {
private String s;
...
public Demo {
s = "Initial Value";
}
...
}

　　而非

　　s = new String("Initial Value");

　　后者每次都会调用构造器，生成新对象，性能低下且内存开销大，并且没有意义，因为String对象不可改变，所以对于内容相同的字符串，只要一个String对象来表示就可以了。也就说，多次调用上面的构造器创建多个对象，他们的String类型属性s都指向同一个对象。

　　上面的结论还基于这样一个事实：对于字符串常量，如果内容相同，Java认为它们代表同一个String对象。而用关键字new调用构造器，总是会创建一个新的对象，无论内容是否相同。

　　至于为什么要把String类设计成不可变类，是它的用途决定的。其实不只String，很多Java标准类库中的类都是不可变的。在开发一个系统的时候，我们有时候也需要设计不可变类，来传递一组相关的值，这也是面向对象思想的体现。不可变类有一些优点，比如因为它的对象是只读的，所以多线程并发访问也不会有任何问题。当然也有一些缺点，比如每个不同的状态都要一个对象来代表，可能会造成性能上的问题。所以Java标准类库还提供了一个可变版本，即StringBuffer。

　　问题四：final关键字到底修饰了什么？

　　final使得被修饰的变量"不变"，但是由于对象型变量的本质是“引用”，使得“不变”也有了两种含义：引用本身的不变，和引用指向的对象不变。

　　引用本身的不变：

final StringBuffer a=new StringBuffer("immutable");
final StringBuffer b=new StringBuffer("not immutable");
a=b;//编译期错误

　　引用指向的对象不变：

final StringBuffer a=new StringBuffer("immutable");
a.append(" broken!"); //编译通过

　　可见，final只对引用的“值”(也即它所指向的那个对象的内存地址)有效，它迫使引用只能指向初始指向的那个对象，改变它的指向会导致编译期错误。至于它所指向的对象的变化，final是不负责的。这很类似==操作符：==操作符只负责引用的“值”相等，至于这个地址所指向的对象内容是否相等，==操作符是不管的。

　　理解final问题有很重要的含义。许多程序漏洞都基于此----final只能保证引用永远指向固定对象，不能保证那个对象的状态不变。在多线程的操作中,一个对象会被多个线程共享或修改，一个线程对对象无意识的修改可能会导致另一个使用此对象的线程崩溃。一个错误的解决方法就是在此对象新建的时候把它声明为final，意图使得它“永远不变”。其实那是徒劳的。

 

　　问题五：到底要怎么样初始化！

　　本问题讨论变量的初始化，所以先来看一下Java中有哪些种类的变量。

1. 类的属性，或者叫值域
2. 方法里的局部变量
3. 方法的参数

　　对于第一种变量，Java虚拟机会自动进行初始化。如果给出了初始值，则初始化为该初始值。如果没有给出，则把它初始化为该类型变量的默认初始值。

int类型变量默认初始值为0
float类型变量默认初始值为0.0f
double类型变量默认初始值为0.0
boolean类型变量默认初始值为false
char类型变量默认初始值为0(ASCII码)
long类型变量默认初始值为0

　　所有对象引用类型变量默认初始值为null，即不指向任何对象。注意数组本身也是对象，所以没有初始化的数组引用在自动初始化后其值也是null。

　　对于两种不同的类属性，static属性与instance属性，初始化的时机是不同的。instance属性在创建实例的时候初始化，static属性在类加载，也就是第一次用到这个类的时候初始化，对于后来的实例的创建，不再次进行初始化。这个问题会在以后的系列中进行详细讨论。 

　　对于第二种变量，必须明确地进行初始化。如果再没有初始化之前就试图使用它，编译器会抗议。如果初始化的语句在try块中或if块中，也必须要让它在第一次使用前一定能够得到赋值。也就是说，把初始化语句放在只有if块的条件判断语句中编译器也会抗议，因为执行的时候可能不符合if后面的判断条件，如此一来初始化语句就不会被执行了，这就违反了局部变量使用前必须初始化的规定。但如果在else块中也有初始化语句，就可以通过编译，因为无论如何，总有至少一条初始化语句会被执行，不会发生使用前未被初始化的事情。对于try-catch也是一样，如果只有在try块里才有初始化语句，编译部通过。如果在catch或finally里也有，则可以通过编译。总之，要保证局部变量在使用之前一定被初始化了。所以，一个好的做法是在声明他们的时候就初始化他们，如果不知道要出事化成什么值好，就用上面的默认值吧！

　　其实第三种变量和第二种本质上是一样的，都是方法中的局部变量。只不过作为参数，肯定是被初始化过的，传入的值就是初始值，所以不需要初始化。

　　问题六：instanceof是什么东东？

　　instanceof是Java的一个二元操作符，和==，>，<是同一类东东。由于它是由字母组成的，所以也是Java的保留关键字。它的作用是测试它左边的对象是否是它右边的类的实例，返回boolean类型的数据。举个例子：

String s = "I AM an Object!";
boolean isObject = s instanceof Object;

　　我们声明了一个String对象引用，指向一个String对象，然后用instancof来测试它所指向的对象是否是Object类的一个实例，显然，这是真的，所以返回true，也就是isObject的值为True。

　　instanceof有一些用处。比如我们写了一个处理账单的系统，其中有这样三个类：

public class Bill {//省略细节}
public class PhoneBill extends Bill {//省略细节}
public class GasBill extends Bill {//省略细节}

　　在处理程序里有一个方法，接受一个Bill类型的对象，计算金额。假设两种账单计算方法不同，而传入的Bill对象可能是两种中的任何一种，所以要用instanceof来判断：

public double calculate(Bill bill) {
if (bill instanceof PhoneBill) {
//计算电话账单
}
if (bill instanceof GasBill) {
//计算燃气账单
}
...
}

　　这样就可以用一个方法处理两种子类。

　　然而，这种做法通常被认为是没有好好利用面向对象中的多态性。其实上面的功能要求用方法重载完全可以实现，这是面向对象变成应有的做法，避免回到结构化编程模式。只要提供两个名字和返回值都相同，接受参数类型不同的方法就可以了：

public double calculate(PhoneBill bill) {
//计算电话账单
}

public double calculate(GasBill bill) {
//计算燃气账单
}

　　所以，使用instanceof在绝大多数情况下并不是推荐的做法，应当好好利用多态。

a:字段和方法
在对象中可以设置两种元素，一种是字段（属性）,一种是方法（函数）
class me{
int age=21;
void eat(){
}
void play(){
}
......
}
这就是一个对象，就是我，age就是我定义的属性，就是我的年龄，eat和play就是我的方法，吃和玩
属性可以是基本类型，也可以是任何类型

b:3.赋值操作符 “＝”

基本数据类型的赋值：基本数据类型存储了实际的数值，并非引用，而是实际的数据拷贝。

对象的赋值：对象的赋值操作“＝”意味着是对这个对象的引用，并非实际的数据拷贝。将一个对象传递给方法时，实际上传递的也是对象的引用。

（个人的理解：JAVA里的引用和C语言中的指针类似）

4.算术操作符

整数除法会直接去掉结果的小数位，而不是四舍五入。

5.关系操作符

关系操作符“＝＝”和“！＝”使用于基本数据类型变量和对象的引用变量。关系操作符生成的是一个boolean的结果：true或者false。

示例：

public class Equvialence {

public static void main(String[] args) {

Integer n1 = new Integer(47);

Integer n2 = new Integer(47);

System.out.println(n1 == n2);

System.out.println(n1 != n2);

// System.out.println(n1.equals(n2));

}

}

结果：

false

true

示例说明了尽管引用变量n1,n2引用的两个对象的值相同，但是“＝＝”操作符比较的是引用变量，而非是对象的值。要比较对象的值，需要使用方法equals 。equals方法这里比较的是对象的值。然而equals方法的默认行为是比较引用（说明在Integer类里，equals方法进行了overwrite）。如果在我们自己创建的类里使用equals方法，让其比较对象的值，我们也需要对其overwrite。

6.逻辑操作符（&&, ||, !）

逻辑操作符只能用于布尔值，不能将一个非布尔值当作布尔值在逻辑运算表达式中使用。

7.常量

以二进制显示输出结果：使用Integer和Long类的静态方法toBinaryString()。

8.移位操作符（>, >>>)

>>：“有符号”右移位操作符，向右移位n位，若符号为正，高位补0，若符号为负，高位补1；

>>>：“无符号”右移位操作符，向右移位n位，高位补0；

如果对char，byte，short类型的数值进行移位处理，在移位之前，它们会被转换为int类型，并且得到的结果也是一个int类型的值。

9.按位操作符（&, |, ^, ~）

10.类型转换操作符（cast）

Java允许把任何基本数据类型转换为别的基本数据类型，但布尔类型除外；布尔类型不允许进行任何的类型转换处理；

“类”数据类型不允许进行类型转换。

11.截取和舍入

如果想要四舍五入，则需要使用java.Lang.Math中的round方法。

12.提升

如果对基本数据类型执行算术运算或者按位运算，只要类型比int类型小（char,short,byte)，那么在运算之前，这些值会自动转换成int。

如果想把结果赋值给较小的类型，就必须使用类型转换，但有可能出现数据丢失。

通常，表达式中出现的最大的数据类型决定了表达式最终结果的数据类型。
第4章控制执行流程

1.foreach语法：for(datatype x: f)

foreach语法用于数组；

任何一个返回一个数组的方法都可以使用foreach；

foreach还可以用于任何Iterable对象；

示例：

public class ForEachString {

public static void main(String[] args) 


{

for(char c: "I am a newbiew of JAVA".toCharArray())

System.out.print(c + " ");

}

}

结果：

I a m a n e w b i e w o f J A V A 

2.标签

goto仍然是JAVA中的一个保留字，但在语言中并未使用它；JAVA中没有goto。

JAVA有类似goto的机制：标签

label1:

outer-iteration {

inner-iteration{

//...

break; //(1)

//...

continue; //(2)

//...

continue label1; //(3)

//...

break label1; //(4)

}

}

在（1）中，break中断内部迭代，回到外部迭代；

在（2）中，continue使执行点回到内部迭代的起始处；

在（3）中，continue label1同时中断内部迭代以及外部迭代，直接转到label1处，随后，从外部迭代开始继续迭代过程；

在（4）中，break label1会中断所有迭代，回到label1处，但并不重新进入迭代；

示例

import static net.mindview.util.Print.*;

public class LabelFor {

public static void main(String[] args) {

int i = 0;

outer:

for (; true ;) {

inner:

for (; i 

print ("i = " + i);

if (i == 2) {

print("continue");

continue;

}

if (i == 3) {

print("break");

i++;

break;

}

if (i == 7) {

print("continue outer");

i++;

continue outer;

}

if (i == 8) {

print("break outer");

break outer;

}

for (int k = 0; k 

if (k == 3) {

print("continue inner");

continue inner;

}

}

}

}

print("Byebye, finished");

}

}

结果：

i = 0

continue inner

i = 1

continue inner

i = 2

continue

i = 3

break

i = 4

continue inner

i = 5

continue inner

i = 6

continue inner

i = 7

continue outer

i = 8

break outer

Byebye, finished

同样的规则适用于while：

一般的continue会退回最内层循环的开头，并继续执行；

带标签的continue会达到标签的位置，并重新进入紧跟在标签后面的循环；

一般的break会中断并跳出当前循环；

带标签的break会中断并跳出标签所指的循环。

要记住的重点：在JAVA里需要使用标签的唯一理由是因为有循环嵌套存在，而且想存多层嵌套中break或者continue。


本篇文章来源于 Linux公社网站(www.linuxidc.com)  原文链接：http://www.linuxidc.com/Linux/2008-12/17553p4.htm
