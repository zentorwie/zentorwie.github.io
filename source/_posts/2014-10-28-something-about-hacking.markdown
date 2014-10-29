---
layout: post
title: "一些Hacking Note"
date: 2014-10-28 23:38:31 +0800
comments: true
categories: 
---

从GitHub上面恢复自己的博客源码到本地
====
本博客用的是Octopress框架，该网站的源码托管在我的GitHub页面上，因为之前重装系统的频率有点高，放在GitHub上面的好处就在这了：我可以随时恢复博客到本地，然后快速的配置到在上一个写博客的系统/发行版时的环境。

步骤：

- 安装git
- 安装rvm和ruby，参照：https://ruby-china.org/wiki/install_ruby_guide
- `git clone git@github.com:user_name/user_name.github.io.git`
- `cd user_name.github.io`
- `git checkout source`
- `gem install bundler`
- `bundle install`
- `rake install`


从源码编译安装Emacs
====
```
去镜像站下载Emacs源码
tar -xf emacs-xxx.tar.xx
cd emacs-xxx.tar.xx
./configure
make bootstrap
make
sudo make install
```
如果遇到缺少依赖就：

`sudo apt-get build-dep emacs24`

参考：http://ergoemacs.org/emacs/building_emacs_on_linux.html

