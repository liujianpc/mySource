title: github上搭建hexo博客
date: 2015-09-06 22:17:22
tags: C语言

### **搭建博客的教程**
>看了博客[如何搭建一个独立博客——简明Github Pages与Hexo教程](http://www.jianshu.com/p/05289a4bc8b2)
，然后开始一步步啊。Git的安装（绿色版）。Node.js的安装（**出问题啊，你大爷的！提示是安装提前终止**）
输入npm时，提示“npm不是内部命令”。npm是node.js带的命令。所以应该是node.js安装失败。
百度谷歌（*真是个你大爷的，屏蔽了谷歌*），得到解决方法[node.js setup wizard ended prematurely Win7安装nodejs失败解决方法](http://www.ccydesign.com/nodejs-setup/).
然而，配置完了path之后，输入npm，依旧提示不是内部命令。输入path命令，显示的环境变量中没有nodejs这个值。（**所以，这是windows的锅，没有及时更新修改的环境变量啊，Linux就不会有这种问题的吧**）
![安装真慢啊](http://i3.tietuku.com/1a67740c8fe3e1d3.png)

---

结果折腾了5个小时还是提示command not found，，，这种问题一般是环境变量问题，然而。对于npm不是啊。需要在git bash里面输入命令
```bash
curl -L https://www.npmjs.org/install.sh | sh```
修复npm

---
**npm官网良心提示**

>If your npm is broken
>
Reinstall npm:

>curl -L https://www.npmjs.org/install.sh | sh
If you're on Windows and you have a broken installation, the easiest thing to do is to reinstall node from the official installer (remember this note).

>Try clearing the npm cache

>Sometimes npm's cache gets confused. You can reset it using:

>npm cache clean



我真是人品太差了，下了个绿色的git，结果尼玛的，好不容易搞定了npm：command not found问题，然后后面又出现不能deloy问题，根本不能提交代码。。。艹，结果一查，是git版本问题，而我很幸运地就用了那么有bug的版本。。。o(︶︿︶)o 唉

---
PS：
>还需注意 
1.安装deployer
```bash
npm install hexo-deployer-git --save ```
2.将deploy 的 type由github改为git

>3.\_congfig.yaml修改主题，最后添加branch: master和代码仓库地址，否则deploy不了